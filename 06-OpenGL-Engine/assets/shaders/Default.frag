#version 330 core
in vec3 fPos;
in vec2 fTex;
in vec3 fNorm;

out vec4 FragColor;
uniform float time;
uniform vec3 color;

void main() {
    vec4 light_color = vec4(1.0, 1.0, 1.0, 1.0);
    //vec4 color = vec4(0.5, 0.5, 0.25, 1.0);
    vec3 light_position = vec3 (2.0 * sin(time), 2.0, 2.0 * cos(time));
    float ambient_strength = 0.1;

    vec3 nromals = normalize(fNorm);
    vec3 light_direction = normalize(light_position - fPos);
    float diffuse = max(dot(nromals, light_direction), 0.0);


    vec3 ambient_light = ambient_strength * light_color.rgb;
    vec3 diffuse_light = diffuse * light_color.rgb;
    vec3 light = ambient_light + diffuse_light;

    FragColor = vec4(light * color.rgb, 1.0);
}