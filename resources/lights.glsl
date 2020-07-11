#ifndef LIGHTS_GLSL
#define LIGHTS_GLSL

#include <material.glsl>

struct DirectionLight
{
    vec3 Direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct AreaLight
{
    vec3 position;

    float cLinear, cQuadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct FlashLight
{
    vec3 position;
    vec3 direction;
    float innerRing, outerRing;

    float cLinear, cQuadratic;

    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
};

uniform DirectionLight Light;
uniform AreaLight Lamp;
uniform FlashLight Torch;

vec3 calculateDirectionalLight(DirectionLight sun, Material mat, vec3 vertPos, vec3 normal, vec3 viewPosition);
vec3 calculateAreaLight(AreaLight lamp, Material mat, vec3 vertPos);
vec3 calculateFlashLight(FlashLight light, Material mat, vec3 vertPos, vec3 normal, vec3 viewPosition);


vec3 calculateDirectionalLight(DirectionLight sun, in Material mat, vec3 vertPos, vec3 normal, vec3 viewPosition)
{
    vec3 lightDir = normalize(-sun.Direction);
    vec3 norm = normalize(normal);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * sun.diffuse;

    vec3 viewDir = normalize(viewPosition - vertPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0), 32);
    vec3 specular = mat.specularIntensity * sun.diffuse * spec;

    return (diffuse + sun.ambient + specular) * mat.Color;
}

vec3 calculateAreaLight(AreaLight lamp, Material mat, vec3 vertPos)
{
    float distance = length(lamp.position - vertPos);
    float attenuation = 1.0 / (1.0 + lamp.cLinear * distance + lamp.cQuadratic * (distance * distance));

    vec3 result = (lamp.ambient * attenuation + lamp.diffuse * attenuation + lamp.specular);

    return result;
}

vec3 calculateFlashLight(FlashLight light, Material mat, vec3 vertPos, vec3 normal, vec3 viewPosition)
{
    vec3 lightDir = normalize(light.position - vertPos);
    float diff = max(dot(normal, lightDir), 0.0f);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 viewDir = normalize(viewPosition - vertPos);

    float spec = pow(max(dot(reflectDir, viewDir), 0.0), 32);

    float distance = length(light.position - vertPos);
    float attenuation = 1.0 / (1.0 + light.cLinear * distance + light.cQuadratic * (distance * distance));

    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.innerRing - light.outerRing;
    float intensity = clamp((theta - light.outerRing) / epsilon, 0.0f, 1.0f);

    vec3 result = (light.diffuse * attenuation + light.ambient * attenuation+ light.specular* attenuation) * intensity;
    return result;
}

#endif
