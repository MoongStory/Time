#include <iostream>
#include "Time.h"

int main()
{
	//std::cout << "seconds_to_data[" << MOONG::Time::seconds_to_date(3660) << "]" << std::endl;

	//std::cout << std::endl;

	std::cout << "get_current_time[" << MOONG::Time::get_current_time() << "]" << std::endl;
	//std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR�� month�� day��(day_of_week) HOUR�� minute�� second�� MILLI_SECONDS�и���") << "]" << std::endl;
	std::cout << "get_current_time[" << MOONG::Time::get_current_time("YEAR�� month(format:04)�� day(format:04)��(day_of_week) HOUR(FORMAT:03)�� minute(foRMat:04)�� second(format:05)�� MILLI_SECONDS(format:06)�и���") << "]" << std::endl;

	return 0;
}