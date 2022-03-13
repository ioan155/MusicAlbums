#include "Standard.h"

string Standard::getArtist() const
{
    return this->m_artist;
}

void Standard::setArtist(string artist)
{
    this->m_artist = artist;
}

void Standard::display(ostream& os) const
{
    os << "Album: ";
    Album::display(os);
    os << "," << m_artist;
    os << endl;
}

Standard::~Standard()
{
}

istream& operator>>(istream& is, Standard& a)
{
    is >> a.m_name >> a.m_year >> a.m_nrSongs >> a.m_artist;
    return is;
}
