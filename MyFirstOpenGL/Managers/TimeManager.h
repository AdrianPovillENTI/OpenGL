#pragma once

class TimeManager
{
private:
    float deltaTime;
    float time;
    float timeScale;
    float savedTimeScale;
    bool paused;

    float lastFrameTime;

    TimeManager ( );

public:
    static TimeManager & Instance ( );

    void Update ( float currentTime );

    float GetDeltaTime ( );
    float GetTime ( );
    float GetSpeed ( );
    bool IsPaused ( );

    void TogglePause ( );
    void IncreaseSpeed ( );
    void DecreaseSpeed ( );
};