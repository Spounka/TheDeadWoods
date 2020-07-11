#version 330 core

layout (location = 0) in vec3 gPos;
layout (location = 1) in vec2 gCoords;
layout (location = 2) in vec3 gNormals;

out vec3 VertPos;
out vec2 TextCoords;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(gPos.x, gPos.y, gPos.z, 1);
    VertPos = vec3(model * vec4(gPos, 1.0f));
    TextCoords = gCoords;
    Normal = mat3(transpose(inverse(model))) * gNormals;
}
