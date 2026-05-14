#version 330 core

// Coordenadas UV que vienen del vertex shader.
// Sirven para saber qué punto de la textura corresponde a este fragmento.
in vec2 TexCoord;

// Color final que saldrá a pantalla
out vec4 FragColor;

// Textura principal del modelo.
// Aquí conectaremos troll.png o rock.png desde C++.
uniform sampler2D mainTexture;

// Color multiplicador para pintar el modelo.
uniform vec3 tintColor;

void main()
{
    // Leemos el color de la textura en las coordenadas UV actuales
    vec4 texColor = texture(mainTexture, TexCoord);

    // Multiplicamos el color de la textura por el tinte.
    // Esto permite reutilizar la misma textura cambiando ligeramente el color.
    FragColor = texColor * vec4(tintColor, 1.0);
}