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

	void searchByLastName();

	void searchByFirstName();

	void searchByCity();

	void deleteContact();

	void deleteAllContacts();

	void addContact();

};

