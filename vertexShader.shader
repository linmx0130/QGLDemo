#version 330
layout(location = 0) in vec3 posVertex;
layout(location = 1) in vec3 colVertex;
uniform mat4 MVP;
out vec4 cols;
void main() {
  gl_Position = MVP * vec4(posVertex, 1.0f);
  cols = vec4(colVertex, 1.0f);
}
