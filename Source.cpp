#include<iostream>
#include "Time.h"
#include "String.h"

using namespace std;



int main()
{
	String t1("vas2103");
	String t2("vasa2301");
	String t3 = t1 * t2;
	t3.Print();
	String t4 = t1 + t2;
	t4.Print();
	t4+=t2;
	t4.Print();
	system("pause");
	return 0;
}