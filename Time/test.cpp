#include <iostream>
#include "Time.h"

#include <wtypes.h>

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

int main()
{
	std::cout << "seconds_to_data[" << MOONG::Time::second_to_date(3601) << "]" << std::endl;
	std::cout << "make_date_format[" << MOONG::Time::make_date_format(MOONG::ConvertDataType::milliseconds_to_systemtime(3601 * 1000)).c_str() << "]" << std::endl;

	std::cout << std::endl;

	// "YEAR�� month(month_format:02)�� day(day_format:02)�� HOUR(hour_FORMAT:02)�� minute(minute_foRMat:02)�� second(second_format:02)�� MILLISECONDS(MILLISECONDS_format:03)�и���"
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time()).c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month(format:02)�� day(format:02)�� HOUR(FORMAT:02)�� minute(foRMat:02)�� second(format:02)�� MILLISECONDS(format:03)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month(format:02)�� day(format:02)��(day_of_week����) HOUR(FORMAT:02)�� minute(foRMat:02)�� second(format:02)�� MILLISECONDS(format:03)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month�� day��(day_of_week) HOUR�� minute�� second�� MILLISECONDS�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month(format:02)�� day(format:03)��(day_of_week) HOUR(FORMAT:04)�� minute(foRMat:05)�� second(format:06)�� MILLISECONDS(format:07)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR.month(format:02).day(format:02).HOUR(FORMAT:02).minute(foRMat:02).second(format:02).MILLISECONDS(format:03)").c_str() << "]" << std::endl;

	std::cout << std::endl;

	//SYSTEMTIME start_time = { 0 };
	//GetLocalTime(&start_time);

	//start_time.wDay -= 1;
	//start_time.wMilliseconds -= 1;

	//SYSTEMTIME end_time = { 0 };
	//GetLocalTime(&end_time);

	//SYSTEMTIME calculated_time = MOONG::Time::calculate_difference_between_times(start_time, end_time);

	//std::cout << "make_date_format[" << MOONG::Time::make_date_format(calculated_time, "year�� month�� day�� hour�� minute�� second�� milliseconds�и���") << "]" << std::endl;

	//std::cout << std::endl;

	return 0;
}