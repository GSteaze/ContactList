#pragma once
#include <string>

using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;
	bool isNull;

public:
	Date();
	Date(string date);
	~Date();

	void setDay(int);
	int getDay();

	void setMonth(int);
	int getMonth();

	void setYear(int);
	int getYear();

	string getDate();

};

