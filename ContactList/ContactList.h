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

	void fillFromFile();

	vector<Contact> searchByLastName(string);

	vector<Contact> searchByFirstName(string);

	vector<Contact> searchByCity(string);

	void deleteContact(string);

	void deleteAllContacts();

	void addContact();

};

