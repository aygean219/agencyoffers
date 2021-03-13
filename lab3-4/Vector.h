#pragma once
#include "Offer.h"
typedef Offer ElemType;
typedef struct {
	ElemType* elems;
	int lg;//current number of elems
	int cp;//capacity
}MyVector;

/*
  Create an empty list
*/
MyVector createEmpty();

/*
  Destroy list
*/
void destroy(MyVector* v);

/*
  Get an element from the list
  poz - position of the element, need to be valid
  return element on the given position
*/
ElemType get(MyVector* v, int poz);

/*
Modify the element on the given pozition
return the overwrited element
*/
ElemType set(MyVector* v, int poz, Offer o);

/*
  return number of elements in the list
*/
int size(MyVector* v);

/*
  Allocate more memory if needed
*/
void ensureCapacity(MyVector* l);

/*
Make a shallow copy of the list
return Mylist containing the same elements as l
*/
MyVector copyList(MyVector* v);

/*
  Add element into the list
  post: element is added to the end of the list
*/
void add(MyVector* v, ElemType el);

/*Delete a existing offer 
* pre:-
* post:offer has been deleted
*/
void del(MyVector* v, ElemType el);

/*Update a existing offer 
* pre:-
* post:offer has been updated
*/
void update(MyVector* v, ElemType el_vechi,ElemType el_nou);

/*Filter by destination
* pre:-
* post:vector has only offers with that destination
*/
void filter_by_destination(MyVector* v, char* d);

/*Filter by type
* pre:-
* post:vector has only offers with that type
*/
void filter_by_type(MyVector* v, char* t);

/*Filter by price
* pre:-
* post:vector has only offers with that price
*/
void filter_by_price(MyVector* v, int p);

/*Exchange two offers
* post:offer1 has the value of offer2 and vice versa
*/
void changeOffer(ElemType* o1, ElemType* o2);

/*Ascending order by price 
* pre:-
* post:vector has only offers with that destination
*/
void ascending_order_by_price_and_destination(MyVector* v, char* d);

/*Descending order by price
* pre:-
* post:vector has only offers with that destination
*/
void descending_order_by_price_and_destination(MyVector* v, char* d);