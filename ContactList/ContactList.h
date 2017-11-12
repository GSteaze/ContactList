#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Contact.h"

using namespace std;

class ContactList
{
private:
	vector<Contact> _contactList;

	bool compareContact(Contact a, Contact b);

	

public:
	ContactList();
	~ContactList();

	void orderContactList();

	void fillFromFile(string);

	vector<Contact> searchByLastName(string);

	vector<Contact> searchByFirstName(string);

	vector<Contact> searchByCity(string);

	void deleteContactByLastName(string);

	void deleteContactByFirstName(string);

	void deleteContactByCity(string);

	void deleteContact(string);

	void deleteAllContacts();

	void addContact();

	bool isEmpty();

	void testCode();

};

