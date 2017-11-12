#pragma once
#include <string>

using namespace std;

class Date
{
private:
	int _day;
	int _month;
	int _year;

public:
	Date();
	Date(string date);
	~Date();

	void setDay();
	int getDay();

	void setMonth();
	int getMonth();

	void setYear();
	int getYear();

	string getDate();

};

