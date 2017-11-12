#pragma once
#include <string>
//#include "Date.h"

using namespace std;

class Contact
{
private:
	string _gender;
	string _title;
	string _firstName;
	string _middleInitial;
	string _lastName;
	string _streetAddress;
	string _city;
	string _state;
	string _zipCode;
	string _emailAddress;
	string _birthday;
	//Date _birthday;
	string _fieldsOfContact[12];

public:
	Contact();
	Contact(string contactLine);
	~Contact();

	void setGender(string);
	string getGender();

	void setTitle(string);
	string getTitle();

	void setFirstName(string);
	string getFirstName();

	void setMiddleInitial(string);
	string getMiddleInitial();

	void setLastName(string);
	string getLastName();

	void setStreetAddress(string);
	string getStreetAddress();

	void setCity(string);
	string getCity();

	void setState(string);
	string getState();

	void setZipCode(string);
	string getZipCode();

	void setEmailAddress(string);
	string getEmailAddress();

	void setBirthday(string);
	string getBirthday();

	string getFullName();

	string toString();

};

