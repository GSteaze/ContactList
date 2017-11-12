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
		cout << endl;
		vector<Contact> searchResults;
		bool isSuccessful = false;
		int counter = 0;
		string userYesOrNo = "";

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
				cout << endl << "Matches Found : " << endl;
				for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
					counter++;
					cout << counter << ". " << it->getFullName() << endl;
				}
			}
			break;
		case 3: deleteContact();
			break;
		case 4: cout << "Are you sure that you would like to delete these contacts?" << endl;
			userYesOrNo = stringValidator("'Y' or 'N'");
			if (userYesOrNo == "Y" || userYesOrNo == "y") {
				cout << "Deleting contacts..." << endl;
				clearContacts();
				cout << "Contacts cleared." << endl;
			}
			else {
				cout << "No contacts deleted." << endl;
			}
			break;
		case 5: cout << "Closing Program." << endl;
			isAgain = false;
			break;
		default: cout << "Invalid Selection." << endl;
		}
	}
	
}

bool MenuIO::loadContacts()
{
	_contactList.fillFromFile("FakeNames.csv");
	return _contactList.isEmpty() ? false : true;
}

vector<Contact> MenuIO::findContact()
{
	cout << "Search by : " << endl
		<< "1. Last Name" << endl
		<< "2. First Name" << endl
		<< "3. City of Residence" << endl
		<< "4. Birth Month" << endl
		<< "5. Birth Year" << endl
		<< "6. Age" << endl;
		int userSelection = intValidator(kSearchOptionMinimum, kSearchOptionMaximum);

		vector<Contact> searchResults;
		string searchCriteria = "";
		int searchCriteriaNumber = 0;
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
		case 4: searchCriteriaNumber = intValidator(0, 12);
			break;
		case 5: searchCriteriaNumber = intValidator(1817, 2017);
			break;
		case 6: searchCriteriaNumber = intValidator(0, 200);
			break;
		default: cout << "Invalid selection" << endl;
		}

		if (searchResults.empty()) {
			cout << "No matches found." << endl;
		}

		return searchResults;
}

void MenuIO::deleteContact()
{
	vector<Contact> searchResults = findContact();
	bool isFound = !searchResults.empty();
	int counter = 0;
	string userSelection = "";
	if (isFound) {
		cout << endl << "Matches Found : " << endl;
		for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
			counter++;
			cout << counter << ". " << it->getFullName() << endl;
		}
		cout << "Would you like to delete these contacts?" << endl;
		userSelection = stringValidator("'Y' or 'N'");
		if (userSelection == "Y" || userSelection == "y") {
			cout << "Deleting contacts..." << endl;
			for (vector<Contact>::iterator it = searchResults.begin(); it != searchResults.end(); it++) {
				_contactList.deleteContact(it->getLastName());
			}
			cout << searchResults.size() << " contacts deleted." << endl;
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
	cout << "Enter a number between " << min << " and " << max << " : ";
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
	cin.ignore(kEndOfLine, '\n');
	getline(cin, userInput);

	bool isValid = false;
	while (!isValid) {
		if (userInput.empty()) {
			cout << "Phrase cannot be empty." << endl
				<< "Please try again : ";
			cin.clear();
			getline(cin, userInput);
		}
		else {
			isValid = true;
		}
	}
	return userInput;
}
