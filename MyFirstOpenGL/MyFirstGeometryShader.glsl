#version 440 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec2 uvsGeometryShader[];
in vec3 normalsGeometryShader[];

out vec2 uvsFragmentShader;
out vec3 normalsFragmentShader;
out vec4 primitivePosition;

unirform mat4 translationMatrix;
unirform mat4 rotationMatrix;
unirform mat4 scaleMatrix;
unirform mat4 view;
unirform mat4 projection;

void main()
{
	mat4 model = translationMatrix * rotationMatrix * scaleMatrix;
	primitivePosition = model * ((gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) * 0.33);

	for(int i = 0; i < gl_in.length(); i++)
	{
		gl_Position = gl_in[i].gl_Position;
		
		uvsGeometryShader = uvsGeometryShader[i];
		normalsGeometryShader = normalsGeometryShader[i];

		EmitVertex();
	}


	EndPrimitive();
}