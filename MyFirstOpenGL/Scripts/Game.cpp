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

    // La cámara mirará al centro de la escena al comenzar.
    camera.SetTarget ( sceneCenter );

    controller = new GameController ( );

    // Suelo con cubo
    //Textures trollTexture ( "Assets/Textures/troll.png" );
    //Textures rockTexture ( "Assets/Textures/rock.png" );

    Textures flowerTexture ("Assets/Textures/Flower.png");
    Textures flagTexture ("Assets/Textures/Flag.png");
    Textures mushroomTexture ("Assets/Textures/Mushroom.png");
    Textures sunTexture ("Assets/Textures/sun.png");
    Textures moonTexture ("Assets/Textures/moon.png");

    ModelObject* sun = new ModelObject("Assets/Obj/sun.obj", sunTexture, glm::vec3(0.f, 10.f, 4.f));
    ModelObject* moon = new ModelObject("Assets/Obj/moon.obj", moonTexture, glm::vec3(0.f, -10.f, 4.f));

    cycleManager.SetSun(sun);
    cycleManager.SetMoon(moon);

    gameObjects.push_back(sun);
    gameObjects.push_back(moon);

    dayNightGradient = Textures("Assets/Textures/dayNight.png");

    std::vector<ModelObject*> randomSpawnedObjs = spawner.SpawnObjects(
        "Assets/Obj/Flower.obj",
        flowerTexture,
        "Assets/Obj/Flag.obj",
        flagTexture,
        "Assets/Obj/Mushroom.obj",
        mushroomTexture
    );

    Cube * ground = new Cube ( glm::vec3 ( 0.0f ,0.4f , 0.0f ) );
    ground->GetTransform().scale = glm::vec3 ( 25.0f , 0.4f , 25.0f );
    gameObjects.push_back ( ground );

    for (int i = 0; i < randomSpawnedObjs.size(); i++)
    {
        gameObjects.push_back(randomSpawnedObjs[i]);
    }

    //ModelObject * trollLeft = new ModelObject (
    //    "Assets/troll.obj" ,
    //    trollTexture ,
    //    glm::vec3 ( -2.5f , 0.0f , 0.0f ) ,
    //    glm::vec3 ( 1.0f ) ,
    //    glm::vec3 ( 0.0f ) ,
    //    glm::vec3 ( 0.8f , 1.0f , 0.8f )
    //);

    //ModelObject * trollCenter = new ModelObject (
    //    "Assets/troll.obj" ,
    //    trollTexture ,
    //    glm::vec3 ( 0.0f , 0.0f , 0.0f ) ,
    //    glm::vec3 ( 1.0f ) ,
    //    glm::vec3 ( 0.0f ) ,
    //    glm::vec3 ( 1.0f , 1.0f , 1.0f )
    //);

    //ModelObject * trollRight = new ModelObject (
    //    "Assets/troll.obj" ,
    //    trollTexture ,
    //    glm::vec3 ( 2.5f , 0.0f , 0.0f ) ,
    //    glm::vec3 ( 1.0f ) ,
    //    glm::vec3 ( 0.0f ) ,
    //    glm::vec3 ( 0.3f , 0.2f , 1.0f )
    //);

    //ModelObject * rock = new ModelObject (
    //    "Assets/rock.obj" ,
    //    rockTexture ,
    //    glm::vec3 ( 3.5f , 0.0f , 2.5f ) ,
    //    glm::vec3 ( 1.0f ) ,
    //    glm::vec3 ( 0.0f ) ,
    //    glm::vec3 ( 1.0f , 1.0f , 1.0f )
    //);

    //ModelObject * cloud = new ModelObject (
    //    "Assets/rock.obj" ,
    //    rockTexture ,
    //    glm::vec3 ( 0.0f , 3.0f , -2.0f ) ,
    //    glm::vec3 ( 2.5f , 0.8f , 1.5f ) ,
    //    glm::vec3 ( 0.0f ) ,
    //    glm::vec3 ( 1.2f , 1.2f , 1.2f )
    //);

    //gameObjects.push_back ( trollLeft );
    //gameObjects.push_back ( trollCenter );
    //gameObjects.push_back ( trollRight );
    //gameObjects.push_back ( rock );
    //gameObjects.push_back ( cloud );
    
    // Inicializar input
    InputManager::Instance ( ).Init ( GLManager::Instance ( ).GetWindow ( ) );
}
void Game::Update ( float dt )
{
    glfwPollEvents ( );

    InputManager::Instance ( ).Update ( );
    TimeManager::Instance ( ).Update ( glfwGetTime ( ) );

    // El centro de la órbita será el centro de la escena
    camera.SetOrbitCenter ( sceneCenter );

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
    glUniform1i(glGetUniformLocation(shaderPrograms[0].GetID(), "dayNightTexture"), 0);

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