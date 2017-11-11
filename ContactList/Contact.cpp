#include <string>
#include <iostream>
#include "Contact.h"
#include "Date.h"

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
	Date birthday = Date(birthday);
}
string Contact::getBirthday() {
	return _birthday.getDate();
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

Contact::Contact() {

}

Contact::Contact(string contactLine)
{
	if (contactLine[0] >= '0' && contactLine[0] <= '9') {
		contactLine.erase(0, contactLine.find(',') + 1);
	}

	int fieldNumber = 0;
	size_t pos = 0;
	string token;
	while ((pos = contactLine.find(',')) != string::npos) {
		token = contactLine.substr(0, pos);
		switch (fieldNumber) {
		case 0: setGender(token);
			break;
		case 1: setTitle(token);
			break;
		case 2: setFirstName(token);
			break;
		case 3: setMiddleInitial(token);
			break;
		case 4: setLastName(token);
			break;
		case 5: setStreetAddress(token);
			break;
		case 6: setCity(token);
			break;
		case 7: setState(token);
			break;
		case 8: setZipCode(token);
			break;
		case 9: setEmailAddress(token);
			break;
		case 10: setBirthday(token);
		default: cout << "Invalid field detected" << endl;
			break;
		}
		contactLine.erase(0, pos + 1);
	}
}


Contact::~Contact()
{
}
