precision mediump float;

uniform vec4 v_Color;
uniform sampler2D u_Texture;
varying vec2 v_TexCoordinate;

#define RESOLUTION_WIDTH 375.0
#define RESOLUTION_HEIGHT 211.0
#define POWER 2.0

void main() {

    vec2 fragCoord = gl_FragCoord.xy;
    vec2 iResolution = vec2(RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
    vec2 p = fragCoord.xy / iResolution.x; // normalized coords with some cheat

    float prop = iResolution.x / iResolution.y;

    vec2 m = vec2(0.5, 0.5 / prop); // center coords
    vec2 d = p - m; // vector from center to current fragment
    float r = sqrt(dot(d, d)); // distance of pixel from center

    float power = POWER;

    float bind; // radius of 1:1 effect
    if (power > 0.0)
        bind = sqrt(dot(m, m)); // stick to corners
    else {
        if (prop < 1.0)
            bind = m.x;
        else
            bind = m.y;
    } // stick to borders

    // Weird formulas
    vec2 uv;
    if (power > 0.0) // fisheye
        uv = m + normalize(d) * tan(r * power) * bind / tan( bind * power);
    else if (power < 0.0) // antifisheye
        uv = m + normalize(d) * atan(r * -power * 10.0) * bind / atan(-power * bind * 10.0);
    else uv = p; // no effect for power = 1.0

    vec3 col = texture2D(u_Texture, vec2(uv.x, -uv.y * prop)).xyz; // Second part of cheat
    gl_FragColor = vec4(col, 1.0);
} 