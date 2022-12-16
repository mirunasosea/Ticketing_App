#include "Ticket.h"


Ticket::Ticket(int number_id, int row, int seat, string event_name)
{
	this->number_id = number_id;
	this->row = row;
	this->seat = seat;
	this->event_name = event_name;
}
Ticket::~Ticket()
{

}
int Ticket::getNumberID()
{
	return number_id;
}
int Ticket::getRow()
{
	return row;
}
int Ticket::getSeat()
{
	return seat;
}

