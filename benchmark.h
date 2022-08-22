#pragma once
#include <chrono>
#include <iostream>


namespace nimiat::benchmark
{
	namespace sch = std::chrono;
	class bench
	{
	public:
		bench() : begin(sch::steady_clock::now()) {}
		~bench()
		{
			end = sch::steady_clock::now();
			std::cout << '<' << sch::duration_cast<sch::milliseconds>(end - begin).count() << '>';
		}
	private:
		sch::time_point<sch::steady_clock> begin;
		sch::time_point<sch::steady_clock> end;
	};
}
