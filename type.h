// 01/02/22

#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

// nodiscard 
#ifndef nodiscard
#ifndef __has_cpp_attribute
#define nodiscard
#elif __has_cpp_attribute(nodiscard) >= 201603L
#define nodiscard [[nodiscard]]
#else
#define nodiscard
#endif
#endif

#undef nodiscard

namespace nimiat
{

    /* types */

    // natural num
    using natural = unsigned int;
    using natural_8 = uint8_t;
    using natural_16 = uint16_t;
    using natural_32 = uint32_t;
    using natural_64 = uint64_t;
    // integer num
    using integer = int;
    using integer_8 = int8_t;
    using integer_16 = int16_t;
    using integer_32 = int32_t;
    using integer_64 = int64_t;
    // decimal num
    using decimal = double;
    using decimal_32 = float;
    using decimal_64 = double;
    using decimal_128 = long double;
    // characters
    using character = char;
    using character_8 = char16_t;
    using character_16 = char16_t;
    using character_32 = char32_t;
    using character_w = wchar_t;
    // binary
    using logical = bool;
    //string, stringstream and fstream
    using string = std::basic_string<character>;
    using stringstream = std::basic_stringstream<character>;
    using istringstream = std::basic_istringstream<character>;
    using ostringstream = std::basic_ostringstream<character>;
    using fstream = std::basic_stringstream<character>;
    using ifstream = std::basic_string<character>;
    using ofstream = std::basic_string<character>;
    using string_w = std::basic_string<character_w>;
    using stringstream_w = std::basic_stringstream<character_w>;
    using istringstream_w = std::basic_istringstream<character_w>;
    using ostringstream_w = std::basic_ostringstream<character_w>;
    using fstream_w = std::basic_stringstream<character_w>;
    using ifstream_w = std::basic_string<character_w>;
    using ofstream_w = std::basic_string<character_w>;
    using string_8 = std::basic_string<character_8>;
    using stringstream_8 = std::basic_stringstream<character_8>;
    using istringstream_8 = std::basic_istringstream<character_8>;
    using ostringstream_8 = std::basic_ostringstream<character_8>;
    using fstream_8 = std::basic_stringstream<character_8>;
    using ifstream_8 = std::basic_string<character_8>;
    using ofstream_8 = std::basic_string<character_8>;
    using string_16 = std::basic_string<character_8>;
    using stringstream_16 = std::basic_stringstream<character_16>;
    using istringstream_16 = std::basic_istringstream<character_16>;
    using ostringstream_16 = std::basic_ostringstream<character_16>;
    using fstream_16 = std::basic_stringstream<character_16>;
    using ifstream_16 = std::basic_string<character_16>;
    using ofstream_16 = std::basic_string<character_16>;
    using string_32 = std::basic_string<character_32>;
    using stringstream_32 = std::basic_stringstream<character_32>;
    using istringstream_32 = std::basic_istringstream<character_32>;
    using ostringstream_32 = std::basic_ostringstream<character_32>;
    using fstream_32 = std::basic_stringstream<character_32>;
    using ifstream_32 = std::basic_string<character_32>;
    using ofstream_32 = std::basic_string<character_32>;
}