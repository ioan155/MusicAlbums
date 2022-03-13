#pragma once
#include "Album.h"
#include <string>

class Soundtrack :public Album
{
private:
	string m_movie;

public:
	Soundtrack() :Album() {
		m_type = 2;
		m_movie = "no movie";
	}
	Soundtrack(int type, int year, int nrSongs, string name, string movie) : Album(type, year, nrSongs, name) {
		this->m_type = 2;
		this->m_movie = movie;
	}

	string getMovie() const;
	void setMovie(string movie);

	void display(ostream& os)const override;
	friend istream& operator>>(istream& is, Soundtrack&);

	~Soundtrack();
};


