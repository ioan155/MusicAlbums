#pragma once
#include "Album.h"
#include <string>

class Standard:public Album
{
private:
	string m_artist;

public:
	Standard() :Album() {
		m_type = 1;
		m_artist = "no artist";
	}
	Standard(int type, int year, int nrSongs, string name, string artist) : Album(type, year, nrSongs, name) {
		this->m_type = 1;
		this->m_artist = artist;
	}

	string getArtist() const;
	void setArtist(string artist);

	void display(ostream& os)const override;
	friend istream& operator>>(istream& is, Standard&);

	~Standard();
};

