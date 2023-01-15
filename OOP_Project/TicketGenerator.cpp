#include "TicketGenerator.h"

int TicketGenerator::unique_id = 0;
string TicketGenerator::message = "Your ticket was successfully booked!";
TicketGenerator::TicketGenerator()
{

}
string TicketGenerator::getMessage()
{
	return message;
}
int TicketGenerator::getUID()
{
	return unique_id;
}
void TicketGenerator::setUID(int id)
{
	TicketGenerator::unique_id = id;
}
void TicketGenerator::changeMessage(string s)
{
	TicketGenerator::message = s;
}
Ticket TicketGenerator::generateTicket(int row, int seat, string event_name)
{
	return Ticket(++unique_id, row, seat, event_name);
}


int TicketGenerator::manageTicket(string filename)
{
	int last_ticket = 0;
	ifstream f(filename, ios::in | ios::binary);
	f.seekg(0, ios::end);
	int noTickets = f.tellg() / sizeof(int); //the number of emitted tickets
	f.seekg((noTickets - 1) * sizeof(int));
	f.read((char*)&last_ticket, sizeof(int));
	return last_ticket;
}