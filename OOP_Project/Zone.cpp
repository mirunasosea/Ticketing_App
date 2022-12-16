
#include "Zone.h"
#include <string>
#include <iostream>

Zone::Zone()
{
	zone_type = "";
	rows = 0;
	seats_per_row = 0;
	availability = nullptr;

}
Zone::Zone(string z, int r, int s) : Zone()
{
	zone_type = z;
	rows = r;
	seats_per_row = s;
	if (rows > 0 && seats_per_row > 0) {
		availability = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			availability[i] = new int[seats_per_row];
		}
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < seats_per_row; j++)
				availability[i][j] = 0;
	}
}
Zone::~Zone()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] availability[i];
	}
	delete[] availability;
	availability = nullptr;
}
Zone::Zone(const Zone& z)
{
	this->zone_type = z.zone_type;
	this->rows = z.rows;
	this->seats_per_row = z.seats_per_row;
	if (z.availability != nullptr && z.rows > 0 && z.seats_per_row > 0)
	{
		this->availability = new int* [z.rows];
		for (int i = 0; i < z.rows; i++)
		{
			this->availability[i] = new int[z.seats_per_row];
		}

		for (int i = 0; i < z.rows; i++)
		{
			for (int j = 0; j < z.seats_per_row; j++)
			{
				this->availability[i][j] = z.availability[i][j];
			}
		}
	}
	else
	{
		this->availability = nullptr;
	}
}
Zone& Zone::operator=(const Zone& z)
{
	if (this != &z)
	{
		if (this == nullptr) {
			cout << "obiectul e nullptr" << endl;
		}
		else {
			if (this->availability != nullptr)
			{
				for (int i = 0; i < rows; i++)
				{
					delete[] this->availability[i];
				}
				delete[] this->availability;
			}
			this->zone_type = z.zone_type;
			this->rows = z.rows;
			this->seats_per_row = z.seats_per_row;
			if (z.availability != nullptr && z.rows > 0 && z.seats_per_row > 0)
			{
				this->availability = new int* [z.rows];
				for (int i = 0; i < z.rows; i++)
				{
					this->availability[i] = new int[z.seats_per_row];
				}

				for (int i = 0; i < z.rows; i++)
				{
					for (int j = 0; j < z.seats_per_row; j++)
					{
						this->availability[i][j] = z.availability[i][j];
					}
				}
			}
			else
			{
				this->availability = nullptr;
			}
		}

	}
	return *this;
}
string Zone::getZoneType()
{
	return zone_type;
}
int Zone::getRows()
{
	return rows;
}
int Zone::getSeatsPerRow()
{
	return seats_per_row;
}
int Zone::getAvailabilityAsIndex(int i, int j)
{
	if (i >= 0 && i < rows && j >= 0 && j < seats_per_row)
		return availability[i][j];
}
void Zone::setZoneType(string z)
{
	zone_type = z;
}
void Zone::setRows(int r)
{
	rows = r;
}
void Zone::setSeatsPerRow(int s)
{
	seats_per_row = s;
}
void Zone::setAvailabilityAsIndex(int i, int j)
{
	availability[i][j] = 1;
}
bool Zone::checkAvailability(int i, int j)
{
	if (availability[i][j] == 0)
		return true;
	else return false;
}
int Zone::available_tickets()
{
	int nr = 0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->seats_per_row; j++)
		{
			if (availability[i][j] == 0)
				nr++;
		}
	}
	return nr;
}
bool Zone::operator==(Zone& z)
{
	if (z.zone_type != this->zone_type)
		return false;
	else if (z.rows != this->rows)
		return false;
	else if (z.seats_per_row != this->seats_per_row)
		return false;
	else return true;
}
ostream& operator<<(ostream& out, Zone z)
{
	out << "Zone type: " << z.zone_type << endl;
	out << "Numebr of rows: " << z.rows << endl;
	out << "Number of seats on each row: " << z.seats_per_row << endl;
	out << "Number of available seats: " << z.available_tickets() << endl;
	return out;
}

istream& operator>>(istream& in, Zone& z)
{
	cout << "Zone type: ";
	in >> ws;
	getline(in, z.zone_type);
	cout << "Number of rows: ";
	in >> z.rows;
	cout << "Seats per row: ";
	in >> z.seats_per_row;
	if (z.rows > 0 && z.seats_per_row > 0) {
		z.availability = new int* [z.rows];
		for (int i = 0; i < z.rows; i++)
		{
			z.availability[i] = new int[z.seats_per_row];
		}
		for (int i = 0; i < z.rows; i++)
			for (int j = 0; j < z.seats_per_row; j++)
				z.availability[i][j] = 0;
	}
	return in;
}
