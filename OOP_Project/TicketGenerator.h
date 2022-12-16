#pragma once
#include "Ticket.h"
#include <string>
class TicketGenerator
{
private:
	static int unique_id;
	static string message;

public:
	TicketGenerator();
	static string getMessage();
	static void changeMessage(string);
	static int getUID();
	Ticket generateTicket(int, int, string);
};


