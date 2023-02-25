#include <iostream>
#include "Time.h"

int main()
{
	//std::cout << "seconds_to_data[" << MOONG::Time::seconds_to_date(3660) << "]" << std::endl;

	//std::cout << std::endl;

	std::cout << "get_current_time[" << MOONG::Time::get_current_time() << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR년 month월 day일(day_of_week) HOUR시 minute분 second초 MILLI_SECONDS밀리초") << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR년 month(format:04)월 day(format:04)일(day_of_week) HOUR(FORMAT:03)시 minute(foRMat:04)분 second(format:05)초 MILLI_SECONDS(format:06)밀리초") << "]" << std::endl;

	return 0;
}