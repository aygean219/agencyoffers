#pragma once
#include "Vector.h"
#include "Offer.h"
#include <stdlib.h>
#include <stdio.h>
void add_ui(MyVector* v);
void upd_ui(MyVector* v);
void del_ui(MyVector* v);
void filter_by_destination_ui(MyVector* v);
void filter_by_type_ui(MyVector* v);
void filter_by_price_ui(MyVector* v);
void ascending_order_by_price_and_destination_ui(MyVector* v);
void descending_order_by_price_and_destination_ui(MyVector* v);
void meniu();
void aplicatie(MyVector* v);
