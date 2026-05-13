#version 330 core

layout (location = 0) in vec3 aPos;

uniform vec4 view;

void main()
{
    gl_Position = model * vec4(aPos, 1.0);
}