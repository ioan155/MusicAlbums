#include "Soundtrack.h"


string Soundtrack::getMovie() const
{
    return this->m_movie;
}

void Soundtrack::setMovie(string movie)
{
    this->m_movie = movie;
}

void Soundtrack::display(ostream& os) const
{
    os << "Album: ";
    Album::display(os);
    os << "," << m_movie;
    os << endl;
}

Soundtrack::~Soundtrack()
{
}

istream& operator>>(istream& is, Soundtrack& a)
{
    is >> a.m_name >> a.m_year >> a.m_nrSongs >> a.m_movie;
    return is;
}
