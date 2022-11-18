#version 460 //minimum version of OpenGL

uniform int time;
in vec3 vertexIn;
in vec3 colorIn;
out vec3 colorOut;

void main()
{
    colorOut = colorIn;
    gl_Position = vec4(vertexIn, 1.0f);
}
