#include "Controller.h"
#include <iostream>

Controller::Controller(Repository& r)
{
	m_repo = r;
}

void Controller::initialize()
{
	std::string CSVfile = "Album.csv";
	m_repo.loadFromCSV(CSVfile);
}

void Controller::writeToCSV()
{
	string CSVfile = "Album.h";
	m_repo.writeToCSV(CSVfile);
}

void Controller::addController(string t, string y, string nr, string name)
{
	int type, year, nrSongs;
	stringstream ss, ss1, ss2;
	ss << t;
	ss >> type;
	if (type == 0) {
		throw exception("Type must be integer");
	}
	ss1 << y;
	ss1 >> year;
	if (year == 0) {
		throw exception("The year must be integer");
	}
	ss2 << nr;
	ss2 >> nrSongs;
	if (nrSongs == 0) {
		throw exception("The number of songs must be integer");
	}
	Album* a = new Album{ type, year, nrSongs,name };
	m_repo.addRepo(a);
	m_undoStack.push(std::make_pair(ActionType::ADD, a));
}

void Controller::deleteController(string id)
{
	int ID;
	stringstream ss;
	ss << id;
	ss >> ID;
	if (ID == 0) {
		throw exception("The id must be an integer");
	}

	Album* a = m_repo.deleteRepo(ID);
	if (a)
		m_undoStack.push(std::make_pair(ActionType::REMOVE, a));
}

void Controller::displayByYearController(string y)
{
	int year;
	stringstream ss;
	ss << y;
	ss >> year;
	if (year == 0) {
		throw exception("The year must be integer");
	}
	m_repo.displayByYear(year);
}

void Controller::displayByType(string type)
{
	if (type != "1" && type != "2")
		throw exception("Incorrect type");
	else
		m_repo.displayByType(type);
}

void Controller::undoController()
{
	if (m_undoStack.size() == 0)
		throw exception("Nothing to undo");

	if (m_undoStack.top().first == ActionType::ADD) {
		m_repo.deleteRepo(m_undoStack.top().second->getId());
		m_redoStack.push(std::make_pair(ActionType::ADD, m_undoStack.top().second));
	}
	else{
		m_repo.addRepo(m_undoStack.top().second);
		m_redoStack.push(std::make_pair(ActionType::REMOVE, m_undoStack.top().second));
	}

	m_undoStack.pop();
}

void Controller::redoController()
{
	if (m_redoStack.size() == 0)
		throw exception("Nothing to redo");

	if (m_redoStack.top().first == ActionType::ADD)
	{
		m_repo.addRepo(m_redoStack.top().second);
		m_undoStack.push(std::make_pair(ActionType::ADD, m_redoStack.top().second));
	}
	else
	{
		m_repo.deleteRepo(m_redoStack.top().second->getId());
		m_undoStack.push(std::make_pair(ActionType::REMOVE, m_redoStack.top().second));
	}

	m_redoStack.pop();
}

void Controller::displayAll()
{
	m_repo.display(std::cout, [](Album* a)->bool {return true;  });
}

Controller::~Controller()
{
}
