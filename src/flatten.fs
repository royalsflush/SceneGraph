uniform sampler2D tex;
varying vec3 normal;
varying vec3 pos;

void main()
{
	vec3 nNormal = normalize(normal);
	vec3 eyeVert = normalize(-pos);
	
	vec4 difColor = gl_FrontMaterial.diffuse;
	vec4 specColor = gl_FrontMaterial.specular;
	float shi = gl_FrontMaterial.shininess;
	gl_FragColor = gl_FrontMaterial.emission + gl_LightModel.ambient*gl_FrontMaterial.ambient;
	vec4 srcColor;

	for (int i=0; i<2; i++) {
		vec3 lightPos = gl_LightSource[i].position.xyz;
		vec3 lightVert = normalize(lightPos - pos);
		vec3 halfVec = normalize(gl_LightSource[i].halfVector.xyz);

		float dist = length(lightPos-pos);
		float att = 1.0/(gl_LightSource[i].constantAttenuation +
						gl_LightSource[i].linearAttenuation*dist +
						gl_LightSource[i].quadraticAttenuation*dist*dist);
						
		srcColor = gl_LightSource[i].ambient*gl_FrontMaterial.ambient;
		srcColor += difColor*max(dot(nNormal,lightVert), 0.0); 
		srcColor += specColor*gl_LightSource[i].specular*pow(max(dot(nNormal,halfVec), 0.0), shi);

		srcColor*=att;

		if (gl_LightSource[i].position.w==1.0) {
			vec3 spotDir = normalize(gl_LightSource[i].spotDirection);
			float spotFactor = dot(normalize(-lightPos), spotDir);

			if (spotFactor > gl_LightSource[i].spotCosCutoff) {
				srcColor*=pow(max(spotFactor, 0.0), gl_LightSource[i].spotExponent);
			}
		}
		
		gl_FragColor += srcColor;
	}
}
