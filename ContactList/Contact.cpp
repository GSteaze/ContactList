#include <string>
#include <iostream>
#include "Contact.h"
#include "Date.h"

void Contact::setGender(string gender) {
	_gender = gender;
}
string Contact::getGender() {
}

void Contact::setTitle(string title) {
	_title = title;
}
string Contact::getTitle() {
}

void Contact::setFirstName(string firstName) {
	_firstName = firstName;
}
string Contact::getFirstName() {
}

void Contact::setMiddleInitial(string middleInitial) {
	_middleInitial = middleInitial;
}
string Contact::getMiddleInitial() {
}

void Contact::setLastName(string lastName) {
	_lastName = lastName;
}
string Contact::getLastName() {
}

void Contact::setStreetAddress(string streetAddress) {
	_streetAddress = streetAddress;
}
string Contact::getStreetAddress() {
}

void Contact::setCity(string city) {
	_city = city;
}
string Contact::getCity() {
}

void Contact::setState(string state) {
	_state = state;
}
string Contact::getState() {
}

void Contact::setZipCode(string zipCode) {
	_zipCode = zipCode;
}
string Contact::getZipCode() {
}

void Contact::setEmailAddress(string emailAddress) {
	_emailAddress = emailAddress;
}
string Contact::getEmailAddress() {

}

void Contact::setBirthday(string birthday) {
	Date birthday = Date(birthday);
}
string Contact::getBirthday() {
}

Contact::Contact() {

}

Contact::Contact(string contactLine)
{
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
