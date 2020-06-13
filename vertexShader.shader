#version 330
layout(location = 0) in vec3 posVertex;
layout(location = 1) in vec3 normVertex;
layout(location = 2) in vec2 uvVertex;
uniform mat4 vpMat;
uniform mat4 modelMat;
out vec4 realPos;
out vec4 norms;
out vec2 uv;
void main() {
  realPos = modelMat * vec4(posVertex, 1.0f);
  norms = modelMat * vec4(normVertex, 1.0f);
  gl_Position = vpMat * realPos;
  uv = uvVertex;
}
