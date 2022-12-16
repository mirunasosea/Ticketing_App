#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

Event::Event()
{
	event_type = "";
	location = nullptr;
	date = "";
	hour = "";
}
Event::Event(string e, const char* l, string d, string h)
{
	event_type = e;
	if (l != nullptr)
	{
		location = new char[strlen(l) + 1];
		strcpy_s(location, strlen(l) + 1, l);
	}
	else
	{
		location = nullptr;
	}
	date = d;
	hour = h;
}
Event::~Event()
{
	if (location != nullptr)
	{
		delete[] location, location = nullptr;
	}
}
Event::Event(const Event& e)
{
	//cout << "s a apelat" << endl;
	this->event_type = e.event_type;
	if (e.location != nullptr)
	{
		this->location = new char[strlen(e.location) + 1];
		strcpy_s(this->location, strlen(e.location) + 1, e.location);
	}
	else
	{
		this->location = nullptr;
	}
	this->date = e.date;
	this->hour = e.hour;
	this->nZones = e.nZones;
	//cout << "in copy constr: " << e.nZones << endl;
	if (e.zones != nullptr)
	{
		this->zones = new Zone[e.nZones];
		for (int i = 0; i < e.nZones; i++)
		{
			this->zones[i] = e.zones[i];
		}
	}
}
Event& Event::operator=(const Event& e)
{
	if (this != &e)
	{
		//cout << "Operator= merge?" << endl;
		this->event_type = e.event_type;
		if (e.location != nullptr)
		{
			if (this->location != nullptr)
			{
				delete[] this->location;
			}
			this->location = new char[strlen(e.location) + 1];
			strcpy_s(this->location, strlen(e.location) + 1, e.location);
		}
		else
		{
			this->location = nullptr;
		}
		this->date = e.date;
		this->hour = e.hour;
		if (e.zones != nullptr)
		{
			this->zones = new Zone[e.nZones];
			for (int i = 0; i < e.nZones; i++)
			{
				this->zones[i] = e.zones[i];
			}
		}
		this->nZones = e.nZones;
	}
	return *this;
}
string Event::getEventType()
{
	return event_type;
}
char* Event::getLocation()
{
	if (location != nullptr)
	{
		char* copy = new char[strlen(location) + 1];
		strcpy_s(copy, strlen(location) + 1, location);
		return copy;
	}
	return nullptr;
}
string Event::getDate()
{
	return date;
}
string Event::getHour()
{
	return hour;
}
string Event::getZoneType(int i)
{
	if (i >= 0 && i < nZones && zones != nullptr)
	{
		return zones[i].getZoneType();
	}
}
Zone Event::getZone(int i)
{
	Zone zbuff;
	if (i >= 0 && i < nZones && zones != nullptr)
	{
		zbuff = zones[i];
	}
	return zbuff;
}
int Event::getNZones()
{
	return nZones;
}
void Event::setZones(Zone* z, int nZones)
{
	//cout << "intra aici" << endl;
	this->nZones = nZones;
	if (z != nullptr && nZones > 0)
	{
		this->zones = new Zone[nZones];
		for (int i = 0; i < nZones; i++)
		{
			this->zones[i] = z[i];
		}
	}
}
void Event::setLocation(const char* location)
{
	if (location != nullptr)
	{
		if (this->location != nullptr)
		{
			delete[] this->location;
		}
		this->location = new char[strlen(location) + 1];
		strcpy_s(this->location, strlen(location) + 1, location);
	}
}
void Event::setDate(string date)
{
	this->date = date;
}
void Event::setHour(string hour)
{
	this->hour = hour;
}

//method wich verifies if an event takes place in a given month
bool Event::EventInMonth(int month)
{
	string m;
	if (month >= 1 && month <= 9)
	{
		m = "0" + to_string(month);
	}
	else
	{
		m = to_string(month);
	}
	if (m == this->date.substr(3, 2))
		return true;
	else
		return false;
}
double Event::maximumCapacity()
{
	double total = 0;
	for (int i = 0; i < nZones; i++)
	{
		total += zones[i].getRows() * zones[i].getSeatsPerRow();
	}
	return total;
}
void Event::bookTicket(Zone z, int i, int j)
{
	for (int k = 0; k < nZones; k++)
	{
		if (zones[k] == z)
		{
			zones[k].setAvailabilityAsIndex(i, j);
		}
	}
}
bool Event::operator!()
{
	return nZones <= 0;
}
ostream& operator<<(ostream& out, Event e)
{
	out << "========================================" << endl;
	out << "Type of event: " << e.event_type << endl;
	out << "The location of the event: " << e.location << endl;
	out << "Date: " << e.date << endl;
	out << "Hour: " << e.hour << endl;
	out << endl;
	if (e.zones != nullptr)
	{
		out << "The available zones: " << endl;
		for (int i = 0; i < e.nZones; i++)
		{
			out << e.zones[i] << endl;
		}
	}
	else
	{
		cout << "Null zones attribute" << endl;
	}
	return out;
}

istream& operator>>(istream& in, Event& e)
{
	cout << "The type of the event as Event: ";
	in >> ws;
	getline(in, e.event_type);
	if (e.location != nullptr)
	{
		delete[] e.location;
	}
	cout << "The location of the event: ";
	string buffer;
	in >> ws;
	getline(in, buffer);
	e.setLocation(buffer.c_str());
	cout << "Date (please insert date as dd.mm.yyyy): ";
	in >> e.date;
	cout << "Hour: ";
	in >> e.hour;
	cout << "The number of zones: ";
	in >> e.nZones;
	e.zones = new Zone[e.nZones];
	for (int i = 0; i < e.nZones; i++)
	{
		cin >> e.zones[i];
	}
	return in;
}
