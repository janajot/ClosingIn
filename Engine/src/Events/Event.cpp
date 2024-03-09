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

void Event::PushEvent(EventType eventType, const EventContext& metaData)
{
    for(Listener& listener : listeners[(int)eventType])
    {
        std::lock_guard<std::mutex> lock(mut);
        listener.metaData = metaData;
        senders.push_back(listener);
    }
}

void Event::PushEvent(EventType eventType)
{
    for(Listener& listener : listeners[(int)eventType])
    {
        std::lock_guard<std::mutex> lock(mut);
        senders.push_back(listener);
    }
}

void Event::FireEvent(bool* run)
{
    std::vector<Listener> senderStack;

    while(*run)
    {
        {
            std::lock_guard<std::mutex> lock(mut);
            senderStack = senders;
            senders.clear();
        }

        for(Listener& listener : senderStack)
        {
            listener.listener(listener);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
