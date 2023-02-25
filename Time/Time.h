// https://github.com/MoongStory/Time

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_H_
#define _TIME_H_

#include <string>
#include <wtypes.h>

namespace MOONG
{
	namespace TIME
	{
		namespace DATE_FORMAT
		{
			static const std::string YEAR = "year";

			static const std::string MONTH_FORMAT = "(month_format:";
			static const std::string MONTH = "month";

			static const std::string DAY_FORMAT = "(day_format:";
			static const std::string DAY = "day";

			static const std::string DAY_OF_WEEK = "day_of_week";

			static const std::string HOUR_FORMAT = "(hour_format:";
			static const std::string HOUR = "hour";

			static const std::string MINUTE_FORMAT = "(minute_format:";
			static const std::string MINUTE = "minute";

			static const std::string SECOND_FORMAT = "(second_format:";
			static const std::string SECOND = "second";

			static const std::string MILLISECONDS_FORMAT = "(milliseconds_format:";
			static const std::string MILLISECONDS = "milliseconds";
		}
	}

	class Time
	{
	public:
	protected:
	private:

	public:
		// year, month, day, day_of_week, hour, minute, second, milliseconds�� �ش��ϴ� ������ ġȯ.
		// format sample
		//		"year�� month�� day�� day_of_week hour�� minute�� second�� milli_seconds�и���" -> "2023�� 02�� 24��(��) 14�� 34�� 43�� 123�и���"
		//		"year�� month(month_format:%02d)�� day(day_format:%02d)��(day_of_week) hour(hour_format:%02d)�� minute(minute_format:%02d)�� second(second_format:%02d)�� milliseconds(milliseconds_format:%03d)�и���" -> "2023�� 02�� 24��(��) 14�� 34�� 43�� 123�и���"
		//		"year�� month�� day��(day_of_week) hour�� minute�� second�� milliseconds(month_format:%02d)(day_format:%02d)(hour_format:%02d)(minute_format:%02d)(second_format:%02d)(milliseconds_format:%03d)�и���" -> "2023�� 02�� 24��(��) 14�� 34�� 43�� 123�и���"
		static const SYSTEMTIME get_current_time();

		static const std::string second_to_date(unsigned long param_second);

		static const SYSTEMTIME calculate_difference_between_times(SYSTEMTIME start_time, SYSTEMTIME end_time);

		static const std::string make_date_format(SYSTEMTIME system_time, std::string date_format = "");
	protected:
	private:
		
		static const unsigned long long get_time_diff_in_milliseconds_(const SYSTEMTIME& start_time, const SYSTEMTIME& end_time);
	};
}
#endif	// _TIME_H_
