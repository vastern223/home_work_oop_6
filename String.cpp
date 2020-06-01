#include "String.h"


String::String() : length(0), str(nullptr){ }

String::String(int count, char symbol) : length(count)
{
	str = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		str[i] = symbol;
	}
	str[length] = 0;
}

String::String(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}

String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);
}

void String:: Print()const
{
	cout << str << endl;
}

void String:: Append(const char* str)
{
	int size = this->length + strlen(str) + 1;
	char* newStr = new char[size];
	strcpy_s(newStr, size, this->str);
	strcat_s(newStr, size, str);

	delete[]this->str;
	this->str = newStr;
	this->length = size - 1;
}

void String:: operator+=(const char* str)
{
	int size = this->length + strlen(str) + 1;
	char* newStr = new char[size];
	strcpy_s(newStr, size, this->str);
	strcat_s(newStr, size, str);

	delete[]this->str;
	this->str = newStr;
	this->length = size - 1;
}

void String:: operator+=(const String& str)
{
	int size = strlen(this->str) + strlen(str.str);
	char* newStr = new char[size + 1];
	strcpy_s(newStr, size + 1, this->str);
	strcat_s(newStr, size + 1, str.str);

	delete[]this->str;
	this->str = newStr;
	this->length = size + 1;
}

String String:: operator+(const String& str) const
{
	String res(*this);
	res += str;
	return res;
}

String String:: operator*(const String& str)const
{
	int count = 0;
	char* temp = new char[count + 1];

	for (int i = 0; i < strlen(this->str); i++)
	{
		for (int j = 0; j < strlen(str.str); j++)
		{
			if (this->str[i] == str.str[j])
			{
				char* temp2 = new char[count + 1];
				for (int k = 0; k < count; k++)
				{
					temp2[k] = temp[k];
				}
				temp2[count] = this->str[i];
				delete[]temp;
				temp = temp2;
				count++;
				break;
			}
		}
	}
	temp[count] = 0;
	return String(temp);
}

bool String:: operator==(const String& str)
{
	return (strcmp(this->str, str.str) == 0);
}

bool String:: operator!=(const String& str)
{
	return(strcmp(this->str, str.str) != 0);

}

bool String::  operator>(const String& str)
{
	return(strcmp(this->str, str.str) > 0);
}

bool String::  operator<(const String& str)
{
	return(strcmp(this->str, str.str) < 0);
}

 String::~String()
{
	if (str != nullptr)
		delete[]str;
}