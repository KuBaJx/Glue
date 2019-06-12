#version 450 core
out vec4 color;

uniform vec4 u_Color;

uniform float u_Time;

void main()
{
	color = vec4(abs(cos(u_Time)), abs(sin(u_Time)), 0.0, 1.0);
}