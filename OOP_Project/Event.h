#pragma once
#include <string>
#include "Zone.h"
using namespace std;

class Event
{
private:
	string event_type;
	char* location;
	string date;
	string hour;
	Zone* zones;
	int nZones;

public:
	Event();
	Event(string, const char*, string, string);
	~Event();
	Event(const Event&);
	Event& operator=(const Event&);
	string getEventType();
	char* getLocation();
	string getDate();
	string getHour();
	string getZoneType(int);
	Zone getZone(int);
	int getNZones();
	void setZones(Zone*, int);
	void setLocation(const char*);
	void setDate(string);
	void setHour(string);
	bool EventInMonth(int);
	double maximumCapacity();
	void bookTicket(Zone, int, int);
	bool operator!();
	friend ostream& operator<<(ostream&, Event);
	friend istream& operator>>(istream&, Event&);
	friend ofstream& operator<<(ofstream&, Event);
	friend ifstream& operator>>(ifstream&, Event&);

};
ostream& operator<<(ostream&, Event);
istream& operator>>(istream&, Event&);
ofstream& operator<<(ofstream&, Event);
ifstream& operator>>(ifstream&, Event&);



