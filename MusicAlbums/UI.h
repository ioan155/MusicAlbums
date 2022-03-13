#pragma once

#include "Album.h"
#include "Soundtrack.h"
#include "Standard.h"
#include "Controller.h"
#include <iostream>
#include <fstream>

using namespace std;

class UI
{
private:
	Controller m_controller;
public:
	UI(Controller&);
	void addUI(); 
	void deleteUI(); 
	void displayAllUI();
	void displayByYearUI();
	void displayByTypeUI();
	void redoUI();
	void undoUI();
	void showUI();
	void initialize();
	
};

