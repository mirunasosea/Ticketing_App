#pragma once
#include "Event.h"
#include <string>
class Ticket
{
private:
	int number_id;
	int row;
	int seat;
	string event_name;

public:
	Ticket();
	Ticket(int, int, int, string);
	~Ticket();
	int getNumberID();
	int getRow();
	int getSeat();
	void writeTicket(int, string);
};

