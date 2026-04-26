#version 330 core

out vec4 FragColor;

uniform float time;
uniform int isPyramid;
uniform vec3 pyramidColor;

void main()
{
    // PIRÁMIDE ? usa color dinámico
    if (isPyramid == 1)
    {
        FragColor = vec4(pyramidColor, 1.0);
    }
    else
    {
        // CUBO / ORTO ? color por altura en pantalla
        if (gl_FragCoord.y > 300.0)
            FragColor = vec4(1.0, 1.0, 0.0, 1.0); // amarillo
        else
            FragColor = vec4(1.0, 0.5, 0.0, 1.0); // naranja
    }
}