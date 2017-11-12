#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Contact.h"
#include "ContactList.h"

class MenuIO
{
private:
	ContactList _contactList = ContactList();
	
	const int kEndOfLine = 1024;
	const int kMenuOptionMinimum = 1;
	const int kMenuOptionMaximum = 5;
	const int kSearchOptionMinimum = 1;
	const int kSearchOptionMaximum = 6;

public:
	MenuIO();
	~MenuIO();

	void displayWelcomeMessage();

	void displayMenu();

	bool loadContacts();

	vector<Contact> findContact();

	void deleteContact();

	void clearContacts();

	int intValidator(int min, int max);

	string stringValidator(string desiredField);

};

