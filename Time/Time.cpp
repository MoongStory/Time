#include "Time.h"

#include <wtypes.h>

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
			// 여기부터
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::ConvertDataType::toString(system_time.wMonth));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MONTH) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::ConvertDataType::toString(system_time.wMonth));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK, day_of_week);
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::DAY) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::DAY, MOONG::ConvertDataType::toString(system_time.wDay));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::HOUR) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::HOUR, MOONG::ConvertDataType::toString(system_time.wHour));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MINUTE) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MINUTE, MOONG::ConvertDataType::toString(system_time.wMinute));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::MILLI_SECONDS) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::MILLI_SECONDS, MOONG::ConvertDataType::toString(system_time.wMilliseconds));
		}

		if (current_time.find(MOONG::TIME::DATE_FORMAT::SECOND) != std::string::npos)
		{
			MOONG::StringTool::replace(current_time, MOONG::TIME::DATE_FORMAT::SECOND, MOONG::ConvertDataType::toString(system_time.wSecond));
		}
	}

	return current_time;
}

const std::string MOONG::Time::seconds_to_date(unsigned long seconds)
{
	if (0 == seconds)
	{
		return std::string("0초");
	}

	const unsigned long seconds_equal_to_minute = 60;
	const unsigned long seconds_equal_to_hour = seconds_equal_to_minute * 60;
	const unsigned long seconds_equal_to_day = seconds_equal_to_hour * 24;

	unsigned int day = seconds / seconds_equal_to_day;
	seconds %= seconds_equal_to_day;

	unsigned int hour = seconds / seconds_equal_to_hour;
	seconds %= seconds_equal_to_hour;

	unsigned int minute = seconds / seconds_equal_to_minute;
	seconds %= seconds_equal_to_minute;

	unsigned int second = seconds;

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
