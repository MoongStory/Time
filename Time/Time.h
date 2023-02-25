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
		// year, month, day, day_of_week, hour, minute, second, milli_seconds를 해당하는 값으로 치환.
		// format sample
		//		"year년 month월 day일 day_of_week hour시 minute분 second초 milli_seconds밀리초" -> "2023년 02월 24일(금요일) 14시 34분 43초 123밀리초"
		//		"YEAR년 month(format:02)월 day(format:03)일(day_of_week) HOUR(FORMAT:04)시 minute(foRMat:05)분 second(format:06)초 MILLI_SECONDS(format:07)밀리초" -> "2023년 02월 024일(금요일) 0014시 00034분 000043초 0000123밀리초"
		//			foramt:(형식), 여기에서 형식은 출력시 "%d"에서 '%'와 'd' 사이에 들어갈 형식이다.
		static const std::string get_current_time(std::string date_format = "");

		static const std::string second_to_date(unsigned long param_second);

		static const SYSTEMTIME calculate_difference_between_times(SYSTEMTIME start_time, SYSTEMTIME end_time);
	protected:
	private:
		static const std::string make_date_format_(SYSTEMTIME system_time, std::string date_format = "");
		
		static const unsigned long long get_time_diff_in_milliseconds(const SYSTEMTIME& start_time, const SYSTEMTIME& end_time);
	};
}
#endif	// _TIME_H_
