#version 460 core
layout (location = 0) in vec2 aPos;

uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * vec4(aPos, 0.0, 1.0);
}
