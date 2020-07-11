#ifndef MATERIAL_FRAG
#define MATERIAL_FRAG

struct Material
{
    vec3 Color;
    sampler2D _diffuse;
    sampler2D _specular;
    float specularIntensity;
};

uniform Material material;

#endif