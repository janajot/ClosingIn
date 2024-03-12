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


void Event::PushEvent(const EventType& eventType)
{
    senders[(int)eventType] = Sender{eventType};
    for (Listener &listener: listeners[(int) eventType])
    {
        listener.eventType = eventType;
        listener.listener(listener);
        //senders.push_back(Sender);
    }
}

void Event::PushEvent(const EventType& eventType, const EventContext& e)
{
    senders[(int)eventType] = Sender{eventType, e};
    for(Listener& listener : listeners[(int)eventType])
    {
        listener.eventType = eventType;
        listener.metaData = e;
        // senders.push_back(listener);
    }
}

void Event::FireEvents()
{
    for(const Sender& sender : senders)
    {
        if(sender.eventType == EventType::None)
            continue;

        for(Listener& send : listeners[(int)sender.eventType])
        {
            send.eventType = senders[(int)sender.eventType].eventType;
            send.metaData = senders[(int)sender.eventType].metaData;
            send.listener(send);
        }
    }

    senders.fill(Sender{EventType::None, EventContext{}});
}