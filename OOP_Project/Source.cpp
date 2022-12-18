#include "Event.h"
#include "Zone.h"
#include "Ticket.h"
#include "TicketGenerator.h"
#include <iostream>
using namespace std;

//returns a month from Month to mm (e.g.: July -> 7)
int MonthAsInt(string month)
{
	if (month == "January") return 1;
	else if (month == "February") return 2;
	else if (month == "March") return 3;
	else if (month == "April") return 4;
	else if (month == "May") return 5;
	else if (month == "June") return 6;
	else if (month == "July") return 7;
	else if (month == "August") return 8;
	else if (month == "September") return 9;
	else if (month == "October") return 10;
	else if (month == "November") return 11;
	else if (month == "December") return 12;
	else return 0; 
}

int main()
{
	//populating our data base with events
	Event e1 = Event("Concert", "Carnegie Hall", "14.02.2023", "18:30");
	Zone z1 = Zone("VIP", 3, 6);
	Zone z2 = Zone("tribune1", 5, 10);
	Zone z3 = Zone("tribune2", 6, 7);
	Zone* z = new Zone[3];
	z[0] = z1;
	z[1] = z2;
	z[2] = z3;
	e1.setZones(z, 3);
	Event e2("Football match", "National arena", "23.01.2023", "14:00");
	Event e3("Movie", "Cinema", "21.12.2022", "20:00");
	if (z != nullptr)
	{
		delete[] z, z = nullptr;
	}
	z = new Zone[2];
	z1 = Zone("VIP", 4, 5);
	z2 = Zone("Normal", 3, 4);
	z[0] = z1, z[1] = z2;
	e3.setZones(z, 2);
	int n = 3;
	Event* e_list = new Event[n];
	e_list[0] = e1;
	e_list[1] = e2;
	e_list[2] = e3;


	cout << "OOP Project -> The Ticketing App" << endl;
	cout << "By Miruna Sosea, 1060" << endl;
	cout << "Please choose how we can help you:" << endl;
	cout << '\t' << "Press 1 if you want to see the list of available events" << endl;
	cout << '\t' << "Press 2 to check the available events in a certain month " << endl;
	cout << '\t' << "Press 3 to check the available seats for a certain event" << endl;
	cout << '\t' << "Press 4 if you want to book a ticket " << endl;
	cout << '\t' << "Press 5 to add a new event" << endl;
	cout << '\t' << "Press 6 to verify your ticket ID" << endl;
	cout << '\t' << "Press 0 if you want to exit" << endl;
	cout << "Your option: ";
	int option;
	cin >> option;
	while (option != 0)
	{
		if (option == 1)
		{
			cout << "These are our available events:" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << e_list[i] << endl;
			}
		}
		else if (option == 2)
		{
			cout << "Please insert the month as 'Month' (e.g. September)" << endl;
			string month;
			cin >> month;
			int m = MonthAsInt(month);
			if (m == 0)
			{
				cout << "The input is not in the correct format. Please insert the month as 'Month'" << endl;
			}
			else
			{
				int k = 0;
				for (int i = 0; i < n; i++)
				{
					if (e_list[i].EventInMonth(m) == true)
					{
						cout << e_list[i] << endl;
						k++;
					}
				}
				if (k == 0)
				{
					cout << "There are no available events in " << month << endl;
				}
			}
		}
		else if (option == 3)
		{
			cout << "What are you interested in? Concert, football match etc" << endl;
			cout << "!!!!!Please insert the name with capital first letter (e.g. Movie)!!!!!" << endl;
			string type;
			cin >> ws;
			getline(cin, type);

			int k = 0;
			for (int i = 0; i < n; i++)
			{
				if (e_list[i].getEventType() == type)
				{
					k++;
					cout << e_list[i].getEventType() << " " << e_list[i].getDate() << " " << e_list[i].getHour() << endl;
					cout << "Maximum capacity: " << e_list[i].maximumCapacity() << endl;
					for (int j = 0; j < e_list[i].getNZones(); j++)
					{
						cout << "Zone type: " << e_list[i].getZoneType(j) << endl;
						if (!e_list[i])
						{
							cout << "No zones assigned" << endl;
						}
						else
						{
							cout << "Number of available seats: " << e_list[i].getZone(j).available_tickets() << endl;
						}
					}

				}
			}
			if (k == 0)
			{
				cout << '\t' << "We couldn't find what you where looking for. Please check the input " << endl;
			}
		}
		else if (option == 4)
		{
			cout << "Where would you like to book a ticket?" << endl;
			for (int i = 0; i < n; i++)
			{
				cout << e_list[i] << endl;
			}
			cout << "Please insert the event type as Event and date of the event as dd.mm.yyyy" << endl;
			string date;
			string type;
			string ztype;
			cin >> ws;
			getline(cin, type);
			cin >> ws;
			cin >> date;
			int i = 0;
			while (e_list[i].getEventType() != type && e_list[i].getDate() != date)
			{
				i++;
			}
			if (i >= n)
			{
				cout << '\t' << "We couldn't find what you where looking for. Please check the input " << endl;
			}
			else
			{ 
				if (!e_list[i])
				{

					TicketGenerator tg;
					Ticket t = tg.generateTicket(1, 1, ztype);
					cout << "Your unique ticket id is: " << t.getNumberID() << " " << endl;
				}
				else 
				{
					for (int j = 0; j < e_list[i].getNZones(); j++)
					{
						cout << "Zone type: " << e_list[i].getZoneType(j) << endl;
						cout << "Number of available seats: " << e_list[i].getZone(j).available_tickets() << endl;
					}
					cout << '\t' << "Please choose the zone where you want to book a ticket" << endl;

					cin >> ws;
					getline(cin, ztype);
					int j = 0;
					while (e_list[i].getZoneType(j) != ztype)
					{
						j++;
					}
					cout << "======================================" << endl;
					cout << '\t' << "Please choose the row and seat (the seats and rows are numbered from 1)" << endl;
					for (int k = 0; k < e_list[i].getZone(j).getRows(); k++)
					{
						for (int l = 0; l < e_list[i].getZone(j).getSeatsPerRow(); l++)
						{
							cout << e_list[i].getZone(j).getAvailabilityAsIndex(k, l) << " ";
						}
						cout << endl;
					}

					int s, r;
					cin >> r >> s;
					if (e_list[i].getZone(j).checkAvailability(r - 1, s - 1) == true)
					{
						e_list[i].bookTicket(e_list[i].getZone(j), r - 1, s - 1);
						TicketGenerator tg;
						Ticket t = tg.generateTicket(r - 1, s - 1, ztype);
						cout << "Your unique ticket id is: " << t.getNumberID() << " " << endl;
					}
					else
					{
						cout << "This seat is already taken" << endl;
					}
				}
				
			}				
					
		}
		else if (option == 5)
		{
			cout << "Do you want to add an event? y/n" << endl;
			char answ;
			cin >> answ;
			if (answ == 'y')
			{
				Event e;
				cin >> e;
				n++;
				Event* buffer = new Event[n];
				for (int i = 0; i < n - 1; i++)
				{
					buffer[i] = e_list[i];
				}
				buffer[n - 1] = e;
				if (e_list != nullptr)
				{
					delete[] e_list, e_list = nullptr;
				}
				e_list = new Event[n];
				for (int i = 0; i < n; i++)
				{
					e_list[i] = buffer[i];
				}
				delete[] buffer, buffer = nullptr;
			}
		}
		else if ( option == 6)
		{
			cout << '\t' << "Please insert your unique ID for validation" << endl;
			TicketGenerator tg;
			int id;
			cin >> id;
			if (id > tg.getUID())
				cout << "Invalid ID" << endl;
			else
			{
				 tg.changeMessage("Your ID is verified");
				 cout << tg.getMessage() << endl;
			}
		}
		else if (option > 6)
		{
		cout << "This is not a valid option." << endl;
		}

		cout << "Press 1, 2, 3, 4, 5 or 6 for the desired option or press 0 to exit" << endl;
		cin >> option;
	}
	
}
