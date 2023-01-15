#include "Ticket.h"

Ticket::Ticket()
{

}
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
void Ticket::writeTicket(int number_id, string filename)
{
	ofstream appendFile(filename, ios::binary | ios::app);
	appendFile.write((char*)&number_id, sizeof(number_id));
}
