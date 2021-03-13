#pragma once
#include "Offer.h"
#include <string.h>
#include <stdlib.h>
Offer createOffer(char* type, char* destination,date date, int price)
{
	Offer rez;
	size_t nrC= strlen(type) + 1;
	rez.type = malloc(sizeof(char) * nrC);
	strcpy_s(rez.type, nrC, type);
	nrC = strlen(destination) + 1;
	rez.destination = malloc(sizeof(char) * nrC);
	strcpy_s(rez.destination, nrC, destination);
	rez.date.day = date.day;
	rez.date.month = date.month;
	rez.date.year = date.year;
	rez.price = price;
	return rez;
}
void destroyOffer(Offer* o)
{
	free(o->type);
	free(o->destination);
	o->type=NULL;
	o->destination = NULL;
	o->price = -1;
	o->date.day = -1;
	o->date.month = -1;
	o->date.year = -1;
}
Offer copyOffer(Offer* o)
{
	return createOffer(o->type, o->destination, o->date, o->price);
}
int validate_type(Offer o)
{
	if (strcmp(o.type, "city_break") != 0)
	{
		if (strcmp(o.type, "mare") != 0)
		{
			if (strcmp(o.type, "munte") != 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
int validate_price(Offer o)
{
	if (o.price<500)
	{
				return 1;
	}
	return 0;
}
int validate_date(Offer o)
{
	if (o.date.day <=0|| o.date.day>=32)
		return 1;
	if (o.date.month <= 0 || o.date.month >= 13)
		return 2;
	if (o.date.year <2021)
		return 3;
	return 0;
}
int validate_destination(Offer o)
{
	if (strlen(o.destination)==0)
	{
		return 1;
	}
	return 0;
}
