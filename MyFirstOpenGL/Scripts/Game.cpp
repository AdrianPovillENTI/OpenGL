#include "Game.h"
#include "../Managers/InputManager.h"
#include "../Managers/TimeManager.h"
#include "../Managers/GLManager.h"
#include "../Scripts/ModelObject.h"
#include "../GeometryModels/Cube.h"
#include <iostream>

Game::Game ( ) { }

Game::~Game ( )
{
    for ( auto obj : gameObjects )
        delete obj;

    delete controller;
}

void Game::Start ( )
{
    glPolygonMode ( GL_FRONT_AND_BACK , GL_FILL );

    // Crear shader principal
    shaderPrograms.push_back ( ShaderProgram ( ) );


    // Usa el tamaño real de la ventana.
    camera.SetAspectRatio ( WIDTH / HEIGHT );

    controller = new GameController ( );

    // Suelo con cubo

    Textures flowerTexture ("Assets/Textures/Flower.png");
    Textures flagTexture ("Assets/Textures/Flag.png");
    Textures mushroomTexture ("Assets/Textures/Mushroom.png");
    Textures sunTexture ("Assets/Textures/sun.png");
    Textures moonTexture ("Assets/Textures/moon.png");
    Textures terrainTexture ("Assets/Textures/Terrain.png");

    ModelObject* terrain = new ModelObject("Assets/Terrain.obj", terrainTexture, glm::vec3(0.f, -0.5f, 0.f));

    gameObjects.push_back(terrain);

    ModelObject* sun = new ModelObject("Assets/sun.obj", sunTexture, glm::vec3(0.f, -50.f, 4.f), glm::vec3(2.f), glm::vec3(0.f, 0.f, 45.f));
    ModelObject* moon = new ModelObject("Assets/moon.obj", moonTexture, glm::vec3(0.f, 50.f, 4.f), glm::vec3(1.5f), glm::vec3(0.f, 180.f, -45.f));

    cycleManager.SetSun(sun);
    cycleManager.SetMoon(moon);

    gameObjects.push_back(sun);
    gameObjects.push_back(moon);

    dayNightGradient = Textures("Assets/Textures/dayNight.png");

    std::vector<ModelObject*> randomSpawnedObjs = spawner.SpawnObjects(
        "Assets/Flower.obj",
        flowerTexture,
        "Assets/Flag.obj",
        flagTexture,
        "Assets/Mushroom.obj",
        mushroomTexture
    );

    for (int i = 0; i < randomSpawnedObjs.size(); i++)
    {
        gameObjects.push_back(randomSpawnedObjs[i]);
    }
    
    // Inicializar input
    InputManager::Instance ( ).Init ( GLManager::Instance ( ).GetWindow ( ) );
}
void Game::Update ( float dt )
{
    glfwPollEvents ( );

    InputManager::Instance ( ).Update ( );
    TimeManager::Instance ( ).Update ( glfwGetTime ( ) );

    // El centro de la órbita será el centro de la escena
    for ( int i = 0; i < gameObjects.size ( ); i++ )
    {
        gameObjects [ i ]->Update ( dt );
    }

    cycleManager.Update(dt);

    // Ahora el controller también controla la cámara
    controller->ManageInputs ( gameObjects , camera , dt );
}
void Game::Render ( )
{
    glm::vec3 skyColor = cycleManager.GetSkyColor();
    glClearColor(skyColor.x, skyColor.y, skyColor.z, 1.0);
    // Limpiar pantalla y depth buffer
    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Activar shader
    shaderPrograms [ 0 ].Use ( );
    
    // Matriz de vista: cámara
    glm::mat4 view = camera.GetViewMatrix ( );

    // Matriz de proyección: perspectiva
    glm::mat4 projection = camera.GetProjectionMatrix ( );

    // Buscar la variable uniform "view" en el shader
    GLint viewLoc = glGetUniformLocation ( shaderPrograms [ 0 ].GetID ( ) , "view" );
    glUniformMatrix4fv ( viewLoc , 1 , GL_FALSE , glm::value_ptr ( view ) );

    // Buscar la varible uniform "projection" en el shader
    GLint projectionLoc = glGetUniformLocation ( shaderPrograms [ 0 ].GetID ( ) , "projection" );
    glUniformMatrix4fv ( projectionLoc , 1 , GL_FALSE , glm::value_ptr ( projection ) );

    glUniform3fv(glGetUniformLocation(shaderPrograms[0].GetID(), "directionalLightDirection"), 1, glm::value_ptr(cycleManager.GetSunlighDirection()));
    glUniform1f(glGetUniformLocation(shaderPrograms[0].GetID(), "sunLightIntensity"), cycleManager.GetLightIntensity());
    glUniform1f(glGetUniformLocation(shaderPrograms[0].GetID(), "dayTime"), cycleManager.GetDayTime());

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, dayNightGradient.GetID());
    glUniform1i(glGetUniformLocation(shaderPrograms[0].GetID(), "dayNightTexture"), 1);

    // Dibujar objetos
    for ( int i = 0; i < gameObjects.size ( ); i++ )
    {
        GameObject * obj = gameObjects [ i ];


        if ( obj == nullptr )
        {
            std::cout << "Objeto " << i << " es nullptr" << std::endl;
            continue;
        }

        if ( !obj->IsActive ( ) )
        {
            std::cout << "Objeto " << i << " no está activo" << std::endl;
            continue;
        }

        obj->Draw ( shaderPrograms [ 0 ].GetID ( ) );
    }
}