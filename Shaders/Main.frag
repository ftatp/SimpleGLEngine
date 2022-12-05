#version 460 //minimum version of OpenGL

uniform bool isLit;

in vec3 colorOut;
in vec2 textureOut;

out vec4 fragColor;

uniform sampler2D textureImage;

void main()
{
    fragColor = vec4(colorOut, 1.0f) * texture(textureImage, textureOut);    
}
