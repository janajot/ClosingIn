//
// Created by Let'sBlend on 25/02/2024.
//

#ifndef CLOSINGIN_EVENT_H
#define CLOSINGIN_EVENT_H

#include "EventType.h"

struct EventContext
{
    //128 bits
    union
    {
        int64_t int64[2];
        uint64_t uint64[2];
        int_fast64_t fint64[2];

        int32_t int32[4];
        uint32_t uint32[4];
        int_fast32_t fint32[4];

        int16_t int16[8];
        uint16_t uint16[8];
        int_fast16_t fint16[8];

        int8_t int8[16];
        uint8_t uint8[16];
        int_fast8_t fint8[16];

        char char4[16];

        float float32[4];
        double double32[4];
    };
};

struct Listener
{
    // The type of event listened to
    EventType eventType;
    // Pointer to the listener
    std::function<void(Listener&)> listener = nullptr;
    // Data that is different for different events, for example
    // MouseMoveEvent: mouse position, mousedelta..
    // KeyPressedEvent: Key..
    EventContext metaData{};

    bool operator==(const Listener& other) const
    {
        return eventType == other.eventType && &listener == &other.listener;
    }
};

template<>
struct std::hash<Listener>
{
    std::size_t operator()(const Listener& s) const noexcept
    {
        // Compute individual hash values for two members and combine them
        size_t h1 = std::hash<EventType>{}(s.eventType);
        auto ptr = reinterpret_cast<void*>(*(uintptr_t*)&s.listener);
        size_t h2 = std::hash<void*>{}(ptr);
        return h1 ^ (h2 << 1); // or use another method to combine hash values
    }
};

class Engine;

class Event
{
    friend class Engine;
public:
    // Registers a listener to a certain Event type
    template<typename T>
    static void RegisterEvent(EventType eventType, T* obj, void(T::*funcPtr)(Listener& listener))
    {
        listeners[(int)eventType].push_back(Listener{eventType, std::bind(funcPtr, obj, std::placeholders::_1)});
    }
    // Unregisters a listener to a certain Event type
    template<typename T>
    static void UnregisterEvent(EventType eventType, T* obj, void(T::*funcPtr)(Listener& listener))
    {
        std::vector<Listener>* data = &listeners[(int)eventType];
        auto it = std::find(data->begin(), data->end(), Listener{eventType, std::bind(funcPtr, obj, std::placeholders::_1)});
        if(it == data->end())
        {
            data->pop_back();
            return;
        }

        std::swap(*it, data->back());
        data->pop_back();
    }

    // Registers a listener to a certain Event type
    static void RegisterEvent(EventType eventType, const std::function<void(Listener&)>& funcPtr);
    // Unregisters a listener to a certain Event type
    static void UnregisterEvent(EventType eventType, const std::function<void(Listener&)>& funcPtr);

    // Pushes an event of a certain type with additional Data to a stack
    static void PushEvent(EventType eventType, const EventContext& metaData);
    // Pushes an event of a certain type without additional Data to a stack
    static void PushEvent(EventType eventType);

private:
    Event() = default;
    ~Event() = default;

    static void FireEvent(bool* run);

    static void StartUp();
    static void ShutDown();

    // Stores all listeners
    inline static std::vector<Listener> listeners[NUM_EVENTS];
};

#endif //CLOSINGIN_EVENT_H
