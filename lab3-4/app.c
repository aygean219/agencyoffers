#define _CRTDBG_MAP_ALLOC  
#include "ui.h"
#include "teste.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>  
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	test_all();
	printf("%s", "Teste trecute!\n");
	MyVector v = createEmpty();
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	date d4 = { 20,2,2022 };
	date d5 = { 14,4,2023 };
	date d6 = { 19,4,2023 };
	date d7 = { 15,6,2022 };
	date d8 = { 1,7,2024 };
	date d9 = { 17,10,2022 };
	add(&v, createOffer("cityBreak", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora", d2, 3300));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	add(&v, createOffer("cityBreak", "Qatar", d4, 7800));
	add(&v, createOffer("mare", "Bora", d5, 4900));
	add(&v, createOffer("munte", "Alpi", d6, 500));
	add(&v, createOffer("cityBreak", "China", d7, 2400));
	add(&v, createOffer("mare", "Bora", d8, 4200));
	add(&v, createOffer("cityBreak", "Paris", d9, 500));
	aplicatie(&v);
	destroy(&v);
	_CrtDumpMemoryLeaks();
	return 0;
}