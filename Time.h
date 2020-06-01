#pragma once
#include<iostream>
using namespace std;

enum Time_second { HOUR = 24, MINUTE = 60, SECOND = 60, SECOND_IN_HOUR = 3600 };

class Time
{
private:
	int hour;
	int minute;
	int second;

	bool Time_check(int hour, int minute, int second)const;
	void Time_plus_check(int& hour, int& minute, int& second);
	void Time_minus_check(int& hour, int& minute, int& second);

public:

	Time();

	Time(int hour, int minute, int second);

	explicit Time(int seconds);

	void Print_Time()const;

	void Plus_second();

	Time operator+(const Time& other);

	Time operator-(const Time& other);

	Time operator/(const Time& other);

	Time operator*(const Time& other);

	bool operator>(const Time& other)const;

	bool operator<(const Time& other)const;

	bool operator>=(const Time& other)const;

	bool operator<=(const Time& other)const;

	bool operator==(const Time& other)const;

	bool operator!=(const Time& other)const;


};

