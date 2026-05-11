#include "TimeManager.h"

TimeManager::TimeManager ( )
{
    deltaTime = 0.0f;
    time = 0.0f;
    timeScale = 1.0f;
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
    float rawDelta = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    if ( rawDelta > 0.1f )
        rawDelta = 0.1f;

    if ( paused )
    {
        deltaTime = 0.0f;
        return;
    }
    deltaTime = rawDelta * timeScale;
    time += deltaTime;
}

float TimeManager::GetDeltaTime ( ) { return deltaTime; }
float TimeManager::GetTime ( ) { return time; }
float TimeManager::GetSpeed ( ) { return timeScale; }
bool TimeManager::IsPaused ( ) { return paused; }

void TimeManager::TogglePause ( )
{
    paused = !paused;
    if (paused) 
    {
        savedTimeScale = timeScale;
        timeScale = 0;
    }
    else timeScale = savedTimeScale;
}

void TimeManager::IncreaseSpeed ( )
{
    timeScale *= 1.1f;
}

void TimeManager::DecreaseSpeed ( )
{
    timeScale *= 0.9f;
}