#include "EngineTime.h"

// This code is from Blat Blatnik, thank you Blat VERY COOL
// Check him out over here: https://blog.bearcats.nl/perfect-sleep-function/
void EngineTime::Sleep(double seconds)
{
    auto t = std::chrono::high_resolution_clock::now();
    auto target = t + std::chrono::nanoseconds(int64_t(seconds * 1e9));

    static HANDLE timer;
    if (!timer)
        timer = CreateWaitableTimerExW(NULL, NULL,
                                       CREATE_WAITABLE_TIMER_HIGH_RESOLUTION,
                                       TIMER_ALL_ACCESS);

    int64_t maxTicks = PERIOD * 9'500;
    for (;;) {
        int64_t remaining = (target - t).count();
        int64_t ticks = (remaining - TOLERANCE) / 100;
        if (ticks <= 0)
            break;
        if (ticks > maxTicks)
            ticks = maxTicks;

        LARGE_INTEGER due;
        due.QuadPart = -ticks;
        SetWaitableTimerEx(timer, &due, 0, NULL, NULL, NULL, 0);
        WaitForSingleObject(timer, INFINITE);
        t = std::chrono::high_resolution_clock::now();
    }

    // spin
    while (std::chrono::high_resolution_clock::now() < target)
        YieldProcessor();
}

void EngineTime::UpdateStartTime()
{
    startTime = std::chrono::system_clock::now();
}

void EngineTime::UpdateEndTime(const int& fps)
{
    // calculate time it took for engine to excecute
    endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;

    // Throttle the gameEngine if the engine has more fps than the target FrameRate
    double targetFrameRate = 1.0 / (double)fps; // TODO: Add Framerate
    if (elapsedTime.count() < targetFrameRate)
        Sleep(targetFrameRate - elapsedTime.count());

    // Calculate deltaTime and other
    endTime = std::chrono::system_clock::now();
    elapsedTime = endTime - startTime;
    deltaTime = elapsedTime.count();
    milliSeconds = elapsedTime.count() * 1000;
}