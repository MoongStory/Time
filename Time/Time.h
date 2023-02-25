// https://github.com/MoongStory/Time

#if _MSC_VER > 1000
	#pragma once
#endif

#ifndef _TIME_H_
#define _TIME_H_

#include <string>

namespace MOONG
{
	namespace TIME
	{
		namespace DATE_FORMAT
		{
			static const std::string YEAR = "year";

			static const std::string MONTH_FORMAT = "month(format";
			static const std::string MONTH = "month";

			static const std::string DAY_FORMAT = "day(format";
			static const std::string DAY = "day";

			static const std::string DAY_OF_WEEK = "day_of_week";

			static const std::string HOUR_FORMAT = "hour(format";
			static const std::string HOUR = "hour";

			static const std::string MINUTE_FORMAT = "minute(format";
			static const std::string MINUTE = "minute";

			static const std::string SECOND_FORMAT = "second(format";
			static const std::string SECOND = "second";

			static const std::string MILLI_SECONDS_FORMAT = "milli_seconds(format";
			static const std::string MILLI_SECONDS = "milli_seconds";
		}
	}

	class Time
	{
	public:
	protected:
	private:

	public:
		// year, month, day, day_of_week, hour, minute, second, milli_seconds�� �ش��ϴ� ������ ġȯ.
		// format sample
		//		"year�� month�� day�� day_of_week hour�� minute�� second�� milli_seconds�и���" -> "2023�� 02�� 24�� �ݿ��� 14�� 34�� 43�� 123�и���"
		static const std::string get_current_time(std::string date_format = "");

		static const std::string seconds_to_date(unsigned long seconds);
	protected:
	private:
	};
}
#endif	// _TIME_H_