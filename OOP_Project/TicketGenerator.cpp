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
void TicketGenerator::changeMessage(string s)
{
	TicketGenerator::message = s;
}
Ticket TicketGenerator::generateTicket(int row, int seat, string event_name)
{
	return Ticket(++unique_id, row, seat, event_name);
}
