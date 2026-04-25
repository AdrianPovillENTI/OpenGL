#version 440 core

uniform float windowHeight;
uniform int figureType; // Té dos modes, 0 per a fer els pixels de la meitat superior grocs i la resta taronja i 1 per a que canvii cada 2s
uniform float time;

out vec4 fragColor;

void main() {
    if (figureType == 0)
    {
        if (gl_FragCoord.y > windowHeight / 2.0)
            fragColor = vec4(1.0, 1.0, 0.0, 1.0);
        else
            fragColor = vec4(1.0, 0.5, 0.0, 1.0);
    }
    else
    {
        float t = mod(time, 6.0);// reinicia el temps cada 6s

        if (t < 2.0)
            fragColor = vec4(1.0, 0.0, 0.0, 1.0);
        else if (t < 4.0)
            fragColor = vec4(0.0, 1.0, 0.0, 1.0);
        else
            fragColor = vec4(0.0, 0.0, 1.0, 1.0);
    }
}
