// 02/02/22

#pragma once
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>
#include <regex>
#include <chrono>
#include <vector>

/* STATIC FUNCTIONS */

template<typename _Elem, typename final_dur, typename dur>
[[nodiscard]] static inline constexpr final_dur func(std::basic_stringstream<_Elem>& ss) noexcept
{
    auto num = dur().count();
    if (!((ss) >> num))
    {
        (ss).clear();
        return dur();
    }
    (ss).clear();
    return final_dur(dur(num));
}

template<typename _Elem, typename final_dur, typename duration, typename duration2, typename... the_rest>
static inline constexpr final_dur func(std::basic_stringstream<_Elem>& ss) noexcept
{
    return func<_Elem, final_dur, duration>(ss) + func<_Elem, final_dur, duration2, the_rest...>(ss);
}

namespace ts_cnvr
{
    //namespace sfs = std::filesystem;

    /* TS CNVR */

    template<typename _Elem, typename final_dur, typename duration, typename ...other_dur>
    [[nodiscard]] constexpr final_dur ts_cnvr_dur(const std::basic_string<_Elem>& str) noexcept
    {
        std::basic_stringstream<_Elem> ss(str);
        // to do flip template parameters
        final_dur temp_duration(func<_Elem, final_dur, duration, other_dur...>(ss));
        ss.clear();
        return temp_duration;
    }

    template<typename _Elem, typename final_dur, typename duration, typename ...other_dur>
    void ts_cnvr_str(std::basic_string<_Elem>& str) noexcept
    {
        std::basic_stringstream<_Elem> ss(str);
        // to do flip template parameters
        final_dur temp_duration(func<_Elem, final_dur, duration, other_dur...>(ss));
        ss.str(std::basic_string<_Elem>());
        ss.clear();
        ss << temp_duration.count();
        str.clear();
        ss >> str;
    }
}