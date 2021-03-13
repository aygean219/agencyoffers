#include "teste.h"
#include <assert.h>
void test_create_destory()
{
	date d1;
	d1.day = 11;
	d1.month = 12;
	d1.year = 2021;
	Offer o = createOffer("city_break","Dubai",d1,1000);
	assert((o.date.day==11)&&(o.date.month == 12)&&(o.date.year == 2021));
	assert(strcmp(o.destination, "Dubai") == 0);
	assert(strcmp(o.type, "city_break") == 0);
	assert(o.price== 1000);
	destroyOffer(&o);

}
void test_validate()
{
	date d1;
	d1.day = 11;
	d1.month = 12;
	d1.year = 2021;
	Offer o = createOffer("city_break", "Dubai", d1, 1000);
	assert((o.date.day == 11) && (o.date.month == 12) && (o.date.year == 2021));
	assert(strcmp(o.destination, "Dubai") == 0);
	assert(strcmp(o.type, "city_break") == 0);
	assert(o.price == 1000);
	assert(validate_type(o) == 0);
	assert(validate_price(o) == 0);
	assert(validate_destination(o) == 0);
	assert(validate_date(o) == 0);
	date d2;
	d2.day = 32;
	d2.month = 13;
	d2.year = 1999;
	Offer o1 = createOffer("city", "", d2, -1);
	assert((o1.date.day ==32) && (o1.date.month == 13) && (o1.date.year ==1999));
	assert(strcmp(o1.destination, "") == 0);
	assert(strcmp(o1.type, "city") ==0);
	assert(o1.price == -1);
	assert(validate_type(o1) == 1);
	assert(validate_price(o1) == 1);
	assert(validate_destination(o1) == 1);
	assert(validate_date(o1) == 1);
}

void test_add_offer()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 =get(&v,0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination,"Dubai")==0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day ==11);
	assert(v.elems[1].date.month==2);
	assert(v.elems[2].date.year==2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	destroy(&v);
	assert(size(&v) == 0);
}

void test_update_offer()
{

	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price== 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	update(&v, o1, o3);
	update(&v, o2, o3);
	assert(v.elems[0].price == 500);
	assert(v.elems[1].price == 500);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Alpi") == 0);
	assert(strcmp(v.elems[1].destination, "Alpi") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 23);
	assert(v.elems[1].date.month == 9);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "munte") == 0);
	assert(strcmp(v.elems[1].type, "munte") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);

}
void test_delete_offer()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	del(&v, o1);
	assert(size(&v) == 2);
	assert(strcmp(v.elems[0].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[1].destination, "Alpi") == 0);
	del(&v, o2);
	assert(size(&v) == 1);
	assert(strcmp(v.elems[0].destination, "Alpi") == 0);
	del(&v, o3);
	assert(size(&v) == 0);

	
}
void test_copy()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);

	Offer o4 = copyOffer(&v.elems[2]);
	assert(o4.price == 500);
	assert(strcmp(o4.type, "munte") == 0);

	MyVector vv = copyList(&v);
	assert(size(&vv) == 3);
	assert(vv.elems[0].price == 1000);
	assert(vv.elems[1].price == 4000);
	assert(vv.elems[2].price == 500);
	assert(strcmp(vv.elems[0].destination, "Dubai") == 0);
	assert(strcmp(vv.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(vv.elems[2].destination, "Alpi") == 0);
	assert(vv.elems[0].date.day == 11);
	assert(vv.elems[1].date.month == 2);
	assert(vv.elems[2].date.year == 2021);
	assert(strcmp(vv.elems[0].type, "city_break") == 0);
	assert(strcmp(vv.elems[1].type, "mare") == 0);
	assert(strcmp(vv.elems[2].type, "munte") == 0);

}
void test_filter_by_destination()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Dubai",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Dubai", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	filter_by_destination(&v, "Dubai");
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
}
void test_filter_by_type()
{
	Offer o1 = { "mare","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("mare", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "mare") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	filter_by_type(&v, "mare");
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(strcmp(v.elems[0].type, "mare") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
}
void test_filter_by_price()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Bora Bora",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Bora Bora", d2, 4000));
	add(&v, createOffer("munte", "Alpi", d3, 4000));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 4000);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[2].destination, "Alpi") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	filter_by_price(&v, 4000);
	assert(v.elems[0].price == 4000);
	assert(v.elems[1].price == 4000);
	assert(strcmp(v.elems[0].destination, "Bora Bora") == 0);
	assert(strcmp(v.elems[1].destination, "Alpi") == 0);
	assert(v.elems[0].date.month == 2);
	assert(v.elems[1].date.year == 2021);
	assert(strcmp(v.elems[0].type, "mare") == 0);
	assert(strcmp(v.elems[1].type, "munte") == 0);
}
void test_ascending_order_by_price_and_destination()
{

	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Dubai",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Dubai", d2, 4000));
	add(&v, createOffer("munte", "Dubai", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(strcmp(v.elems[2].destination, "Dubai") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	ascending_order_by_price_and_destination(&v, "Dubai");
	assert(v.elems[0].price ==500);
	assert(v.elems[1].price == 1000);
	assert(v.elems[2].price == 4000);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(v.elems[1].date.day == 11);
	assert(v.elems[2].date.month == 2);
	assert(strcmp(v.elems[1].type, "city_break") == 0);
	assert(strcmp(v.elems[2].type, "mare") == 0);

}
void test_descending_order_by_price_and_destination()
{
	Offer o1 = { "city_break","Dubai",{11,12,2021},1000 };
	Offer o2 = { "mare","Dubai",{6,2,2022},4000 };
	Offer o3 = { "munte","Alpi",{23,9,2021},500 };
	MyVector v = createEmpty();
	assert(size(&v) == 0);
	date d1 = { 11,12,2021 };
	date d2 = { 6,2,2022 };
	date d3 = { 23,9,2021 };
	add(&v, createOffer("city_break", "Dubai", d1, 1000));
	add(&v, createOffer("mare", "Dubai", d2, 4000));
	add(&v, createOffer("munte", "Dubai", d3, 500));
	assert(size(&v) == 3);
	Offer oo1 = get(&v, 0);
	Offer oo2 = get(&v, 1);
	Offer oo3 = get(&v, 2);
	assert(v.elems[0].price == 1000);
	assert(v.elems[1].price == 4000);
	assert(v.elems[2].price == 500);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(strcmp(v.elems[2].destination, "Dubai") == 0);
	assert(v.elems[0].date.day == 11);
	assert(v.elems[1].date.month == 2);
	assert(v.elems[2].date.year == 2021);
	assert(strcmp(v.elems[0].type, "city_break") == 0);
	assert(strcmp(v.elems[1].type, "mare") == 0);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	descending_order_by_price_and_destination(&v, "Dubai");
	assert(v.elems[2].price == 500);
	assert(v.elems[1].price == 1000);
	assert(v.elems[0].price == 4000);
	assert(strcmp(v.elems[1].destination, "Dubai") == 0);
	assert(strcmp(v.elems[0].destination, "Dubai") == 0);
	assert(v.elems[1].date.day == 11);
	assert(v.elems[0].date.month == 2);
	assert(strcmp(v.elems[2].type, "munte") == 0);
	assert(strcmp(v.elems[1].type, "city_break") == 0);
	assert(strcmp(v.elems[0].type, "mare") == 0);

}
void test_all()
{
	test_create_destory();
	test_validate();
	test_add_offer();
	test_update_offer();
	test_delete_offer();
	test_copy();
	test_filter_by_destination();
	test_filter_by_type();
	test_filter_by_price();
	test_ascending_order_by_price_and_destination();
	test_descending_order_by_price_and_destination();
}