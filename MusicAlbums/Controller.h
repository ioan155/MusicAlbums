#pragma once
#include "Repository.h"
#include <stack>
#include <sstream>

enum class ActionType {
	ADD,
	REMOVE
};

class Controller
{
private:
	Repository m_repo;
	std::stack<pair<ActionType, Album*>> m_undoStack;
	std::stack<pair<ActionType, Album*>> m_redoStack;

public:
	Controller(Repository& r);

	void initialize();
	void writeToCSV();

	void addController(string, string, string, string);
	void deleteController(string id);
	void displayByYearController(string year);
	void displayByType(string);
	void undoController();
	void redoController();

	void displayAll();
	~Controller();
};

