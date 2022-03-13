#pragma once
#include "Album.h"
#include "Standard.h"
#include "Soundtrack.h"
#include <fstream>
#include <iostream>

using namespace std;

class Repository
{
private:
	vector<Album*> m_repo;
public:
	void addRepo(Album* a);
	int getPosition(int);
	int getPositionOfObject(Album);
	Album* getElementAt(int);
	int size();
	Album* deleteRepo(int id);

	ostream& display(ostream& os, bool(*filterFunction)(Album* a));
	void displayByYear(int);
	void displayByType(string);
	
	void loadFromCSV(const string& csvFilepath)
	{

		ifstream f;
		f.open(csvFilepath);


		if (!f.is_open())     //if the file can't be opened(doesn't exist) then it creates it
		{
			ofstream g;
			g.open(csvFilepath);
			//f.open(csvFilepath);
		}
		else
		{

			while (!f.eof())       //reads the data from the CSV file and keeps it in the repo
			{
				Album* al = new Album;
				f >> *al;
				m_repo.push_back(al);
			}
		}

		f.close();
	}

	void writeToCSV(string csvFilepath)
	{

		ofstream g;
		g.open(csvFilepath);

		if (m_repo.size() > 0)
		{
			g << *m_repo[0];
			for (int i = 1; i < m_repo.size(); i++)       //overwrites the CSV file with the current repository data
			{
				g << endl << *m_repo[i];
			}
		}
		else
			g << "";

		g.close();

	}
	Repository();
	~Repository();
};

