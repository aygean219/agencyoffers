#pragma once
#include <stdlib.h>
#include <string.h>
//representation for date
typedef struct {
	int day;
	int month;
	int year;
}date;
//representation of an offer
typedef struct {
	char* type;
	char* destination;
	date date;
	int price;
}Offer;

/*
* Create an new offer
* @param: type of offer(char*),destination for offer(char*),date for offer(date),price for offer(int)
* pre:all param. are validate
* post:offer is created
*/
Offer createOffer(char* type, char* destination, date date, int price);

/*
 Dealocate memory occupied by offer
 @param:an offer(Offer*)
 pre:-
 post:offer was destroyed
*/
void destroyOffer(Offer* o);

/*
Create a copy for the offer
Deep copy - copy all the sub-parts
@param:an offer(Offer*)
@return:copy of the offer(Offer*)
 pre:-
 post:-
 
*/
Offer copyOffer(Offer* o);

/*
   Validate type for the offer
   return !=0 if the type is invalid
   @param:an offer(Offer)
*/
int validate_type(Offer o);

/*
   Validate date
   return !=0 if the date is invalid
  @param:an offer(Offer)
*/
int validate_date(Offer o);

/*
   Validate destination
   return !=0 if the destination is invalid
   @param:an offer(Offer)
*/
int validate_destination(Offer o);

/*
   Validate price
   return !=0 if the price is invalid
   @param:an offer(Offer)
*/
int validate_price(Offer o);
