#include <iostream>
#include "Time.h"

int main()
{
	//std::cout << "seconds_to_data[" << MOONG::Time::seconds_to_date(3660) << "]" << std::endl;

	//std::cout << std::endl;

	std::cout << "get_current_time[" << MOONG::Time::get_current_time() << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR�� month(format:02)�� day(format:02)��(day_of_week) HOUR(FORMAT:02)�� minute(foRMat:02)�� second(format:02)�� MILLI_SECONDS(format:03)�и���") << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR�� month�� day��(day_of_week) HOUR�� minute�� second�� MILLI_SECONDS�и���") << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR�� month(format:02)�� day(format:03)��(day_of_week) HOUR(FORMAT:04)�� minute(foRMat:05)�� second(format:06)�� MILLI_SECONDS(format:07)�и���") << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR.month(format:02).day(format:02).HOUR(FORMAT:02).minute(foRMat:02).second(format:02).MILLI_SECONDS(format:03)") << "]" << std::endl;

	return 0;
}