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

void ContactList::fillFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	string contactLine = "";
	getline(fin, contactLine);	
	while (!fin.eof()) {
		getline(fin, contactLine);
		Contact newContact = Contact(contactLine);
		_contactList.push_back(newContact);		
	}
	fin.close();
}

vector<Contact> ContactList::searchByLastName(string lastName)
{
	vector<Contact> lastNameMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (lastName == (it->getLastName())) {
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
		if (firstName == (it->getFirstName())) {
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
		if (city == (it->getLastName())) {
			Contact matchingContact = Contact(it->toString());
			cityMatches.push_back(matchingContact);
		}
	}
	return cityMatches;
}

void ContactList::deleteContactByLastName(string lastName)
{
	vector<Contact> newContactList;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (lastName != (it->getLastName())) {
			Contact copyContact = Contact(it->toString());
			newContactList.push_back(copyContact);
		}
	}
	_contactList = newContactList;
}

void ContactList::deleteContactByFirstName(string firstName)
{
	//Test
	cout << "Entering delete: " << firstName << endl;


	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		
		//Test
		cout << firstName << "\tlistName : " << it->getFirstName() << endl;
		
		
		if (firstName == (it->getFirstName())) {
			
			//Test
			cout << "Name to be deleted : " << it->toString() << endl;

			_contactList.erase(it);
		}
	}
}

void ContactList::deleteContactByCity(string city)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (city == (it->getLastName())) {
			_contactList.erase(it);
		}
	}
}

void ContactList::deleteContact(string contactLine)
{
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (contactLine == (it->toString())) {
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

void ContactList::testCode()
{
	cout << "Current List" << endl;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		cout << "1." << it->toString() << endl;
	}
}

