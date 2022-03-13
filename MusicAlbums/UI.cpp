#include "UI.h"

UI::UI(Controller& c): m_controller{c}
{}

void UI::addUI()
{
	try {
		string type, year, nrSongs, name;
		cout << "Please give the type of album you want to add: 1 - Standard, 2 - Soundtrack ";
		cin >> type;
		cout << "Please give the name of the album: ";
		cin >> name;
		cout << "Please give the year the album was released: ";
		cin >> year;
		cout << "Please give the number of songs on the ablum: ";
		cin >> nrSongs;

		m_controller.addController(type, year, nrSongs, name);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::deleteUI()
{
	try {
		string id;
		cout << "Please enter the id: ";
		cin >> id;
		m_controller.deleteController(id);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayAllUI()
{
	try {
		cout << endl;
		m_controller.displayAll();
		cout << endl << endl;
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayByYearUI()
{
	try {
		string year;
		cout << "Please give a year: ";
		cin >> year;
		m_controller.displayByYearController(year);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::displayByTypeUI()
{
	try {
		string type;
		cout << "Please insert the type of album you want to display (1 or 2)" << endl << endl;
		cout << "1 - all standard" << endl << "2 - all soundtracks" << endl;
		cin >> type;
		m_controller.displayByType(type);
	}
	catch (exception e) { cout << e.what() << endl << endl; }
}

void UI::redoUI()
{
	try {
		m_controller.redoController();
	}
	catch (exception e) { cout << e.what() << endl; }
}

void UI::undoUI()
{
	try {
		m_controller.undoController();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void UI::showUI()
{
	char option;
	do {
		cout << "Please insert your option: " << endl;
		cout << "1 - Add \n";
		cout << "2 - Display all \n";
		cout << "3 - Remove \n";
		cout << "4 - Display all albums after a year \n";
		cout << "5 - Display all albums of a type \n";
		cout << "6 - Undo \n";
		cout << "7 - Redo \n";
		cout << "0 - Exit \n";

		cin >> option;
		switch (option) {
		default:
			break;
		case '1':
			addUI();
			break;
		case '2':
			displayAllUI();
			break;
		case '3':
			deleteUI();
			break;
		case '4':
			displayByYearUI();
			break;
		case '5':
			displayByTypeUI();
			break;
		case  '6':
			undoUI();
			break;
		case '7':
			redoUI();
			break;
		case '0':
			m_controller.writeToCSV();
			exit(0);
			break;
		}
	} while (true);
}

void UI::initialize()
{
	m_controller.initialize();
	showUI();
}

