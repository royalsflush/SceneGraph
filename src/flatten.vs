varying vec3 normal;
varying vec3 pos;

void main()
{
	normal = normalize(gl_NormalMatrix*gl_Normal);
	vec4 tmp = gl_ModelViewMatrix*gl_Vertex;
	pos = tmp.xyz;

	gl_Position = ftransform();
}
