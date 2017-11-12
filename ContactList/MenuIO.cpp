#include "MenuIO.h"



MenuIO::MenuIO()
{
	displayWelcomeMessage();
	displayMenu();
}


MenuIO::~MenuIO()
{
}

void MenuIO::displayWelcomeMessage()
{
	cout << "Contact List" << endl;
}

void MenuIO::displayMenu()
{
	bool isAgain = true;
	while (isAgain) {
		cout << endl << "Menu" << endl;
		cout << "1. Load Contacts" << endl
			<< "2. Search Contacts" << endl
			<< "3. Delete Contact(s)" << endl
			<< "4. Delete All Contacts" << endl
			<< "5. Exit Program" << endl;

		int userSelection = intValidator(kMenuOptionMinimum, kMenuOptionMaximum);
		vector<Contact> searchResults;
		bool isSuccessful = false;
		int counter = 0;
		switch (userSelection) {
		case 1: cout << "Loading Contacts..." << endl;
			isSuccessful = loadContacts();
			if (isSuccessful) {
				cout << "Contacts Loaded." << endl;
			}
			else {
				cout << "Contacts not found." << endl;
			}
			break;
		case 2:searchResults = findContact();
			if (!searchResults.empty()) {
				cout << "Matches Found : " << endl;
				for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
					counter++;
					cout << counter << ". " << it->getFullName() << endl;
				}
			}
			break;
		case 3: deleteContact();
			break;
		case 4: cout << "Closing Program." << endl;
			isAgain = false;
			break;
		default: cout << "Invalid Selection." << endl;
		}
	}
	
}

bool MenuIO::loadContacts()
{
	_contactList.fillFromFile();
	return _contactList.isEmpty() ? false : true;
}

vector<Contact> MenuIO::findContact()
{
	bool isFound = false;

	cout << "Search by : " << endl
		<< "1. Last Name" << endl
		<< "2. First Name" << endl
		<< "3. City of Residence" << endl << endl
		<< "Enter a number between" << kSearchOptionMinimum << " and " << kSearchOptionMaximum << " : ";
		int userSelection = intValidator(kSearchOptionMinimum, kMenuOptionMaximum);

		vector<Contact> searchResults;
		string searchCriteria = "";
		switch (userSelection) {
		case 1: searchCriteria = stringValidator("last name");
			searchResults = _contactList.searchByLastName(searchCriteria);
			break;
		case 2: searchCriteria = stringValidator("first name");
			searchResults = _contactList.searchByFirstName(searchCriteria);
			break;
		case 3: searchCriteria = stringValidator("city of residence");
			searchResults = _contactList.searchByCity(searchCriteria);
			break;
		default: cout << "Invalid selection" << endl;
		}

		if (!isFound) {
			cout << "No matches found." << endl;
		}

		return searchResults;
}

void MenuIO::deleteContact()
{
	vector<Contact> searchResults = findContact();
	bool isFound = !searchResults.empty();
	int counter = 0;
	if (isFound) {
		cout << "Matches Found : " << endl;
		for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
			counter++;
			cout << counter << ". " << it->getFullName() << endl;
		}
		cout << endl << "Would you like to delete these contacts?" << endl;
		string userSelection = stringValidator("'Y' or 'N'");
		if (userSelection.compare("Y") || userSelection.compare("y")) {
			for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
				_contactList.deleteContact(it->toString());
			}
		}
		else {
			cout << "No contacts deleted." << endl;
		}
	}
	else {
		cout << "No matches found." << endl;
	}
}

void MenuIO::clearContacts()
{
	_contactList.deleteAllContacts();
}

int MenuIO::intValidator(int min, int max)
{
	cout << "Please enter a number between " << min << " and " << max << " : ";
	int userInput = 0;
	bool isValidInput = false;
	while (!isValidInput) {
		cin >> userInput;
		if (cin.fail() || userInput < min || userInput > max) {
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
		}
		else if (userInput >= min && userInput <= max) {
			isValidInput = true;
		}
	}
	return userInput;
}

string MenuIO::stringValidator(string desiredField)
{
	cout << "Please enter " << desiredField << " : ";
	string userInput = "";
	bool isValidInput = false;
	while (!isValidInput) {
		cin.clear();
		getline(cin, userInput);
		if (cin.fail() || userInput.empty()) {
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
		}
		else {
			isValidInput = true;
		}
	}
	return userInput;
}
