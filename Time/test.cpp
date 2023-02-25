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
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "year년 month(month_format:%02d)월 day(day_format:%02d)일(day_of_week) hour(hour_format:%02d)시 minute(minute_format:%02d)분 second(second_format:%02d)초 milliseconds(milliseconds_format:%03d)밀리초").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "year년 month월 day일(day_of_week) hour시 minute분 second초 milliseconds(month_format:%02d)(day_format:%02d)(hour_format:%02d)(minute_format:%02d)(second_format:%02d)(milliseconds_format:%03d)밀리초").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR년 month(month_format:%02d)월 day(day_format:%02d)일(day_of_week요일) HOUR(hour_FORMAT:%02d)시 minute(minute_foRMat:%02d)분 second(second_format:%02d)초 MILLISECONDS(MILLISECONDS_format:%03d)밀리초").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR년 month월(month_format:%02d) day일(day_format:%02d) HOUR시(hour_format:%02d) minute분(minute_format:%02d) second초(second_format:%02d) MILLISECONDS밀리초(MILLISECONDS_FORMAT:%03d)").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR년 month월 day일 HOUR시 minute분 second초 MILLISECONDS밀리초").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "HOUR시 minute분 second초").c_str() << "]" << std::endl;
	std::cout << "[" << MOONG::Time::make_date_format(MOONG::Time::get_current_time(), "YEAR년 month(month_format:%02d)월 day(day_format:%03d)일(day_of_week) HOUR(hour_FORMAT:%04d)시 minute(minute_foRMat:%05d)분 second(second_format:%06d)초 MILLISECONDS(MILLISECONDS_format:%07d)밀리초").c_str() << "]" << std::endl;
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

	std::cout << "make_date_format[" << MOONG::Time::make_date_format(calculated_time, "year년 month월 day일 hour시 minute분 second초 milliseconds밀리초") << "]" << std::endl;
	std::cout << "make_time_taken_format[" << MOONG::Time::make_time_taken_format(calculated_time).c_str() << "]" << std::endl;

	std::cout << "make_time_taken_format[" << MOONG::Time::make_time_taken_format(MOONG::Time::get_current_time()).c_str() << "]" << std::endl;

	std::cout << std::endl;

	return 0;
}