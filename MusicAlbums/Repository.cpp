#include "Repository.h"

void Repository::addRepo(Album* a)
{
	m_repo.push_back(a);
}

int Repository::getPosition(int id)
{
	for (int i = 0; i < m_repo.size(); i++) {
		if (m_repo[i]->getId() == id)
			return i;
	}
	return -1;
}

int Repository::getPositionOfObject(Album al)
{
	for (auto i = 0; i < m_repo.size(); i++)
	{
		if (*m_repo[i] == al)
			return i;
	}
}

Album* Repository::getElementAt(int pos)
{
	return m_repo[pos];
}

int Repository::size()
{
	return m_repo.size();
}

Album* Repository::deleteRepo(int id)
{
	Album* a = nullptr;
	auto index = find_if(m_repo.begin(), m_repo.end(), [id](Album* a)->bool {
		return a->getId() == id;
		});
	if (index != m_repo.end()) {
		a = *index;
		m_repo.erase(index);
	}
	else {
		throw exception("Invalid ID");
	}
	return a;
}

ostream& Repository::display(ostream& os, bool(*filterFunction)(Album* a))
{
	if (m_repo.size() == 0)
		throw exception("Nothing in repo");

	for (auto i = 0; i < m_repo.size(); i++) {
		if (filterFunction(m_repo[i]))
			os << m_repo[i]->getId() << "-" << *m_repo[i] << endl;
	}
	return os;
}

void Repository::displayByYear(int year)
{
	bool ok = false;
	for(auto i = 0; i<m_repo.size();i++)
		if (m_repo[i]->getYear() >= year)
		{
			ok = true;
			cout << *m_repo[i] << endl;
		}
	if (ok == false)
		throw exception("There are no albums to show");
}

void Repository::displayByType(string type)
{
	if (m_repo.size() == 0)
		throw exception("Nothing in repo");

	vector <Album*> Standards;
	vector <Album*> Soundtracks;

	for (auto i = 0; i < m_repo.size(); i++) {
		if (m_repo[i]->getType() == 1)
			Standards.push_back(m_repo[i]);
		else
			if (m_repo[i]->getType() == 2)
				Soundtracks.push_back(m_repo[i]);
	}

	if (type == "1") {
		if (Standards.size() == 0)
			throw exception("There are no standard albums");
		cout << endl;
		for (auto i = 0; i < Standards.size(); i++)
			cout << *Standards[i] << endl;
		cout << endl;
	}
	else {
		if (Soundtracks.size() == 0)
			throw exception("There are nou soundtracks");
		cout << endl;
		for (auto i = 0; i < Soundtracks.size(); i++)
			cout << *Soundtracks[i] << endl;
		cout << endl;
	}
}

Repository::Repository()
{
}

Repository::~Repository()
{
}
