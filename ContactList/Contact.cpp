#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.h"
//#include "Date.h"

void Contact::setGender(string gender) {
	_gender = gender;
}
string Contact::getGender() {
	return _gender;
}

void Contact::setTitle(string title) {
	_title = title;
}
string Contact::getTitle() {
	return _title;
}

void Contact::setFirstName(string firstName) {
	_firstName = firstName;
}
string Contact::getFirstName() {
	return _firstName;
}

void Contact::setMiddleInitial(string middleInitial) {
	_middleInitial = middleInitial;
}
string Contact::getMiddleInitial() {
	return _middleInitial;
}

void Contact::setLastName(string lastName) {
	_lastName = lastName;
}
string Contact::getLastName() {
	return _lastName;
}

void Contact::setStreetAddress(string streetAddress) {
	_streetAddress = streetAddress;
}
string Contact::getStreetAddress() {
	return _streetAddress;
}

void Contact::setCity(string city) {
	_city = city;
}
string Contact::getCity() {
	return _city;
}

void Contact::setState(string state) {
	_state = state;
}
string Contact::getState() {
	return _state;
}

void Contact::setZipCode(string zipCode) {
	_zipCode = zipCode;
}
string Contact::getZipCode() {
	return _zipCode;
}

void Contact::setEmailAddress(string emailAddress) {
	_emailAddress = emailAddress;
}
string Contact::getEmailAddress() {
	return _emailAddress;

}

void Contact::setBirthday(string birthday) {
	_birthday = birthday;
	//_birthday = Date(birthday);
}
string Contact::getBirthday() {
	return _birthday;
	//return _birthday.getDate();
}

string Contact::getFullName()
{
	string fullName = "";
	fullName.append(getFirstName());
	fullName.append(" ");
	fullName.append(getMiddleInitial());
	fullName.append(" ");
	fullName.append(getLastName());
	return fullName;
}

string Contact::toString() {
	string newString = "";
	newString.append(getGender());
	newString.append(", ");
	newString.append(getTitle());
	newString.append(", ");
	newString.append(getFirstName());
	newString.append(", ");
	newString.append(getMiddleInitial());
	newString.append(", ");
	newString.append(getLastName());
	newString.append(", ");
	newString.append(getStreetAddress());
	newString.append(", ");
	newString.append(getCity());
	newString.append(", ");
	newString.append(getState());
	newString.append(", ");
	newString.append(getZipCode());
	newString.append(", ");
	newString.append(getEmailAddress());
	newString.append(", ");
	newString.append(getBirthday());
	
	return newString;

}

void Contact::setBirthdayValues()
{
	string tempLine = _birthday;
	string token = "";
	int fieldNumber = 0;
	char delimiter = '/';
	int numberOfFields = 3;
	int start = 0;
	int end = tempLine.find(delimiter);
	int fieldsOfBirthday[3];

	while (end != string::npos) {
		token = tempLine.substr(start, (end - start));
		fieldsOfBirthday[fieldNumber] = stoi(token);
		fieldNumber++;
		start = end + 1;
		end = tempLine.find(delimiter, start);
	}
	token = tempLine.substr(start, (end - start));
	fieldsOfBirthday[fieldNumber] = stoi(token);

	for (int index = 0; index < numberOfFields; index++) {
		switch (index) {
		case 0: _birthMonth = fieldsOfBirthday[index];
			break;
		case 1: _birthDayOfTheMonth = fieldsOfBirthday[index];
			break;
		case 2: _birthYear = fieldsOfBirthday[index];
			break;
		default: cout << "Invalid field detected" << endl;
			break;
		}

	}
	setAge();
}

void Contact::setAge() {
	int currentDay = 12;
	int currentMonth = 11;
	int currentYear = 2017;

	//auto t = std::time(nullptr);
	//auto tm = *std::localtime(&t);

	//std::ostringstream oss;
	//oss << std::put_time(&tm, "%d-%m-%Y");
	//auto str = oss.str();

	//string tempLine = str;
	//string token = "";
	//int fieldNumber = 0;
	//char delimiter = '/';
	//int numberOfFields = 3;
	//int start = 0;
	//int end = tempLine.find(delimiter);
	//int fieldsOfBirthday[3];

	//while (end != string::npos) {
	//	token = tempLine.substr(start, (end - start));
	//	fieldsOfBirthday[fieldNumber] = stoi(token);
	//	fieldNumber++;
	//	start = end + 1;
	//	end = tempLine.find(delimiter, start);
	//}
	//token = tempLine.substr(start, (end - start));
	//fieldsOfBirthday[fieldNumber] = stoi(token);

	//for (int index = 0; index < numberOfFields; index++) {
	//	switch (index) {
	//	case 0: currentMonth = fieldsOfBirthday[index];
	//		break;
	//	case 1: currentDay = fieldsOfBirthday[index];
	//		break;
	//	case 2: currentYear = fieldsOfBirthday[index];
	//		break;
	//	default: cout << "Invalid field detected" << endl;
	//		break;
	//	}

	//}

	int age = currentYear - _birthYear;
	_age = age;
}

int Contact::getAge()
{
	return _age;
}

int Contact::getMonth()
{
	return _birthMonth;
}

int Contact::getYear()
{
	return _birthYear;
}

int Contact::getDayOfTheMonth()
{
	return _birthDayOfTheMonth;
}

Contact::Contact() {

}

Contact::Contact(string contactLine)
{
	string tempLine = contactLine;
	string token = "";
	int fieldNumber = 0;
	char delimiter = ',';
	int numberOfFields = 11;
	int start = 0;
	int end = tempLine.find(delimiter);
	if (tempLine[0] >= '0' && tempLine[0] <= '9') {
		start = tempLine.find(delimiter) + 1;
		end = tempLine.find(delimiter, start);
	}
	while (end != string::npos) {
		token = tempLine.substr(start, (end - start));
		_fieldsOfContact[fieldNumber] = token;
		fieldNumber++;
		start = end + 1;
		end = tempLine.find(delimiter, start);
	}
	token = tempLine.substr(start, (end - start));
	_fieldsOfContact[fieldNumber] = token;

	for (int index = 0; index < numberOfFields; index++) {
		switch (index) {
		case 0: setGender(_fieldsOfContact[index]);
			break;
		case 1: setTitle(_fieldsOfContact[index]);
			break;
		case 2: setFirstName(_fieldsOfContact[index]);
			break;
		case 3: setMiddleInitial(_fieldsOfContact[index]);
			break;
		case 4: setLastName(_fieldsOfContact[index]);
			break;
		case 5: setStreetAddress(_fieldsOfContact[index]);
			break;
		case 6: setCity(_fieldsOfContact[index]);
			break;
		case 7: setState(_fieldsOfContact[index]);
			break;
		case 8: setZipCode(_fieldsOfContact[index]);
			break;
		case 9: setEmailAddress(_fieldsOfContact[index]);
			break;
		case 10: setBirthday(_fieldsOfContact[index]);
			//_birthday = Date(token);
			break;
		default: cout << "Invalid field detected" << endl;
			break;
		}
	}
	setBirthdayValues();
}


Contact::~Contact()
{
}
