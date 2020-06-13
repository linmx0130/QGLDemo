#version 330
in vec4 realPos;
in vec4 norms;
in vec2 uv;
uniform vec3 lightPos;
//uniform vec3 cameraPos;
out vec4 fragColor;
uniform sampler2D imgTexture;
void main() {
  vec3 pos = realPos.xyz / realPos.w;
  vec3 lightSourceDir = normalize(pos - lightPos);
  vec3 norm3D = normalize(norms.xyz / norms.w);
  // diffuse
  float diffuse = max(dot(lightSourceDir, norm3D), 0);
  float lightDeg = diffuse * 0.9 +0.1;
  //vec3 reflection = 2 * diffuse * norm3D - lightSourceDir;
  // vec4 specular = pow(max(dot(reflection, cameraPos - pos),0), 3) * vec4(1.0, 1.0, 1.0, 1.0) * 0.1;
  fragColor = texture(imgTexture, uv) * lightDeg; // + specular;
}
