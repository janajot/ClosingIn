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

void Event::RegisterEvent(EventType eventType, const std::function<void(Listener&)>& funcPtr)
{
    listeners[(int)eventType].insert(Listener{eventType, funcPtr});
}

void Event::UnregisterEvent(EventType eventType, const std::function<void(Listener&)>& funcPtr)
{
    listeners[(int)eventType].erase(Listener{eventType, funcPtr});
}

void Event::FireEvent(EventType eventType, const EventContext& metaData)
{
    for(Listener listener : listeners[(int)eventType])
    {
        listener.metaData = metaData;
        listener.listener(listener);
    }
}

void Event::FireEvent(EventType eventType)
{
    for(Listener listener : listeners[(int)eventType])
    {
        listener.listener(listener);
    }
}
