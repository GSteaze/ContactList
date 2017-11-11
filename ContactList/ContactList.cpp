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

void ContactList::orderContactList()
{
	sort(_contactList.begin(), _contactList.end(), compareContact);
}

void ContactList::fillFromFile()
{
	ifstream fin;
	fin.open("FakeNames.csv");
	while (!fin.eof()) {
		string contactLine = "";
		fin.getline(contactLine, '\n');
		Contact newContact = Contact(contactLine);
		_contactList.push_back(newContact);
	}
}

vector<Contact> ContactList::searchByLastName(string lastName)
{
	vector<Contact> _lastNameMatches;
	for (vector<Contact>::iterator it = _contactList.begin; it != _contactList.end(); it++) {
		if (lastName.compare(it->getLastName())) {
			Contact matchingContact = Contact(it->toString());
			_lastNameMatches.push_back(matchingContact);
		}
	}
	return _lastNameMatches;
}

vector<Contact> ContactList::searchByFirstName(string firstName)
{
	vector<Contact> _firstNameMatches;
	for (vector<Contact>::iterator it = _contactList.begin; it != _contactList.end(); it++) {
		if (firstName.compare(it->getFirstName())) {
			Contact matchingContact = Contact(it->toString());
			_firstNameMatches.push_back(matchingContact);
		}
	}
	return _firstNameMatches;
}

vector<Contact> ContactList::searchByCity(string city)
{
	vector<Contact> _cityMatches;
	for (vector<Contact>::iterator it = _contactList.begin; it != _contactList.end(); it++) {
		if (city.compare(it->getLastName())) {
			Contact matchingContact = Contact(it->toString());
			_cityMatches.push_back(matchingContact);
		}
	}
	return _cityMatches;
}

void ContactList::deleteContact(string contactInfo)
{
}

void ContactList::deleteAllContacts()
{
	_contactList.clear();
}

void ContactList::addContact()
{
}
