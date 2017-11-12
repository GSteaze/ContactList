#include "ContactList.h"



bool ContactList::compareContact(Contact &a, Contact &b)
{
	bool isLessThan = false;
	if (a.getFirstName()[0] < b.getFirstName()[0]) {
		isLessThan = true;
	}
	else if (a.getFirstName()[0] == (b.getFirstName()[0])) {
		if (a.getLastName()[0] < b.getLastName()[0]) {
			isLessThan = true;
		}
	}
	return isLessThan;
}

ContactList::ContactList()
{
}


ContactList::~ContactList()
{
}

//I could not get the code to compile using this method
//void ContactList::orderContactList()
//{	
//	sort(_contactList.begin(), _contactList.end(), compareContact);
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
	//orderContactList();
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
		if (city == (it->getCity())) {
			Contact matchingContact = Contact(it->toString());
			cityMatches.push_back(matchingContact);
		}
	}
	return cityMatches;
}

vector<Contact> ContactList::searchByBirthMonth(int birthMonth)
{
	vector<Contact> monthMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (birthMonth == (it->getMonth())) {
			Contact matchingContact = Contact(it->toString());
			monthMatches.push_back(matchingContact);
		}
	}
	return monthMatches;
}

vector<Contact> ContactList::searchByBirthYear(int birthYear)
{
	vector<Contact> yearMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (birthYear == (it->getYear())) {
			Contact matchingContact = Contact(it->toString());
			yearMatches.push_back(matchingContact);
		}
	}
	return yearMatches;
}

vector<Contact> ContactList::searchByAge(int age)
{
	vector<Contact> ageMatches;
	for (vector<Contact>::iterator it = _contactList.begin(); it != _contactList.end(); it++) {
		if (age == (it->getAge())) {
			Contact matchingContact = Contact(it->toString());
			ageMatches.push_back(matchingContact);
		}
	}
	return ageMatches;
}

void ContactList::deleteContact(string lastName)
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

