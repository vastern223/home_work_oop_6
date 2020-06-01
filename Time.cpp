#include "Time.h"

bool Time::Time_check(int hour, int minute, int second)const
{
	if (hour >= 0 && hour < HOUR)
	{
		if (minute >= 0 && minute < MINUTE)
		{
			if (second >= 0 && second < SECOND)
			{
				return true;
			}
		}
	}
}

void Time::Time_plus_check(int& hour, int& minute, int& second)
{
	while (second >= SECOND)
	{
		minute++;
		second -= SECOND;

	}
	while (minute >= MINUTE)
	{
		hour++;
		minute -= MINUTE;
	}
}

void Time::Time_minus_check(int& hour, int& minute, int& second)
{
	while (second < 0)
	{
		minute--;
		second += SECOND;

	}
	while (minute < 0)
	{
		hour--;
		minute += MINUTE;
	}
}

Time::Time() :hour(0), minute(0), second(0) {}

Time::Time(int hour, int minute, int second) : Time()
{
	if (Time_check(hour, minute, second))
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
}
Time::Time(int second)
{
	this->hour = second / SECOND_IN_HOUR;
	this->minute = (second - hour * SECOND_IN_HOUR) / MINUTE;
	this->second = second - hour * SECOND_IN_HOUR - minute * SECOND;
}
void Time::Print_Time()const
{
	cout << "Time: " << hour << ":" << minute << ":" << second << endl;
}
void Time::Plus_second()
{
	second++;
	Time_plus_check(this->hour, this->minute, this->second);
}

Time Time :: operator+(const Time& other)
{
	int _hour = this->hour + other.hour;
	int _minute = this->minute + other.minute;
	int _second = this->second + other.second;
	Time_plus_check(_hour, _minute, _second);
	return Time(_hour, _minute, _second);
}
Time Time :: operator-(const Time& other)
{
	int _hour = this->hour - other.hour;
	int _minute = this->minute - other.minute;
	int _second = this->second - other.second;
	Time_minus_check(_hour, _minute, _second);
	return Time(_hour, _minute, _second);
}
Time Time :: operator/(const Time& other)
{
	return Time(this->hour / other.hour, this->minute / other.minute, this->second / other.second);
}
Time Time :: operator*(const Time& other)
{
	int _hour = this->hour * other.hour;
	int _minute = this->minute * other.minute;
	int _second = this->second * other.second;
	Time_plus_check(_hour, _minute, _second);
	return Time(_hour, _minute, _second);
}
bool Time :: operator>(const Time& other)const
{
	return ((this->hour * SECOND_IN_HOUR + this->minute * MINUTE + this->second) > (other.hour * SECOND_IN_HOUR + other.minute * MINUTE + other.second));
}
bool Time :: operator<(const Time& other)const
{
	return (other > * this);
}
bool Time :: operator>=(const Time& other)const
{
	return !(other > * this) || (!(other > * this) && !(*this > other));
}
bool Time :: operator<=(const Time& other)const
{
	return (other > * this) || (!(other > * this) && !(*this > other));
}
bool Time :: operator==(const Time& other)const
{
	return (!(other > * this) && !(*this > other));
}
bool Time :: operator!=(const Time& other)const
{
	return ((other > * this) || (*this > other));
}