#include "ContactList.h"



bool ContactList::compareContact(Contact a, Contact b)
{
	if (a.getFirstName()[0] < b.getFirstName()[0]) {
		return true;
	}
	else if (a.getFirstName()[0] == (b.getFirstName()[0])) {
		if (a.getLastName()[0] < b.getLastName()[0]) {
			return true;
		}
	}
	return false;
}

ContactList::ContactList()
{
}


ContactList::~ContactList()
{
}

//void ContactList::orderContactList()
//{
//	sort(_contactList.begin(), _contactList.end(), ContactList::compareContact);
//}

void ContactList::fillFromFile()
{
	ifstream fin;
	fin.open("FakeNames.csv");
	while (!fin.eof()) {
		string contactLine = "";
		getline(fin, contactLine);
		Contact newContact = Contact(contactLine);
		_contactList.push_back(newContact);
	}
}

vector<Contact> ContactList::searchByLastName(string lastName)
{
	vector<Contact> lastNameMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (lastName.compare(it->getLastName())) {
			Contact matchingContact = Contact(it->toString());
			lastNameMatches.push_back(matchingContact);
		}
	}
	return lastNameMatches;
}

vector<Contact> ContactList::searchByFirstName(string firstName)
{
	vector<Contact> firstNameMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (firstName.compare(it->getFirstName())) {
			Contact matchingContact = Contact(it->toString());
			firstNameMatches.push_back(matchingContact);
		}
	}
	return firstNameMatches;
}

vector<Contact> ContactList::searchByCity(string city)
{
	vector<Contact> cityMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (city.compare(it->getLastName())) {
			Contact matchingContact = Contact(it->toString());
			cityMatches.push_back(matchingContact);
		}
	}
	return cityMatches;
}

void ContactList::deleteContactByLastName(string lastName)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (lastName.compare(it->getLastName())) {
			_contactList.erase(it);
		}
	}
}

void ContactList::deleteContactByFirstName(string firstName)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (firstName.compare(it->getFirstName())) {
			_contactList.erase(it);
		}
	}
}

void ContactList::deleteContactByCity(string city)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (city.compare(it->getLastName())) {
			_contactList.erase(it);
		}
	}
}

void ContactList::deleteContact(string contactLine)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (contactLine.compare(it->toString())) {
			_contactList.erase(it);
		}
	}
}

void ContactList::deleteAllContacts()
{
	_contactList.clear();
}

void ContactList::addContact()
{
}

bool ContactList::isEmpty()
{
	return _contactList.empty() ? true : false;
}
