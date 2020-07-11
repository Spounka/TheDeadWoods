#version 330 core

out vec4 FragColour;
uniform sampler2D text;
uniform vec3 viewPos;

in vec3 VertPos;
in vec2 TextCoords;
in vec3 Normal;

#include <lights.glsl>

void main()
{
    vec3 light = calculateDirectionalLight(Light, material, VertPos, Normal, viewPos);
    light += calculateAreaLight(Lamp, material, VertPos);
    light += calculateFlashLight(Torch, material, VertPos, Normal, viewPos);
    FragColour = texture(text, TextCoords) * vec4(light, 1.0f) * vec4(material.Color, 1);
}
