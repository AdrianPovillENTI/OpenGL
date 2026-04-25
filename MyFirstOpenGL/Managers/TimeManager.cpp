#include "TimeManager.h"

TimeManager::TimeManager ( )
{
    deltaTime = 0.0f;
    time = 0.0f;
    speed = 1.0f;
    paused = false;
    lastFrameTime = 0.0f;
}

TimeManager & TimeManager::Instance ( )
{
    static TimeManager instance;
    return instance;
}

//Se metera en el parametro "glfwGetTime()" para actualizar cada frame
void TimeManager::Update ( float currentTime )
{
    deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    if ( !paused )
    {
        time += deltaTime * speed;
    }
}

float TimeManager::GetDeltaTime ( ) { return deltaTime; }
float TimeManager::GetTime ( ) { return time; }
float TimeManager::GetSpeed ( ) { return speed; }
bool TimeManager::IsPaused ( ) { return paused; }

void TimeManager::TogglePause ( )
{
    paused = !paused;
}

void TimeManager::IncreaseSpeed ( )
{
    speed *= 1.1f;
}

void TimeManager::DecreaseSpeed ( )
{
    speed *= 0.9f;
}