/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "array_list.h"


//#include "array_list.h"

void init_array_list(Array_list l)
{
    l->index = -1;
}
void insert_at(Array_list l, int position, float value)
{
    l->data[position] = value;
}

void add(Array_list l, float value)
{
    if (l->index < ARRAY_LIST_MAX_SIZE -1)
    {
        index ++;
        l->data[l->index] =value;
    }
}

float remove_at(Array_list l, int position);
float get_at(Array_list l, int position);
void clear(Array_list l);