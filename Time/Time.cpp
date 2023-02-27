#include "Time.h"

#include "../../ConvertDataType/ConvertDataType/ConvertDataType.h"
#include "../../StringTool/StringTool/StringTool.h"

const SYSTEMTIME MOONG::Time::get_current_time()
{
	SYSTEMTIME system_time = { 0 };
	GetLocalTime(&system_time);

	return system_time;
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

		if (output.find(MOONG::TIME::DATE_FORMAT::MONTH) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MONTH_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::MONTH_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::MONTH_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::StringTool::format(format, system_time.wMonth));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MONTH, MOONG::ConvertDataType::toString(system_time.wMonth));
			}
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK) != std::string::npos)
		{
			MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::DAY_OF_WEEK, day_of_week);
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::DAY) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::DAY_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::DAY_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::DAY_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::DAY, MOONG::StringTool::format(format, system_time.wDay));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::DAY, MOONG::ConvertDataType::toString(system_time.wDay));
			}
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::HOUR) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::HOUR_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::HOUR_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::HOUR_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::HOUR, MOONG::StringTool::format(format, system_time.wHour));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::HOUR, MOONG::ConvertDataType::toString(system_time.wHour));
			}
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::MINUTE) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::MINUTE_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MINUTE, MOONG::StringTool::format(format, system_time.wMinute));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MINUTE, MOONG::ConvertDataType::toString(system_time.wMinute));
			}
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::MILLISECONDS) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::MILLISECONDS_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::MILLISECONDS_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::MILLISECONDS_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::MILLISECONDS_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MILLISECONDS, MOONG::StringTool::format(format, system_time.wMilliseconds));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::MILLISECONDS, MOONG::ConvertDataType::toString(system_time.wMilliseconds));
			}
		}

		if (output.find(MOONG::TIME::DATE_FORMAT::SECOND) != std::string::npos)
		{
			if (output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT) != std::string::npos)
			{
				size_t index_head = output.find(MOONG::TIME::DATE_FORMAT::SECOND_FORMAT);
				size_t index_tail = output.find(")", index_head);

				std::string format = output.substr(index_head + MOONG::TIME::DATE_FORMAT::SECOND_FORMAT.length(), index_tail - (index_head + MOONG::TIME::DATE_FORMAT::SECOND_FORMAT.length()));

				output.replace(index_head, (index_tail - index_head) + 1, "");

				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::SECOND, MOONG::StringTool::format(format, system_time.wSecond));
			}
			else
			{
				MOONG::StringTool::replace(output, MOONG::TIME::DATE_FORMAT::SECOND, MOONG::ConvertDataType::toString(system_time.wSecond));
			}
		}
	}

	return output;
}

const std::string MOONG::Time::make_time_taken_format(unsigned __int64 param_milliseconds)
{
	if (0 == param_milliseconds)
	{
		return std::string("0밀리초");
	}

	const unsigned __int64 milliseconds_equal_to_second = 1000;
	const unsigned __int64 milliseconds_equal_to_minute = milliseconds_equal_to_second * 60;
	const unsigned __int64 milliseconds_equal_to_hour = milliseconds_equal_to_minute * 60;
	const unsigned __int64 milliseconds_equal_to_day = milliseconds_equal_to_hour * 24;

	unsigned int day = static_cast<unsigned int>(param_milliseconds / milliseconds_equal_to_day);
	param_milliseconds %= milliseconds_equal_to_day;

	unsigned int hour = static_cast<unsigned int>(param_milliseconds / milliseconds_equal_to_hour);
	param_milliseconds %= milliseconds_equal_to_hour;

	unsigned int minute = static_cast<unsigned int>(param_milliseconds / milliseconds_equal_to_minute);
	param_milliseconds %= milliseconds_equal_to_minute;

	unsigned int second = static_cast<unsigned int>(param_milliseconds / milliseconds_equal_to_second);
	param_milliseconds %= milliseconds_equal_to_second;

	unsigned int milliseconds = static_cast<unsigned int>(param_milliseconds);

	std::string output = "";

	if (day > 0)
	{
		output = MOONG::StringTool::format("%d일", day);
	}

	if (hour > 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d시간", hour);
	}

	if (minute > 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d분", minute);
	}

	if (second > 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d초", second);
	}

	if (milliseconds > 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d밀리초", milliseconds);
	}

	return output;
}

const std::string MOONG::Time::make_time_taken_format(const SYSTEMTIME system_time)
{
	std::string output = "";

	if (system_time.wYear != 0)
	{
		output = MOONG::StringTool::format("%d년", system_time.wYear);
	}
	
	if (system_time.wMonth != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d개월", system_time.wMonth);
	}

	if (system_time.wDay != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d일", system_time.wDay);
	}

	if (system_time.wHour != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d시간", system_time.wHour);
	}

	if (system_time.wMinute != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d분", system_time.wMinute);
	}

	if (system_time.wSecond != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d초", system_time.wSecond);
	}

	if (system_time.wMilliseconds != 0)
	{
		if (output.length() > 0)
		{
			output += " ";
		}

		output += MOONG::StringTool::format("%d밀리초", system_time.wMilliseconds);
	}

	return output;
}

const unsigned __int64 MOONG::Time::get_time_diff_in_milliseconds_(const SYSTEMTIME& start_time, const SYSTEMTIME& end_time)
{
	FILETIME file_time_1 = { 0 }, file_time_2 = { 0 };
	ULARGE_INTEGER ul1 = { 0 }, ul2 = { 0 };

	SystemTimeToFileTime(&start_time, &file_time_1);
	SystemTimeToFileTime(&end_time, &file_time_2);

	ul1.LowPart = file_time_1.dwLowDateTime;
	ul1.HighPart = file_time_1.dwHighDateTime;

	ul2.LowPart = file_time_2.dwLowDateTime;
	ul2.HighPart = file_time_2.dwHighDateTime;
	
	return (ul2.QuadPart - ul1.QuadPart) < 0 ? (((ul2.QuadPart - ul1.QuadPart) * -1) / 10000) : ((ul2.QuadPart - ul1.QuadPart) / 10000);
}
