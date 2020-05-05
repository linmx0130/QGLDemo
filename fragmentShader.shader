#version 330
in vec4 cols;
in vec2 uv;
out vec4 fragColor;
uniform sampler2D imgTexture;
void main() {
  fragColor = texture(imgTexture, uv);
}
