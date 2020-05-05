#version 330
layout(location = 0) in vec3 posVertex;
layout(location = 1) in vec3 colVertex;
layout(location = 2) in vec2 uvVertex;
uniform mat4 MVP;
out vec4 cols;
out vec2 uv;
void main() {
  gl_Position = MVP * vec4(posVertex, 1.0f);
  cols = vec4(colVertex, 1.0f);
  uv = uvVertex;
}
