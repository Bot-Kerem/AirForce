#version 460 core

uniform mat4 view;
uniform mat4 proj;
uniform mat4 rotate;

uniform int size;


void main()
{
    vec2 position = vec2((gl_VertexID/2), (gl_VertexID % 2) * size);
    gl_Position = proj * view * rotate * vec4(position.x - (size / 2), 0.0, position.y - (size / 2), 1.0);
    //gl_Position =  proj * view * vec4(points[gl_VertexID], -2.0, 1.0);
}