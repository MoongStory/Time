#include "Time.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"
#include "../../StringTool/StringTool/StringTool.h"

const SYSTEMTIME MOONG::Time::get_current_time()
{
	SYSTEMTIME system_time = { 0 };
	GetLocalTime(&system_time);

	return system_time;
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
	return MOONG::ConvertDataType::milliseconds_to_systemtime(get_time_diff_in_milliseconds_(start_time, end_time));
}

const std::string MOONG::Time::make_date_format(SYSTEMTIME system_time, std::string date_format/* = ""*/)
{
	std::string output;

	std::string day_of_week;
	switch (system_time.wDayOfWeek)
	{
	case 0:
		day_of_week = "일";
		break;
	case 1:
		day_of_week = "월";
		break;
	case 2:
		day_of_week = "화";
		break;
	case 3:
		day_of_week = "수";
		break;
	case 4:
		day_of_week = "목";
		break;
	case 5:
		day_of_week = "금";
		break;
	case 6:
		day_of_week = "토";
		break;
	default:
		day_of_week = "something wrong";
		break;
	}

	if (date_format.length() <= 0)
	{
		output = MOONG::StringTool::format("%d년 %02d월 %02d일(%s) %02d시 %02d분 %02d초 %03d밀리초",
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
		output = date_format;

		MOONG::StringTool::tolower(output);

		if (output.find(MOONG::TIME::DATE_FORMAT::YEAR) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::YEAR, MOONG::ConvertDataType::toString(system_time.wYear));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MONTH_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMonth)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::MONTH) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::ConvertDataType::toString(system_time.wMonth));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK, day_of_week);
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::DAY_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wDay)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::DAY) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::DAY, MOONG::ConvertDataType::toString(system_time.wDay));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::HOUR_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wHour)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::HOUR) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::HOUR, MOONG::ConvertDataType::toString(system_time.wHour));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMinute)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::MINUTE) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MINUTE, MOONG::ConvertDataType::toString(system_time.wMinute));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wMilliseconds)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MILLI_SECONDS, MOONG::ConvertDataType::toString(system_time.wMilliseconds));
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT) != std::string::npos)
		{
			size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT);
			index_head += MOONG::TIME::DATE_FORMAT::SECOND_FORMAT.length() + 1;
			size_t index_tail = output.find(")", index_head);

			output.replace(
				output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT),
				(index_tail - (output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT)) + 1),
				MOONG::StringTool::format(std::string("%") + output.substr(index_head, index_tail - index_head) + std::string("d"), system_time.wSecond)
			);
		}
		else if (output.find(MOONG::TIME::DATE_FORMAT::SECOND) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::SECOND, MOONG::ConvertDataType::toString(system_time.wSecond));
		}
	}

	return output;
}

const unsigned long long MOONG::Time::get_time_diff_in_milliseconds_(const SYSTEMTIME& start_time, const SYSTEMTIME& end_time)
{
	FILETIME file_time_1 = { 0 }, file_time_2 = { 0 };
	ULARGE_INTEGER ul1 = { 0 }, ul2 = { 0 };

	SystemTimeToFileTime(&start_time, &file_time_1);
	SystemTimeToFileTime(&end_time, &file_time_2);

	ul1.LowPart = file_time_1.dwLowDateTime;
	ul1.HighPart = file_time_1.dwHighDateTime;

	ul2.LowPart = file_time_2.dwLowDateTime;
	ul2.HighPart = file_time_2.dwHighDateTime;

	return abs(static_cast<long long>(ul2.QuadPart - ul1.QuadPart)) / 10000;
}
