#include "Vector.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

MyVector createEmpty()
{
	MyVector rez;
	rez.lg = 0;
	rez.cp = 2;
	rez.elems = malloc(sizeof(ElemType) * rez.cp);
	return rez;
}

void destroy(MyVector* v)
{
	for (int i = 0; i < v->lg; i++)
	{
		destroyOffer(&v->elems[i]);
	}
	free(v->elems);
	v->elems = NULL;
	v->lg = 0;
}

ElemType get(MyVector* v, int poz)
{
	return v->elems[poz];
}

ElemType set(MyVector* v, int poz, Offer o)
{
	ElemType rez = v->elems[poz];
	v->elems[poz] = o;
	return rez;
} 

int size(MyVector* v)
{
	return v->lg;
}
void ensureCapacity(MyVector* l) {
	if (l->lg < l->cp) {
		return; //we have room
	}
	//alocate more memory
	int newCapacity = l->cp + 2;
	ElemType* nElems = malloc(sizeof(ElemType) * newCapacity);
	//copy elems
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	//dealocate old vector
	free(l->elems);
	l->elems = nElems;
	l->cp = newCapacity;
}
void add(MyVector* v, ElemType el)
{
	ensureCapacity(v);
	v->elems[v->lg] = el;
	v->lg++;
}

MyVector copyList(MyVector* v) {
	MyVector rez = createEmpty();
	for (int i = 0; i < size(v); i++) {
		ElemType p = get(v, i);
		add(&rez, copyOffer(&p));
	}
	return rez;
}
void del(MyVector* v, ElemType el)
{
	int pos = -1;
	for (int i = 0; i <v->lg; i++)
	{
		if ((strcmp(v->elems[i].destination,  el.destination) == 0) && (strcmp(v->elems[i].type, el.type) == 0) && (v->elems[i].date.day== el.date.day) && (v->elems[i].date.month==el.date.month) && (v->elems[i].date.year== el.date.year) && (v->elems[i].price == el.price))
		{
			pos = i;
		}
	}
	ElemType* nElems = malloc(sizeof(ElemType) * v->lg-1);
	//copy elems
	for (int i = 0; i <=pos; i++) {
		nElems[i] = v->elems[i];
	}
	for (int i = pos; i < v->lg - 1; i++)
	{
		nElems[i] = v->elems[i + 1];
	}
	v->elems = nElems;
	v->lg = v->lg - 1;
}

void update(MyVector* v, ElemType el, ElemType el_nou)
{
	for (int i = 0; i < v->lg; i++)
	{
		if ((strcmp(v->elems[i].destination, el.destination) == 0) && (strcmp(v->elems[i].type, el.type) == 0) && (v->elems[i].date.day == el.date.day) && (v->elems[i].date.month == el.date.month) && (v->elems[i].date.year == el.date.year) && (v->elems[i].price == el.price))
		{
			v->elems[i] = el_nou;
		}
	}

}
void filter_by_destination(MyVector* v, char* d)
{
	ElemType* nElems = malloc(sizeof(ElemType) * v->lg - 1);
	int j = 0;
	for (int i = 0; i < v->lg; i++)
	{
		if (strcmp(v->elems[i].destination, d) == 0)
		{
			nElems[j] = v->elems[i];
			j++;
		}
	}
	v->elems = nElems;
	v->lg = j;
}

void filter_by_type(MyVector* v, char* t)
{
	ElemType* nElems = malloc(sizeof(ElemType) * v->lg - 1);
	int j = 0;
	for (int i = 0; i < v->lg; i++)
	{
		if (strcmp(v->elems[i].type, t) == 0)
		{
			nElems[j] = v->elems[i];
			j++;
		}
	}
	v->elems = nElems;
	v->lg = j;
}

void filter_by_price(MyVector* v, int p)
{
	ElemType* nElems = malloc(sizeof(ElemType) * v->lg - 1);
	int j = 0;
	for (int i = 0; i < v->lg; i++)
	{
		if (v->elems[i].price==p)
		{
			nElems[j] = v->elems[i];
			j++;
		}
	}
	v->elems = nElems;
	v->lg = j;
}
void changeOffer(ElemType* o1, ElemType* o2)
{
	ElemType* aux=malloc(sizeof(ElemType));
	size_t nrC;
	aux->date.day = o1->date.day;
	aux->date.month = o1->date.month;
	aux->date.year = o1->date.year;
	aux->price = o1->price;
	nrC = strlen(o1->type) + 1;
	aux->type = malloc(sizeof(char) * nrC);
	strcpy_s(aux->type, nrC, o1->type);
	nrC = strlen(o1->destination) + 1;
	aux->destination = malloc(sizeof(char) * nrC);
	strcpy_s(aux->destination, nrC, o1->destination);
	//aux=o1

	o1->date.day = o2->date.day;
	o1->date.month = o2->date.month;
	o1->date.year = o2->date.year;
	o1->price = o2->price;
	nrC = strlen(o2->type) + 1;
	o1->type = malloc(sizeof(char) * nrC);
	strcpy_s(o1->type, nrC, o2->type);
	nrC = strlen(o2->destination) + 1;
	o1->destination = malloc(sizeof(char) * nrC);
	strcpy_s(o1->destination, nrC, o2->destination);
	//o1=o2

	o2->date.day = aux->date.day;
	o2->date.month = aux->date.month;
	o2->date.year = aux->date.year;
	o2->price = aux->price;
	nrC = strlen(aux->type) + 1;
	o2->type = malloc(sizeof(char) * nrC);
	strcpy_s(o2->type, nrC,aux->type);
	nrC = strlen(aux->destination) + 1;
	o2->destination = malloc(sizeof(char) * nrC);
	strcpy_s(o2->destination, nrC, aux->destination);
	//o2=aux
}
void ascending_order_by_price_and_destination(MyVector* v, char* d)
{ 
	filter_by_destination(v, d);
	ElemType aux;
	for (int i = 0; i < v->lg - 1; i++) {
		for (int j = i + 1; j < v->lg; j++) {
			if (v->elems[i].price > v->elems[j].price) {
				changeOffer(&v->elems[i], &v->elems[j]);
			}
		}
	}

}

void descending_order_by_price_and_destination(MyVector* v, char* d)
{
	filter_by_destination(v, d);
	Offer aux;
	for (int i = 0; i < v->lg - 1; i++) {
		for (int j = i + 1; j <v->lg; j++) {
			if (v->elems[i].price < v->elems[j].price) {
				changeOffer(&v->elems[i], &v->elems[j]);
			}
		}
	}

}