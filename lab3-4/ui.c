#pragma once
#include "ui.h"
void add_ui(MyVector* v)
{
	char t[20] = { 0 };
	char d[20] = { 0 };
	int p,zi,luna,an;
	printf("Dati tipul calatoriei (cityBreak/mare/munte)pe care doriti sa-l adaugati: ");
	scanf_s("%s", &t, (unsigned)_countof(t));
	printf("Dati destinatia calatoriei pe care doriti sa-l adaugati: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Dati data calatoriei pe care doriti sa-l adaugati: Zi: ");
	scanf_s("%d", &zi);
	printf("Luna: ");
	scanf_s("%d", &luna);
	printf("An: ");
	scanf_s("%d",&an);
	printf("Dati pretul calatoriei pe care doriti sa-l adaugati: ");
	scanf_s("%d", &p);
	date dd;
	dd.day = zi;
	dd.month = luna;
	dd.year = an;
	Offer oo = createOffer(t, d, dd, p);
	int ok = 0;
	if (validate_type(oo) != 0)
	{
		printf("Tipul trebuie sa fie :cityBreak/mare/munte!!!\n");
		ok = 1;
	}
	if (validate_destination(oo) != 0)
	{
		printf("Destinatia trebuie introdusa!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 1)
	{
		printf("Ziua trebuie sa fie intre 1-31!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 2)
	{
		printf("Luna trebuie sa fie intre 1-12!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 3)
	{
		printf("Anul trebuie sa fie mai mare decate 2020!!\n");
		ok = 1;
	}
	if (validate_price(oo) != 0)
	{
		printf("Pretul trebuie sa fie pozitiv si mai mare decat 500$!!\n");
		ok = 1;
	}
	if (ok == 0)
	{
		add(v, oo);
		printf("Oferta a fost adaugata cu succes!!\n");
	}
	else
	{
		destroyOffer(&oo);
		printf("Reincercati,adaugarea nu s-a realizat!!\n");
	}
}
void del_ui(MyVector* v)
{
	char t[20] = { 0 };
	char d[20] = { 0 };
	int p, zi, luna, an;
	printf("Dati tipul calatoriei (cityBreak/mare/munte)pe care doriti sa-l stergeti: ");
	scanf_s("%s", &t, (unsigned)_countof(t));
	printf("Dati destinatia calatoriei pe care doriti sa-l stergeti: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Dati data calatoriei pe care doriti sa-l stergeti: Zi: ");
	scanf_s("%d", &zi);
	printf("Luna: ");
	scanf_s("%d", &luna);
	printf("An: ");
	scanf_s("%d", &an);
	printf("Dati pretul calatoriei pe care doriti sa-l stergeti: ");
	scanf_s("%d", &p);
	date dd;
	dd.day = zi;
	dd.month = luna;
	dd.year = an;
	Offer oo = createOffer(t, d, dd, p);
	int ok = 0;
	if (validate_type(oo) != 0)
	{
		printf("Tipul trebuie sa fie :cityBreak/mare/munte!!!\n");
		ok = 1;
	}
	if (validate_destination(oo) != 0)
	{
		printf("Destinatia trebuie introdusa!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 1)
	{
		printf("Ziua trebuie sa fie intre 1-31!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 2)
	{
		printf("Luna trebuie sa fie intre 1-12!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 3)
	{
		printf("Anul trebuie sa fie mai mare decate 2020!!\n");
		ok = 1;
	}
	if (validate_price(oo) != 0)
	{
		printf("Pretul trebuie sa fie pozitiv si mai mare decat 500$!!\n");
		ok = 1;
	}
	if (ok == 0)
	{
		del(v, oo);
		printf("Oferta a fost stearsa cu succes daca exista!!\n");
	}
	else
	{
		destroyOffer(&oo);
		printf("Reincercati,stergerea nu s-a realizat!!\n");
	}

}
void upd_ui(MyVector* v)
{
	char t[20] = { 0 };
	char d[20] = { 0 };
	int p, zi, luna, an;
	printf("Dati tipul calatoriei (cityBreak/mare/munte)pe care doriti sa-l modificati: ");
	scanf_s("%s", &t, (unsigned)_countof(t));
	printf("Dati destinatia calatoriei pe care doriti sa-l modificati: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Dati data calatoriei pe care doriti sa-l modificati: Zi: ");
	scanf_s("%d", &zi);
	printf("Luna: ");
	scanf_s("%d", &luna);
	printf("An: ");
	scanf_s("%d", &an);
	printf("Dati pretul calatoriei pe care doriti sa-l modificati: ");
	scanf_s("%d", &p);
	date dd;
	dd.day = zi;
	dd.month = luna;
	dd.year = an;
	Offer oo = createOffer(t, d, dd, p);
	int ok = 0;
	if (validate_type(oo) != 0)
	{
		printf("Tipul trebuie sa fie :cityBreak/mare/munte!!!\n");
		ok = 1;
	}
	if (validate_destination(oo) != 0)
	{
		printf("Destinatia trebuie introdusa!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 1)
	{
		printf("Ziua trebuie sa fie intre 1-31!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 2)
	{
		printf("Luna trebuie sa fie intre 1-12!!\n");
		ok = 1;
	}
	if (validate_date(oo) == 3)
	{
		printf("Anul trebuie sa fie mai mare decate 2020!!\n");
		ok = 1;
	}
	if (validate_price(oo) != 0)
	{
		printf("Pretul trebuie sa fie pozitiv si mai mare decat 500$!!\n");
		ok = 1;
	}
	if (ok == 0)
	{
		char t2[20] = { 0 };
		char d2[20] = { 0 };
		int p2, zi2, luna2, an2;
		printf("Dati noul tip al calatoriei (cityBreak/mare/munte)pe care doriti sa-l modificati: ");
		scanf_s("%s", &t2, (unsigned)_countof(t2));
		printf("Dati noua destinatie calatoriei pe care doriti sa-l modificati: ");
		scanf_s("%s", &d2, (unsigned)_countof(d2));
		printf("Dati noua data a calatoriei pe care doriti sa-l modificati: Zi: ");
		scanf_s("%d", &zi2);
		printf("Luna: ");
		scanf_s("%d", &luna2);
		printf("An: ");
		scanf_s("%d", &an2);
		printf("Dati noul pret al calatoriei pe care doriti sa-l modificati: ");
		scanf_s("%d", &p2);
		date dd2;
		dd2.day = zi2;
		dd2.month = luna2;
		dd2.year = an2;
		Offer oo2 = createOffer(t2, d2, dd2, p2);
		int ok2 = 0;
		if (validate_type(oo2) != 0)
		{
			printf("Tipul trebuie sa fie :cityBreak/mare/munte!!!\n");
			ok2 = 1;
		}
		if (validate_destination(oo2) != 0)
		{
			printf("Destinatia trebuie introdusa!!\n");
			ok2 = 1;
		}
		if (validate_date(oo2) == 1)
		{
			printf("Ziua trebuie sa fie intre 1-31!!\n");
			ok2 = 1;
		}
		if (validate_date(oo2) == 2)
		{
			printf("Luna trebuie sa fie intre 1-12!!\n");
			ok2 = 1;
		}
		if (validate_date(oo2) == 3)
		{
			printf("Anul trebuie sa fie mai mare decate 2020!!\n");
			ok2 = 1;
		}
		if (validate_price(oo2) != 0)
		{
			printf("Pretul trebuie sa fie pozitiv si mai mare decat 500$!!\n");
			ok2 = 1;
		}
		if (ok2 == 0)
		{
			update(v, oo, oo2);
			printf("Modificarea s-a realizat cu succes daca oferta exista!!\n");
		}
		else
		{
			destroyOffer(&oo2);
			destroyOffer(&oo);
			printf("Reincercati,modificarea nu s-a realizat!!\n");
		}
	}
	else
	{
		printf("Reincercati,modificarea nu s-a realizat!!\n");
	}
	
}
void filter_by_destination_ui(MyVector* v)
{	
	MyVector vv = copyList(v);
	char d[20] = { 0 };
	printf("Dati destinatia calatoriilor pe care doriti sa le vedeti: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Ofertele sunt urmatoarele : \n");
	filter_by_destination(&vv, d);
	for (int i = 0; i < vv.lg; i++)
	{
		printf("OFERTA--->Tip: %s ,Destinatie: %s ,Data plecarii: Zi: %d,Luna: %d,An: %d ,Pret: %d $;\n", vv.elems[i].type, vv.elems[i].destination, vv.elems[i].date.day, vv.elems[i].date.month, vv.elems[i].date.year, vv.elems[i].price);
	}
	destroy(&vv);
}
void filter_by_type_ui(MyVector* v)
{
	MyVector vv = copyList(v);
	char t[20] = { 0 };
	printf("Dati tipul calatoriilor pe care doriti sa le vedeti: ");
	scanf_s("%s", &t, (unsigned)_countof(t));
	printf("Ofertele sunt urmatoarele : \n");
	filter_by_type(&vv, t);
	for (int i = 0; i < vv.lg; i++)
	{
		printf("OFERTA--->Tip: %s ,Destinatie: %s ,Data plecarii: Zi: %d,Luna: %d,An: %d ,Pret: %d $;\n", vv.elems[i].type, vv.elems[i].destination, vv.elems[i].date.day, vv.elems[i].date.month, vv.elems[i].date.year, vv.elems[i].price);
	}
	destroy(&vv);
}
void filter_by_price_ui(MyVector* v)
{
	MyVector vv = copyList(v);
	int p;
	printf("Dati pretul calatoriilor pe care doriti sa le vedeti: ");
	scanf_s("%d", &p);
	printf("Ofertele sunt urmatoarele : \n");
	filter_by_price(&vv, p);
	for (int i = 0; i < vv.lg; i++)
	{
		printf("OFERTA--->Tip: %s ,Destinatie: %s ,Data plecarii: Zi: %d,Luna: %d,An: %d ,Pret: %d $;\n", vv.elems[i].type, vv.elems[i].destination, vv.elems[i].date.day, vv.elems[i].date.month, vv.elems[i].date.year, vv.elems[i].price);
	}
	destroy(&vv);
}
void ascending_order_by_price_and_destination_ui(MyVector* v)
{
	MyVector vvv = copyList(v);
	char d[20] = { 0 };
	printf("Dati destinatia calatoriilor pe care doriti sa le vedeti ordonate crescator: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Ofertele sunt urmatoarele : \n");
	MyVector* vv;
	vv=ascending_order_by_price_and_destination(&vvv, d);
	for (int i = 0; i < vv->lg; i++)
	{
		printf("OFERTA--->Tip: %s ,Destinatie: %s ,Data plecarii: Zi: %d,Luna: %d,An: %d ,Pret: %d $;\n", vv->elems[i].type, vv->elems[i].destination, vv->elems[i].date.day, vv->elems[i].date.month, vv->elems[i].date.year, vv->elems[i].price);
	}
	destroy(&vvv);
	destroy(vv);
}
void descending_order_by_price_and_destination_ui(MyVector* v)
{
	MyVector vvv = copyList(v);
	char d[20] = { 0 };
	printf("Dati destinatia calatoriilor pe care doriti sa le vedeti ordonate descrescator: ");
	scanf_s("%s", &d, (unsigned)_countof(d));
	printf("Ofertele sunt urmatoarele : \n");
	MyVector* vv;
	vv = descending_order_by_price_and_destination(&vvv, d);
	for (int i = 0; i < vv->lg; i++)
	{
		printf("OFERTA--->Tip: %s ,Destinatie: %s ,Data plecarii: Zi: %d,Luna: %d,An: %d ,Pret: %d $;\n", vv->elems[i].type, vv->elems[i].destination, vv->elems[i].date.day, vv->elems[i].date.month, vv->elems[i].date.year, vv->elems[i].price);
	}
	destroy(&vvv);
	destroy(vv);
}
void meniu()
{
	printf("1.Adaugare oferta noua!\n");
	printf("2.Update oferta existenta!\n");
	printf("3.Stergere oferta existenta!\n");
	printf("4.Filtrare dupa destinatie!\n");
	printf("5.Filtrare dupa pret!\n");
	printf("6.Filtrare dupa tip!\n");
	printf("7.Afisarea ordonata crescator dupa pret pentru o anumita destinatie!\n");
	printf("8.Afisarea ordonata descrescator dupa pret pentru o anumita destinatie!\n");
	printf("9.Afisare oferte existente!\n");
	printf("10.Exit!\n");
}
void show_agency(MyVector* v)
{
	printf("TIP--------------------DESTINATIE------------ZI------------LUNA---------------AN---------------PRET\n");
	for (int i = 0; i < v->lg; i++)
	{
		if (strcmp(v->elems[i].type, "cityBreak") != 0) {
			if (strcmp(v->elems[i].type, "mare") == 0) {
				printf("%s                     %s               %d               %d               %d              %d$\n", v->elems[i].type, v->elems[i].destination, v->elems[i].date.day, v->elems[i].date.month, v->elems[i].date.year, v->elems[i].price);
			}
			else
			{
				printf("%s                   %s               %d               %d               %d              %d$\n", v->elems[i].type, v->elems[i].destination, v->elems[i].date.day, v->elems[i].date.month, v->elems[i].date.year, v->elems[i].price);
			}
			}
		else
		{
			printf("%s               %s               %d               %d               %d              %d$\n", v->elems[i].type, v->elems[i].destination, v->elems[i].date.day, v->elems[i].date.month, v->elems[i].date.year, v->elems[i].price);
		}
	}
}
void aplicatie(MyVector* v)
{
	printf("----------------------------BUN VENIT----------------------------\n");
	int opt;
	int gata = 0;
	while (!gata)
	{
		meniu();
		scanf_s("%d", &opt);
		switch (opt)
		{
		case 1: {add_ui(v); show_agency(v); break; }
		case 2: {upd_ui(v); show_agency(v); break; }
		case 3: {del_ui(v); show_agency(v); break; }
		case 4: {filter_by_destination_ui(v);break; }
		case 5: {filter_by_price_ui(v); break; }
		case 6: {filter_by_type_ui(v); break; }
		case 7: {ascending_order_by_price_and_destination_ui(v); break; }
		case 8: {descending_order_by_price_and_destination_ui(v); break; }
		case 9: {show_agency(v); break; }
		case 10: {printf("----------------------------RAMAS BUN----------------------------\n"); gata = 1; break; }

		}
	}

}