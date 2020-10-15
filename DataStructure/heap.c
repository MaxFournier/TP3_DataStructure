/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "heap.h"

void init_heap(Heap *h)
{
    h->index =-1;
}

bool is_heap_empty(Heap *h)
{
    if(h->index == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float pop(Heap *h); //pop the root value
void push(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek(Heap *h); // return root value but dont remove it

//En option
void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
void merge(Heap *dest, Heap *src); //merge src into dest