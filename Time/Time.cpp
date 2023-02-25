#include "Time.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"
#include "../../StringTool/StringTool/StringTool.h"

const std::string MOONG::Time::get_current_time(std::string date_format/* = ""*/)
{
	SYSTEMTIME system_time = { 0 };
	GetLocalTime(&system_time);

	std::string current_time;

	std::string day_of_week;
	switch (system_time.wDayOfWeek)
	{
	case 0:
		day_of_week = "일요일";
		break;
	case 1:
		day_of_week = "월요일";
		break;
	case 2:
		day_of_week = "화요일";
		break;
	case 3:
		day_of_week = "수요일";
		break;
	case 4:
		day_of_week = "목요일";
		break;
	case 5:
		day_of_week = "금요일";
		break;
	case 6:
		day_of_week = "토요일";
		break;
	default:
		day_of_week = "something wrong";
		break;
	}

	if (date_format.length() <= 0)
	{
		current_time = MOONG::StringTool::format("%d년 %02d월 %02d일(%s) %02d시 %02d분 %02d초 %03d밀리초",
			system_time.wYear,
			system_time.wMonth,
			system_time.wDay,
			day_of_week.c_str(),
			system_time.wHour,
			system_time.wMinute,
			system_time.wSecond,
			system_time.wMilliseconds);
	}
	else
	{
		current_time = date_format;

		MOONG::StringTool::tolower(current_time);

		if (current_time.find(MOONG::TIME::DATE_FORMAT::YEAR) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::YEAR, MOONG::ConvertDataType::toString(system_time.wYear));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MONTH_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);
			
			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMonth)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::MONTH) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::ConvertDataType::toString(system_time.wMonth));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK, day_of_week);
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::DAY_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);

			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wDay)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::DAY) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::DAY, MOONG::ConvertDataType::toString(system_time.wDay));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::HOUR_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);

			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wHour)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::HOUR) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::HOUR, MOONG::ConvertDataType::toString(system_time.wHour));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);

			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMinute)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MINUTE, MOONG::ConvertDataType::toString(system_time.wMinute));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);

			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMilliseconds)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MILLI_SECONDS, MOONG::ConvertDataType::toString(system_time.wMilliseconds));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT) != std::string::npos)
		{
			size_t index_head = current_time.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::SECOND_FORMAT.length() + 1;
			size_t index_tail = current_time.find(")", index_head);

			current_time.replace(
				current_time.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT),
				(index_tail - (current_time.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + current_time.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wSecond)
			);
		}
		else if (current_time.find(MOONG::TIME::DATE_FORMAT::SECOND) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::SECOND, MOONG::ConvertDataType::toString(system_time.wSecond));
		}
	}

	return current_time;
}

const std::string MOONG::Time::second_to_date(unsigned long param_second)
{
	if (0 == param_second)
	{
		return std::string("0초");
	}

	const unsigned long second_equal_to_minute = 60;
	const unsigned long second_equal_to_hour = second_equal_to_minute * 60;
	const unsigned long second_equal_to_day = second_equal_to_hour * 24;

	unsigned int day = param_second / second_equal_to_day;
	param_second %= second_equal_to_day;

	unsigned int hour = param_second / second_equal_to_hour;
	param_second %= second_equal_to_hour;

	unsigned int minute = param_second / second_equal_to_minute;
	param_second %= second_equal_to_minute;

	unsigned int second = param_second;

	std::string date = "";

	if (day > 0)
	{
		date += MOONG::StringTool::format("%d일", day);
	}

	if (hour > 0)
	{
		if (date.length() > 0)
		{
			date += " ";
		}

		date += MOONG::StringTool::format("%d시간", hour);
	}

	if (minute > 0)
	{
		if (date.length() > 0)
		{
			date += " ";
		}

		date += MOONG::StringTool::format("%d분", minute);
	}

	if (second > 0)
	{
		if (date.length() > 0)
		{
			date += " ";
		}

		date += MOONG::StringTool::format("%d초", second);
	}

	return date;
}

const SYSTEMTIME MOONG::Time::calculate_difference_between_times(SYSTEMTIME start_time, SYSTEMTIME end_time)
{
	unsigned long long calculated_milliseconds = MOONG::Time::get_time_diff_in_milliseconds(start_time, end_time);
	
	const unsigned long long milliseconds_equal_to_second = 1000;
	const unsigned long long milliseconds_equal_to_minute = milliseconds_equal_to_second * 60;
	const unsigned long long milliseconds_equal_to_hour = milliseconds_equal_to_minute * 60;
	const unsigned long long milliseconds_equal_to_day = milliseconds_equal_to_hour * 24;

	WORD day = static_cast<WORD>(calculated_milliseconds / milliseconds_equal_to_day);
	calculated_milliseconds %= milliseconds_equal_to_day;

	WORD hour = static_cast<WORD>(calculated_milliseconds / milliseconds_equal_to_hour);
	calculated_milliseconds %= milliseconds_equal_to_hour;

	WORD minute = static_cast<WORD>(calculated_milliseconds / milliseconds_equal_to_minute);
	calculated_milliseconds %= milliseconds_equal_to_minute;

	WORD second = static_cast<WORD>(calculated_milliseconds / milliseconds_equal_to_second);
	calculated_milliseconds %= milliseconds_equal_to_second;

	WORD milliseconds = static_cast<WORD>(calculated_milliseconds);

	SYSTEMTIME calculated_time = { 0 };
	calculated_time.wDay = day;
	calculated_time.wHour = hour;
	calculated_time.wMinute = minute;
	calculated_time.wSecond = second;
	calculated_time.wMilliseconds = milliseconds;

	return calculated_time;
}

const unsigned long long MOONG::Time::get_time_diff_in_milliseconds(const SYSTEMTIME& start_time, const SYSTEMTIME& end_time)
{
	FILETIME file_time_1 = { 0 }, file_time_2 = { 0 };
	ULARGE_INTEGER ul1 = { 0 }, ul2 = { 0 };

	SystemTimeToFileTime(&start_time, &file_time_1);
	SystemTimeToFileTime(&end_time, &file_time_2);

	ul1.LowPart = file_time_1.dwLowDateTime;
	ul1.HighPart = file_time_1.dwHighDateTime;

	ul2.LowPart = file_time_2.dwLowDateTime;
	ul2.HighPart = file_time_2.dwHighDateTime;

	unsigned long long diff = (ul2.QuadPart - ul1.QuadPart) / 10000;
	
	return diff < 0 ? (diff * -1) : diff;
}
