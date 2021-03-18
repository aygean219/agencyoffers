#define _CRTDBG_MAP_ALLOC  
#include "Vector.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <sal.h>
//_Post_ _Notnull_ ElemType* o1;
//_Post_ _Notnull_ ElemType* o2;

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

/*ElemType set(MyVector* v, int poz, Offer o)
{
	ElemType rez = v->elems[poz];
	v->elems[poz] = o;
	return rez;
} */

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
	destroyOffer(&v->elems[pos]);
	for (int i = pos; i < v->lg - 1; i++)
	{
		v->elems[i] = v->elems[i + 1];
	}
	v->lg--;
}

void update(MyVector* v, ElemType el, ElemType el_nou)
{
	for (int i = 0; i < v->lg; i++)
	{
		if ((strcmp(v->elems[i].destination, el.destination) == 0) && (strcmp(v->elems[i].type, el.type) == 0) && (v->elems[i].date.day == el.date.day) && (v->elems[i].date.month == el.date.month) && (v->elems[i].date.year == el.date.year) && (v->elems[i].price == el.price))
		{
			destroyOffer(&v->elems[i]);
			v->elems[i] = copyOffer(&el_nou);
		}
	}

}
void filter_by_destination(MyVector* v, char* d)
{
	//ElemType* nElems = malloc(sizeof(ElemType) * v->lg - 1);
	int j = 0;
	int cp = 0;
	for (int i = 0; i < v->lg; i++)
	{
		if (strcmp(v->elems[i].destination, d) == 0)
		{
			cp++;
		}
	}
	ElemType* nElems = malloc(sizeof(ElemType) *cp);
	for (int i = 0; i < v->lg; i++)
	{
		if (strcmp(v->elems[i].destination, d) == 0)
		{
			nElems[j] = copyOffer(&v->elems[i]);
			j++;
		}
		destroyOffer(&v->elems[i]);
	}
	free(v->elems);
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
			nElems[j] = copyOffer(&v->elems[i]);
			j++;
		}
		destroyOffer(&v->elems[i]);
	}
	free(v->elems);
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
			nElems[j] = copyOffer(&v->elems[i]);
			j++;
		}
		destroyOffer(&v->elems[i]);
	}
	free(v->elems);
	v->elems = nElems;
	v->lg = j;
}
void changeOffer(ElemType* o1, ElemType* o2)
{
	ElemType aux;// = malloc(sizeof(ElemType));
	aux = copyOffer(o1);
	destroyOffer(o1);

	(*o1) = copyOffer(o2);
	destroyOffer(o2);

	(*o2) = copyOffer(&aux);
	destroyOffer(&aux);
}
MyVector* ascending_order_by_price_and_destination(MyVector* vv, char* d)
{
	
	filter_by_destination(vv, d);
	sort(vv, crescator);
	return vv;
}

MyVector* descending_order_by_price_and_destination(MyVector* vv, char* d)
{
	filter_by_destination(vv, d);
	sort(vv,  descrescator);
	return vv;
}

void sort(MyVector* v, int(*compare)(void*, void*))
{
	for (int i = 0; i < v->lg - 1; i++) {
		for (int j = i + 1; j < v->lg; j++) {
			if (compare(&v->elems[i], &v->elems[j])==1) {
				changeOffer(&v->elems[i], &v->elems[j]);
				//_CrtDumpMemoryLeaks();
			}
		}
	}
	
}
int crescator(ElemType* a, ElemType* b)
{
		if (a->price > b->price)
		{
			return 1;
		}
		return 0;
	
}
int descrescator(ElemType* a, ElemType* b)
{
		if (a->price < b->price)
		{
			return 1;
		}
		return 0;
}