#version 330 core
//ESTE CODIGO SE HA HECHO CON LA AYUDA DE CHATGPT
// Posición del vértice.
// Debe coincidir con el atributo 0 para cuando hacemos: glVertexAttribPointer(attrib ...)
layout (location = 0) in vec3 aPos;

// Coordenadas UV de textura.
// Debe coincidir con el atributo 1 para cuando hacemos: glVertexAttribPointer(attrib ...)
layout (location = 1) in vec2 aTexCoord;

// Matriz del objeto.
// Mueve, rota y escala cada objeto en el mundo.
uniform mat4 model;

// Matriz de vista.
// Representa la cámara: desde dónde mira y hacia dónde.
uniform mat4 view;

// Matriz de proyección.
// Representa la perspectiva: FOV, aspect ratio.
uniform mat4 projection;

// Enviamos las UV al fragment shader para usar texturas después.
out vec2 TexCoord;

void main()
{
    /*
    Aplicamos la transformación completa:
        1. model => coloca el objeto en el mundo
        2. view => aplica la cámara
        3. projection => aplica la perspectiva
    */ 
    gl_Position = projection * view * model * vec4(aPos, 1.0);

    // Pasamos las coordenadas UV al fragment shader
    TexCoord = aTexCoord;
}