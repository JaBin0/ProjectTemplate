#version 330 core
layout(location = 0) in vec3 vPos;
layout(location = 1) in vec2 vTex;
layout(location = 2) in vec3 vNorm;

out vec3 fPos;
out vec2 fTex;
out vec3 fNorm;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
  fTex = vTex;
  gl_Position = projection * view * model * vec4(vPos, 1.0);
  fPos = vec3(model * vec4(vPos.xyz, 1.0));
  fNorm = mat3(transpose(inverse(model))) * vNorm;
}