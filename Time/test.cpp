#include <iostream>
#include "Time.h"

#include <wtypes.h>

int main()
{
	//std::cout << "seconds_to_data[" << MOONG::Time::second_to_date(3660) << "]" << std::endl;

	//std::cout << std::endl;

	//std::cout << "get_current_time[" << MOONG::Time::get_current_time() << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR년 month(format:02)월 day(format:02)일(day_of_week) HOUR(FORMAT:02)시 minute(foRMat:02)분 second(format:02)초 MILLISECONDS(format:03)밀리초") << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR년 month월 day일(day_of_week) HOUR시 minute분 second초 MILLISECONDS밀리초") << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR년 month(format:02)월 day(format:03)일(day_of_week) HOUR(FORMAT:04)시 minute(foRMat:05)분 second(format:06)초 MILLISECONDS(format:07)밀리초") << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR.month(format:02).day(format:02).HOUR(FORMAT:02).minute(foRMat:02).second(format:02).MILLISECONDS(format:03)") << "]" << std::endl;

	//std::cout << std::endl;

	SYSTEMTIME start_time = { 0 };
	GetLocalTime(&start_time);

	start_time.wDay -= 1;
	start_time.wMilliseconds -= 1;

	SYSTEMTIME end_time = { 0 };
	GetLocalTime(&end_time);

	SYSTEMTIME calculated_time = MOONG::Time::calculate_difference_between_times(start_time, end_time);

	std::cout << std::endl;

	std::cout << "make_date_format[" << MOONG::Time::make_date_format(calculated_time, "year년 month월 day일 hour시 minute분 second초 milliseconds밀리초") << "]" << std::endl;

	std::cout << std::endl;

	return 0;
}