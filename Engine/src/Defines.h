//
// Created by Let'sBlend on 11/03/2024.
//

#ifndef CLOSINGIN_DEFINES_H
#define CLOSINGIN_DEFINES_H

#endif //CLOSINGIN_DEFINES_H


#ifdef PLATFORM_WINDOWS
#include <Windows.h>
#elif PLATRFORM_LINUX
#elif PLATRFORM_MAC
#endif

using int64 = int64_t;
using uint64 = uint64_t;
using fint64 = int_fast64_t;
using int32 = int32_t;
using uint32 = uint32_t;
using fint32 = int_fast32_t;
using int16 = int16_t;
using uint16 = uint16_t;
using fint16 = int_fast16_t;
using int8 = int8_t;
using uint8 = uint8_t;
using fint8 = int_fast8_t;

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}