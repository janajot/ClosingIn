//
// Created by Let'sBlend on 25/02/2024.
//

#ifndef CLOSINGIN_EVENT_H
#define CLOSINGIN_EVENT_H

#define DEFINE_KEY(name, code) name = code

// The types of keys available
enum class KeyCode
{
    // Define key codes with their corresponding values
    DEFINE_KEY(Backspace, 0x08),
    DEFINE_KEY(Enter, 0x0D),
    DEFINE_KEY(Tab, 0x09),
    DEFINE_KEY(Shift, 0x10),
    DEFINE_KEY(Control, 0x11),

    DEFINE_KEY(Pause, 0x13),
    DEFINE_KEY(Capital, 0x14),

    DEFINE_KEY(Escape, 0x1B),

    DEFINE_KEY(Convert, 0x1C),
    DEFINE_KEY(NonConvert, 0x1D),
    DEFINE_KEY(Accept, 0x1E),
    DEFINE_KEY(ModeChange, 0x1F),

    DEFINE_KEY(Space, 0x20),
    DEFINE_KEY(Prior, 0x21),
    DEFINE_KEY(Next, 0x22),
    DEFINE_KEY(End, 0x23),
    DEFINE_KEY(Home, 0x24),
    DEFINE_KEY(Left, 0x25),
    DEFINE_KEY(Up, 0x26),
    DEFINE_KEY(Right, 0x27),
    DEFINE_KEY(Down, 0x28),
    DEFINE_KEY(Select, 0x29),
    DEFINE_KEY(Print, 0x2A),
    DEFINE_KEY(Execute, 0x2B),
    DEFINE_KEY(Snapshot, 0x2C),
    DEFINE_KEY(Insert, 0x2D),
    DEFINE_KEY(Delete, 0x2E),
    DEFINE_KEY(Help, 0x2F),

    DEFINE_KEY(A, 0x41),
    DEFINE_KEY(B, 0x42),
    DEFINE_KEY(C, 0x43),
    DEFINE_KEY(D, 0x44),
    DEFINE_KEY(E, 0x45),
    DEFINE_KEY(F, 0x46),
    DEFINE_KEY(G, 0x47),
    DEFINE_KEY(H, 0x48),
    DEFINE_KEY(I, 0x49),
    DEFINE_KEY(J, 0x4A),
    DEFINE_KEY(K, 0x4B),
    DEFINE_KEY(L, 0x4C),
    DEFINE_KEY(M, 0x4D),
    DEFINE_KEY(N, 0x4E),
    DEFINE_KEY(O, 0x4F),
    DEFINE_KEY(P, 0x50),
    DEFINE_KEY(Q, 0x51),
    DEFINE_KEY(R, 0x52),
    DEFINE_KEY(S, 0x53),
    DEFINE_KEY(T, 0x54),
    DEFINE_KEY(U, 0x55),
    DEFINE_KEY(V, 0x56),
    DEFINE_KEY(W, 0x57),
    DEFINE_KEY(X, 0x58),
    DEFINE_KEY(Y, 0x59),
    DEFINE_KEY(Z, 0x5A),

    DEFINE_KEY(LWin, 0x5B),
    DEFINE_KEY(RWin, 0x5C),
    DEFINE_KEY(Apps, 0x5D),

    DEFINE_KEY(Sleep, 0x5F),

    DEFINE_KEY(Numpad0, 0x60),
    DEFINE_KEY(Numpad1, 0x61),
    DEFINE_KEY(Numpad2, 0x62),
    DEFINE_KEY(Numpad3, 0x63),
    DEFINE_KEY(Numpad4, 0x64),
    DEFINE_KEY(Numpad5, 0x65),
    DEFINE_KEY(Numpad6, 0x66),
    DEFINE_KEY(Numpad7, 0x67),
    DEFINE_KEY(Numpad8, 0x68),
    DEFINE_KEY(Numpad9, 0x69),
    DEFINE_KEY(Multiply, 0x6A),
    DEFINE_KEY(Add, 0x6B),
    DEFINE_KEY(Separator, 0x6C),
    DEFINE_KEY(Subtract, 0x6D),
    DEFINE_KEY(Decimal, 0x6E),
    DEFINE_KEY(Divide, 0x6F),
    DEFINE_KEY(F1, 0x70),
    DEFINE_KEY(F2, 0x71),
    DEFINE_KEY(F3, 0x72),
    DEFINE_KEY(F4, 0x73),
    DEFINE_KEY(F5, 0x74),
    DEFINE_KEY(F6, 0x75),
    DEFINE_KEY(F7, 0x76),
    DEFINE_KEY(F8, 0x77),
    DEFINE_KEY(F9, 0x78),
    DEFINE_KEY(F10, 0x79),
    DEFINE_KEY(F11, 0x7A),
    DEFINE_KEY(F12, 0x7B),
    DEFINE_KEY(F13, 0x7C),
    DEFINE_KEY(F14, 0x7D),
    DEFINE_KEY(F15, 0x7E),
    DEFINE_KEY(F16, 0x7F),
    DEFINE_KEY(F17, 0x80),
    DEFINE_KEY(F18, 0x81),
    DEFINE_KEY(F19, 0x82),
    DEFINE_KEY(F20, 0x83),
    DEFINE_KEY(F21, 0x84),
    DEFINE_KEY(F22, 0x85),
    DEFINE_KEY(F23, 0x86),
    DEFINE_KEY(F24, 0x87),

    DEFINE_KEY(Numlock, 0x90),
    DEFINE_KEY(Scroll, 0x91),

    DEFINE_KEY(Numpad_Equal, 0x92),

    DEFINE_KEY(LShift, 0xA0),
    DEFINE_KEY(RShift, 0xA1),
    DEFINE_KEY(LControl, 0xA2),
    DEFINE_KEY(RControl, 0xA3),
    DEFINE_KEY(LMenu, 0xA4),
    DEFINE_KEY(RMenu, 0xA5),

    DEFINE_KEY(Semicolon, 0xBA),
    DEFINE_KEY(Plus, 0xBB),
    DEFINE_KEY(Comma, 0xBC),
    DEFINE_KEY(Minus, 0xBD),
    DEFINE_KEY(Period, 0xBE),
    DEFINE_KEY(Slash, 0xBF),
    DEFINE_KEY(Grave, 0xC0),
};

// The types of Mouse Buttons available
enum class Button
{
    DEFINE_KEY(LButton, 0x01),
    DEFINE_KEY(RButton, 0x02),
    DEFINE_KEY(MButton, 0x04)
};

// The types of Events available
#define NUM_EVENTS 11
enum class EventType
{
    None = 0,
    WindowClose = 1,
    WindowResize = 2,
    WindowFocus = 3,
    WindowLostFocus = 4,
    WindowMoved = 5,
    KeyPressed = 6,
    KeyReleased = 7,
    MouseButtonPressed = 8,
    MouseButtonReleased = 9,
    MouseMoved = 10,
    MouseScrolled = 11
};

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
    };
};

struct Listener
{
    // The type of event listened to
    EventType eventType;
    // Pointer to the listener
    void (*listener)(Listener& listening) = nullptr;
    // Pointer to the sender
    void (*sender)() = nullptr;
    // Data that is different for different events, for example
    // MouseMoveEvent: mouse position, mousedelta..
    // KeyPressedEvent: Key..
    EventContext metaData;

    bool operator==(const Listener& other) const
    {
        return eventType == other.eventType && listener == other.listener;
    }
};

template<>
struct std::hash<Listener>
{
    std::size_t operator()(const Listener& s) const noexcept
    {
        // Compute individual hash values for two members and combine them
        size_t h1 = std::hash<EventType>{}(s.eventType);
        size_t h2 = std::hash<void*>{}((void*)s.listener);
        return h1 ^ (h2 << 1); // or use another method to combine hash values
    }
};

class Event
{
public:
    static void StartUp();
    static void ShutDown();

    // Registers a listener to a certain Event type
    static void RegisterEvent(EventType eventType, void(*listener)(Listener& listening));
    // Unregisters a listener to a certain Event type
    static void UnregisterEvent(EventType eventType, void(*listener)(Listener& listening));

    // Fires an event of a certain type
    static void FireEvent(EventType eventType, void(*sender)());
private:
    // Stores all listeners
    //inline static std::vector<Listener> listeners[NUM_EVENTS];
    inline static std::unordered_set<Listener> listeners[NUM_EVENTS];
};

#endif //CLOSINGIN_EVENT_H