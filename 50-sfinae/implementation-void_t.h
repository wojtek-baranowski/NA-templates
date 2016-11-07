#pragma once

template<typename... Ts>
struct voider
{
    using type = void;
};

template<typename... Ts>
using void_t = typename voider<Ts...>::type;

template<typename T>
struct has_type_typedef : std::false_type {};

template<typename T>
struct has_member_variable : std::false_type {};

