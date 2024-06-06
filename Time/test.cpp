#include <iostream>
#include "Time.h"

#include <wtypes.h>

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"

int main()
{
	std::cout << "seconds_to_data[" << MOONG::Time::make_time_taken_format(3601000) << "]" << std::endl;
	std::cout << "seconds_to_data[" << MOONG::Time::make_time_taken_format(3601010) << "]" << std::endl;
	std::cout << "make_date_format[" << MOONG::Time::make_time_taken_format(MOONG::ConvertDataType::milliseconds_to_systemtime(3601000)).c_str() << "]" << std::endl;
	std::cout << "make_date_format[" << MOONG::Time::make_time_taken_format(MOONG::ConvertDataType::milliseconds_to_systemtime(3601010)).c_str() << "]" << std::endl;

	std::cout << std::endl;

	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time()).c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "year�� month(month_format:%02d)�� day(day_format:%02d)��(day_of_week) hour(hour_format:%02d)�� minute(minute_format:%02d)�� second(second_format:%02d)�� milliseconds(milliseconds_format:%03d)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "year�� month�� day��(day_of_week) hour�� minute�� second�� milliseconds(month_format:%02d)(day_format:%02d)(hour_format:%02d)(minute_format:%02d)(second_format:%02d)(milliseconds_format:%03d)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month(month_format:%02d)�� day(day_format:%02d)��(day_of_week����) HOUR(hour_FORMAT:%02d)�� minute(minute_foRMat:%02d)�� second(second_format:%02d)�� MILLISECONDS(MILLISECONDS_format:%03d)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month��(month_format:%02d) day��(day_format:%02d) HOUR��(hour_format:%02d) minute��(minute_format:%02d) second��(second_format:%02d) MILLISECONDS�и���(MILLISECONDS_FORMAT:%03d)").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month�� day�� HOUR�� minute�� second�� MILLISECONDS�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR�� minute�� second��").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR�� month(month_format:%02d)�� day(day_format:%03d)��(day_of_week) HOUR(hour_FORMAT:%04d)�� minute(minute_foRMat:%05d)�� second(second_format:%06d)�� MILLISECONDS(MILLISECONDS_format:%07d)�и���").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR.month(month_format:%02d).day(day_format:%02d).HOUR(hour_FORMAT:%02d).minute(minute_foRMat:%02d).second(second_format:%02d).MILLISECONDS(MILLISECONDS_format:%03d)").c_str() << "]" << std::endl;

	std::cout << std::endl;

	SYSTEMTIME start_time = { 0 };
	GetLocalTime(&start_time);

	//start_time.wYear -= 1;
	//start_time.wMonth -= 1;
	//start_time.wDay -= 1;
	start_time.wHour -= 1;
	start_time.wMinute -= 1;
	start_time.wSecond -= 1;
	start_time.wMilliseconds -= 1;

	SYSTEMTIME end_time = { 0 };
	GetLocalTime(&end_time);

	SYSTEMTIME calculated_time = MOONG::Time::calculate_difference_between_times(start_time, end_time);

	std::cout << "make_date_format[" << MOONG::Time::make_date_format(calculated_time, "year�� month�� day�� hour�� minute�� second�� milliseconds�и���") << "]" << std::endl;
	std::cout << "make_time_taken_format[" << MOONG::Time::make_time_taken_format(calculated_time).c_str() << "]" << std::endl;

	std::cout << "make_time_taken_format[" << MOONG::Time::make_time_taken_format(MOONG::Time::get_current_time()).c_str() << "]" << std::endl;

	std::cout << std::endl;

	return 0;
}