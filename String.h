#pragma once
#include<iostream>
using namespace std;

class String
{
	char* str;
	int length;

public:

	String();

	explicit String(int count, char symbol);
	
	explicit String(const char* str);
	
	String(const String& other);
	
	void Append(const char* str);

	void Print()const;

	void operator+=(const char* str);

	void operator+=(const String& str);
	
	String operator+(const String& str) const;

	String operator*(const String& str)const;
		
	bool operator==(const String& str);
	
	bool operator!=(const String& str);
	
	bool  operator>(const String& str);
	
	bool  operator<(const String& str);
	
	~String();
	
	

};


