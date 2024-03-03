//
// Created by Let'sBlend on 25/02/2024.
//

#include "Event.h"

void Event::StartUp()
{
    std::cout << "Initialized event sub system" << std::endl;
}

void Event::ShutDown()
{
    for(auto & listener : listeners)
        listener.clear();
    std::cout << "Shut downed event sub system" << std::endl;
}

void Event::RegisterEvent(EventType eventType, void (*listener)(Listener& listening))
{
    listeners[(int)eventType].insert(Listener{eventType, listener});
}

void Event::UnregisterEvent(EventType eventType, void (*listener)(Listener& listening))
{
    listeners[(int)eventType].erase(Listener{eventType, listener});
}

void Event::FireEvent(EventType eventType, void (*sender)())
{
    for(Listener listener : listeners[(int)eventType])
    {
        listener.sender = sender;
        listener.listener(listener);
    }
}

