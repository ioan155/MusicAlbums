#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>

using namespace std;

class Album
{
private:
	int m_id;
	static int idGenerator;

protected:
	int m_type;
	int m_year;
	int m_nrSongs;
	string m_name;

public:
	Album();
	Album(int type, int year, int nrSongs, string name);
	~Album() = default;

	int getId() const;

	void setType(int type);
	int getType() const;

	void setYear(int year);
	int getYear() const;

	void setNrSongs(int nrSongs);
	int getNrSongs() const;

	void setName(string name);
	string getName() const;

	virtual void display(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Album&);
	friend istream& operator>>(istream& is, Album&);

	friend bool operator==(const Album&, const Album&);

};

