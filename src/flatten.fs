uniform sampler2D tex;
varying vec3 normal;
varying vec3 pos;

void spotCalc(int lSrcIndex, out vec4 finalColor)
{
	vec3 spotDir = normalize(gl_LightSource[lSrcIndex].spotDirection);
	vec3 lightPos = gl_LightSource[lSrcIndex].position.xyz;
	vec3 lightVert = normalize(lightPos-pos);
	float spotFactor = dot(normalize(-lightVert), spotDir);

	float dist = length(lightPos-pos);

	float att = 1.0/(gl_LightSource[lSrcIndex].constantAttenuation +
						gl_LightSource[lSrcIndex].linearAttenuation*dist +
						gl_LightSource[lSrcIndex].quadraticAttenuation*dist*dist);

	vec4 ambient =  gl_LightSource[lSrcIndex].ambient*gl_FrontMaterial.ambient;
	finalColor = ambient*att;

	if (spotFactor <= gl_LightSource[lSrcIndex].spotCosCutoff) {
		vec3 nNormal = normalize(normal);
		float shi = gl_FrontMaterial.shininess;
		vec3 halfVec = normalize(gl_LightSource[lSrcIndex].halfVector.xyz);

		vec4 diffuse = gl_FrontMaterial.diffuse*gl_LightSource[lSrcIndex].diffuse*max(dot(nNormal,lightVert), 0.0);
		vec4 specular = gl_FrontMaterial.specular*gl_LightSource[lSrcIndex].specular*pow(max(dot(nNormal, halfVec), 0.0), shi);
		float spot = pow(max(spotFactor, 0.0), gl_LightSource[lSrcIndex].spotExponent);

		finalColor*=spot;
		finalColor+=diffuse*spot*att;
		finalColor+=specular*spot*att;
	}
}

void dirCalc(int lSrcIndex, out vec4 finalColor) 
{
	vec3 nNormal = normalize(normal);
	vec3 halfVec = normalize(gl_LightSource[lSrcIndex].halfVector.xyz);
	vec3 lightPos = gl_LightSource[lSrcIndex].position.xyz;
	vec3 lightVert = normalize(lightPos-pos);
	float shi = gl_FrontMaterial.shininess;

	vec4 ambient =  gl_LightSource[lSrcIndex].ambient*gl_FrontMaterial.ambient;
	vec4 diffuse = gl_FrontMaterial.diffuse*gl_LightSource[lSrcIndex].diffuse*max(dot(nNormal,lightVert), 0.0);

	if (dot(nNormal,lightVert)> 0.0)	{
		vec4 specular = gl_FrontMaterial.specular*gl_LightSource[lSrcIndex].specular*pow(max(dot(nNormal, halfVec), 0.0), shi);
		finalColor+=specular;
	}	

	finalColor = ambient+diffuse;
}

void main()
{
	vec4 srcColor;
	gl_FragColor = gl_FrontMaterial.emission + gl_LightModel.ambient*gl_FrontMaterial.ambient;

	for (int i=0; i<2; i++) {

		if (gl_LightSource[i].position.w==1.0) 
			spotCalc(i, srcColor);
		else dirCalc(i, srcColor);
		
		gl_FragColor += srcColor;
	}
}
