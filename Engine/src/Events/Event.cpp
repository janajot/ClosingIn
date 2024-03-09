//
// Created by Let'sBlend on 25/02/2024.
//

#include "Event.h"
#include "EngineTime.h"

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
    listeners[(int)eventType].push_back(Listener{eventType, funcPtr});
}

void Event::UnregisterEvent(EventType eventType, const std::function<void(Listener&)>& funcPtr)
{
    std::vector<Listener>* data = &listeners[(int)eventType];
    auto it = std::find(data->begin(), data->end(), Listener{eventType, funcPtr});
    if(it == data->end())
        data->pop_back();

    std::swap(*it, data->back());
    data->pop_back();
}

void Event::FireEvent(const EventType& eventType)
{
    for (Listener &listener: listeners[(int) eventType])
    {
        listener.listener(listener);
    }
}

void Event::FireEvent(const EventType& eventType, const EventContext& e)
{
    for(Listener& listener : listeners[(int)eventType])
    {
        listener.metaData = e;
        listener.listener(listener);
    }
}
