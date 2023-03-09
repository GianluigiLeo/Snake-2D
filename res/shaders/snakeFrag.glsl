#version 450 core
out vec4 Color;

uniform vec3 customColor;


void main() {
    Color = vec4(customColor, 1.0);
}