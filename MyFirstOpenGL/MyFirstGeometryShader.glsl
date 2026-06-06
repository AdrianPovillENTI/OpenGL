#version 440 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 GeometryNormals[];
in vec2 GeometryTexCoord[];

out vec3 FragNormals;
out vec2 FragTexCoord;

void main(){

	for(int i = 0; i < gl_in.length(); i++){
		gl_Position = gl_in[i].gl_Position;

		FragNormals = GeometryNormals[i];
		FragTexCoord = GeometryTexCoord[i];

		EmitVertex();
	}

	EndPrimitive();
}