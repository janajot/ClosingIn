#include "pch.h"
#include "Events/Event.h"

bool stop;

void Test(Listener &listener)
{
    if (listener.eventType == EventType::KeyPressed)
        std::cout << "Test" << std::endl;
    stop = false;
}

int main()
{
    // Testing Event System
    /////////////////////////////////////////////////////////////////
    stop = true;
    Event::RegisterEvent(EventType::KeyPressed, &Test);
    while (stop)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line == "Fire")
        {
            Event::FireEvent(EventType::KeyPressed, nullptr);
        }
    }
    Event::UnregisterEvent(EventType::KeyPressed, &Test);
    /////////////////////////////////////////////////////////////////
#ifndef DIST
    std::cin.get();
#endif
}