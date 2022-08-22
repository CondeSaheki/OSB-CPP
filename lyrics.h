#pragma once
#include "type.h"
#include <chrono>
#include <regex>
#include <sstream>
#include "string_tools.h"
//#include "io.h"
#include "time_stamp.h"

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



namespace nimiat::sub
{

	namespace sch = std::chrono;

	template<typename char_type_ = char, typename time_point_ = sch::time_point<sch::system_clock>>
	class sub
	{
	public: // type
		using char_type = char_type_;
		using time_point = time_point_;
	public: // constructors
		sub(const size_t& Num, const time_point& begin, const time_point& end, const std::basic_string<char_type>& str)
			: num(Num), begin_(begin), end_(end), txt_(str) {}
	private: // data
		size_t num;
		time_point begin_;
		time_point end_;
		std::basic_string<char_type> txt_;
	public: // operators
	};



	template<typename _Elem = char> [[nodiscard]] constexpr std::vector<sub<_Elem, sch::time_point<sch::system_clock>>> inputf_str(std::basic_string<_Elem>& str) noexcept
	{
		const std::basic_regex<_Elem> rgx(L"[[:d:]]+\n[[:d:]][[:d:]]\:[[:d:]][[:d:]]\:[[:d:]][[:d:]]\,[[:d:]][[:d:]][[:d:]] --> [[:d:]][[:d:]]\:[[:d:]][[:d:]]\:[[:d:]][[:d:]]\,[[:d:]][[:d:]][[:d:]]\n(.*\n)*\n");

		std::vector<sub<_Elem, sch::time_point<sch::system_clock>>> result;
		if (!str.empty() && !rgx._Empty())
		{
			result.reserve((num_lines<_Elem>(str, std::use_facet<std::ctype<_Elem>>(std::locale()).widen('\n')) / 4) + 10);

			typename std::basic_string<_Elem>::iterator match_it = str.begin();
			std::match_results<typename std::basic_string<_Elem>::iterator> rgx_matchs;

			size_t index = 0;
			sch::milliseconds start(0);
			sch::milliseconds end(0);
			std::basic_string<_Elem> string;
			std::basic_stringstream<_Elem> ss;

			while (std::regex_search(match_it, str.end(), rgx_matchs, rgx))
			{
				typename std::basic_string<_Elem>::iterator _begin = (rgx_matchs[0]).first;

				for (auto it = _begin; it != (rgx_matchs[0]).second; ++it)
				{
					if (*it != '\n')
					{
						ss << std::basic_string<_Elem>(_begin, it);
						if (ss >> index)
						{
							// faild to convert in index type
						}
						ss.clear();
						ss.str(std::basic_string<_Elem>());
						_begin = it;
					}
				}
				for (auto it = _begin; it != (rgx_matchs[0]).second; ++it)
				{
					if (*it != '\n')
					{
						std::basic_string<_Elem> temp1 = std::basic_string<_Elem>(_begin, _begin + 12);
						str_keep<_Elem>(temp1, L"0123456789 ");
						start = ts_cnvr::ts_cnvr_dur<_Elem, sch::milliseconds, sch::milliseconds, sch::seconds, sch::minutes, sch::hours>(temp1);
						std::basic_string<_Elem> temp2 = std::basic_string<_Elem>(_begin + 17, it);
						str_keep<_Elem>(temp2, L"0123456789 ");
						end = ts_cnvr::ts_cnvr_dur<_Elem, sch::milliseconds, sch::milliseconds, sch::seconds, sch::minutes, sch::hours>(temp2);
						_begin = it;
					}
				}
				string = std::basic_string<_Elem>(_begin, std::prev((rgx_matchs[0]).second));
				result.emplace_back(index, start, end, string);
				// resets
				index = size_t();
				start = sch::milliseconds();
				end = sch::milliseconds();
				string = std::basic_string<_Elem>();
				match_it = std::get<1>((rgx_matchs.prefix())) + rgx_matchs.str().size();
			}
		}
		return result;
	}
}