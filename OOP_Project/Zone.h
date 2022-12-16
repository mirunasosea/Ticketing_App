#pragma once
#include <string>
#include <iostream>
using namespace std;


class Zone
{
private:
	string zone_type; //e.g. tribune1, VIP 
	int rows;
	int seats_per_row;
	int** availability; // 0 if the seat is available, 1 if not

public:
	Zone();
	Zone(string, int, int);
	~Zone();
	Zone(const Zone& z);
	Zone& operator=(const Zone&);
	string getZoneType();
	int getRows();
	int getSeatsPerRow();
	int getAvailabilityAsIndex(int, int);
	void setZoneType(string);
	void setRows(int);
	void setSeatsPerRow(int);
	void setAvailabilityAsIndex(int, int);
	bool checkAvailability(int, int);
	int available_tickets();
	bool operator==(Zone&);
	friend ostream& operator<<(ostream&, Zone);
	friend istream& operator>>(istream&, Zone&);
	
};
ostream& operator<<(ostream&, Zone);
istream& operator>>(istream&, Zone&);



