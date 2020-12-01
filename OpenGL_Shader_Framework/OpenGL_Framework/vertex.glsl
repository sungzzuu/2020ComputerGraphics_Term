#version 330 core

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vColor;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ex_Color;

void main()
{
	gl_Position = vec4(vPos, 1.0);

	ex_Color = vColor;
}