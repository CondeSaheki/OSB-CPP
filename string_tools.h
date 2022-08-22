#pragma once

#include <sstream>
#include <fstream>
#include <filesystem>
#include <string>
#include <regex>
#include <chrono>
#include <vector>





/* REGEX E STR EDIT */

template<typename _Elem = char>
void str_keep(std::basic_string<_Elem>& str, const std::basic_string<_Elem>& safe) noexcept
{
    bool ok;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        ok = false;
        for (auto it2 = safe.begin(); it2 != safe.end(); ++it2)
        {
            if (*it == *it2)
            {
                ok = true;
                break;
            }
        }
        if (!ok) { *it = ' '; }
    }
}

template<typename _Elem = char>
void regex_edit(std::basic_string<_Elem>& str, const std::basic_string<_Elem>& rgx_str,
    void(*edit_lambda)(std::basic_string<_Elem>& str)) noexcept
{
    const std::basic_regex<_Elem> rgx(rgx_str);
    if (!str.empty() && !rgx._Empty())
    {
        typename std::basic_string<_Elem>::iterator match_it = str.begin();
        std::match_results<typename std::basic_string<_Elem>::iterator> rgx_matchs;
        std::basic_string<_Elem> sub_str;
        while (std::regex_search(match_it, str.end(), rgx_matchs, rgx))
        {
            sub_str = rgx_matchs.str();
            edit_lambda(sub_str);
            match_it = std::get<1>((rgx_matchs.prefix())) + sub_str.size();
            str.replace(std::get<1>((rgx_matchs.prefix())), std::get<0>((rgx_matchs.suffix())), sub_str.begin(), sub_str.end());
            sub_str.clear();
        }
    }
}

template<typename _Elem = char>
void regex_edit(std::basic_string<_Elem>& str, const std::basic_regex<_Elem>& rgx,
    void(*edit_lambda)(std::basic_string<_Elem>& str)) noexcept
{
    if (!str.empty() && !rgx._Empty())
    {
        typename std::basic_string<_Elem>::iterator match_it = str.begin();
        std::match_results<typename std::basic_string<_Elem>::iterator> rgx_matchs;
        std::basic_string<_Elem> sub_str;
        while (std::regex_search(match_it, str.end(), rgx_matchs, rgx))
        {
            sub_str = rgx_matchs.str();
            edit_lambda(sub_str);
            match_it = std::get<1>((rgx_matchs.prefix())) + sub_str.size();
            str.replace(std::get<1>((rgx_matchs.prefix())), std::get<0>((rgx_matchs.suffix())), sub_str.begin(), sub_str.end());
            sub_str.clear();
        }
    }
}

template<typename _Elem = char>
[[nodiscard]] constexpr std::vector<std::basic_string<_Elem>> regex_results_vec(std::basic_string<_Elem>& str,
    const std::basic_regex<_Elem>& rgx, const size_t& reverve = 10) noexcept
{
    std::vector<std::basic_string<_Elem>> matches;
    if (!str.empty() && !rgx._Empty())
    {
        matches.reserve(reverve);
        typename std::basic_string<_Elem>::iterator match_it = str.begin();
        std::match_results<typename std::basic_string<_Elem>::iterator> rgx_matchs;
        while (std::regex_search(match_it, str.end(), rgx_matchs, rgx))
        {
            matches.emplace_back(rgx_matchs.str());
            match_it = std::get<1>((rgx_matchs.prefix())) + rgx_matchs.str().size();
        }
    }
    return matches;
}

template<typename _Elem = char>
[[nodiscard]] constexpr std::vector<std::basic_string<_Elem>> regex_results_vec(std::basic_string<_Elem>& str,
    const std::basic_string<_Elem>& rgx_str, const size_t& reverve = 10) noexcept
{
    const std::basic_regex<_Elem> rgx(rgx_str);
    std::vector<std::basic_string<_Elem>> matches;
    if (!str.empty() && !rgx._Empty())
    {
        matches.reserve(reverve);
        typename std::basic_string<_Elem>::iterator match_it = str.begin();
        std::match_results<typename std::basic_string<_Elem>::iterator> rgx_matchs;
        while (std::regex_search(match_it, str.end(), rgx_matchs, rgx))
        {
            matches.emplace_back(rgx_matchs.str());
            match_it = std::get<1>((rgx_matchs.prefix())) + rgx_matchs.str().size();
        }
    }
    return matches;
}

template<typename char_t = char> [[nodiscard]] constexpr size_t num_lines(const std::basic_string<char_t>& str, char_t letter) noexcept
{
    size_t counter = 0;
    for (auto it = str.begin(); it != str.end(); ++it)
    {
        if((*it) == '\n')
        {
            ++counter;
        }
    }
    return counter;
}

template<typename _Elem> [[nodiscard]] constexpr std::vector<std::pair<_Elem, _Elem>> lines(const typename std::basic_string<_Elem>::iterator& begin, 
    const  typename std::basic_string<_Elem>::iterator& end) noexcept
{
    typename std::basic_string<_Elem>::iterator _begin = begin;
    std::vector<std::pair<_Elem, _Elem>> vec;
    for (auto it = _begin; it != end; ++it)
    {
        if (*it != '\n')
        {
            vec.emplace_back(begin, *it);
            _begin = it;
        }
    }
}