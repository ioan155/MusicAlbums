#include "Album.h"
#include <sstream>

int Album::idGenerator = 0;

Album::Album()
{
	idGenerator++;
	this->m_id = idGenerator;
	this->m_type = 0;
	this->m_name = "no name";
	this->m_nrSongs = 0;
	this->m_year = 0;
}

Album::Album(int type, int year, int nrSongs, string name)
{
	idGenerator++;
	this->m_id = idGenerator;
	this->m_type = type;
	this->m_name = name;
	this->m_nrSongs = nrSongs;
	this->m_year = year;
}

int Album::getId() const
{
	return this->m_id;
}

void Album::setType(int type)
{
	this->m_type = type;
}

int Album::getType() const
{
	return this->m_type;
}

void Album::setYear(int year)
{
	this->m_year = year;
}

int Album::getYear() const
{
	return this->m_year;
}

void Album::setNrSongs(int nrSongs)
{
	this->m_nrSongs = nrSongs;
}

int Album::getNrSongs() const
{
	return this->m_nrSongs;
}

void Album::setName(string name)
{
	this->m_name = name;
}

string Album::getName() const
{
	return this->m_name;
}

void Album::display(ostream& os) const
{
	stringstream strType;
	strType << this->m_type << ",";
	os<<strType.str();

	os << this->m_name + ",";

	stringstream strYear;
	strYear << this->m_year << ",";
	os << strYear.str();

	stringstream strNrSongs;
	strNrSongs << this->m_nrSongs << " songs";
	os << strNrSongs.str();
}


ostream& operator<<(ostream& os, const Album& al)
{
	al.display(os);
	return os;
}

istream& operator>>(istream& is, Album& a)
{
	is >> a.m_type >> a.m_name >> a.m_year >> a.m_nrSongs;
	return is;
}

bool operator==(const Album& a, const Album& b)
{
	return a.m_type == b.m_type && a.m_name == b.m_name && a.m_nrSongs == b.m_nrSongs && a.m_year == b.m_year;
}
