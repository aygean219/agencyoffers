#include "ui.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
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
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "BoraBora", d2, 3300));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	add(&v, createOffer("city_break", "Qatar", d4, 7800));
	add(&v, createOffer("mare", "BoraBora", d5, 4900));
	add(&v, createOffer("munte", "Carpati", d6, 500));
	add(&v, createOffer("city_break", "China", d7, 2400));
	add(&v, createOffer("mare", "BoraBora", d8, 4200));
	add(&v, createOffer("city_break", "Paris", d9, 500));
//	aplicatie(&v);
	return 0;
}