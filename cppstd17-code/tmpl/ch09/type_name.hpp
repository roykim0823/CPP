#pragma once
#include <string_view>

template <class T>
constexpr std::string_view type_name() {
    // This is a simplified example, the actual parsing is more robust
#if defined(__GNUC__)
    // Extracts the name from the template argument T in the function signature
    std::string_view p = __PRETTY_FUNCTION__;
    // Example: static constexpr std::string_view type_name() [with T = int]
    return p.substr(34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    // Extracts the name from the template argument T in the function signature
    std::string_view p = __PRETTY_FUNCTION__;
    // Example: static constexpr std::string_view type_name() [with T = int]
    return p.substr(49, p.size() - 49 - 1);
#else
    return "Unknown Type";
#endif
}