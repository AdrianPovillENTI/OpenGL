#version 330 core

// Coordenadas UV que vienen del vertex shader.
// Sirven para saber qué punto de la textura corresponde a este fragmento.
in vec2 TexCoord;
in vec3 FragNormal;

// Color final que saldrá a pantalla
out vec4 FragColor;

// Textura principal del modelo.
uniform sampler2D mainTexture;
uniform sampler2D dayNightTexture;

uniform float dayTime;

uniform vec3 directionalLightDirection;
uniform float sunLightIntensity;

void main()
{
    // Leemos el color de la textura en las coordenadas UV actuales
    vec4 texColor = texture(mainTexture, TexCoord);
    vec3 ambientColor = texture(dayNightTexture, vec2(dayTime, 0.5)).rgb;

    vec3 normal = normalize(FragNormal);
    
    float diffuseAmount = max(dot(normal, -directionalLightDirection), 0.0);

    vec3 ambient = texColor.rgb * ambientColor;

    vec3 diffuse = texColor.rgb * diffuseAmount * sunLightIntensity;

    vec3 finalColor = ambient + diffuse;

    FragColor = vec4(finalColor, 1.0);
}