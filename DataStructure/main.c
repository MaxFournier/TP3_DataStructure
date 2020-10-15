/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * @author: Max Fournier
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "stack.h"
#include "heap.h"
#include "array_list.h"
#include "queue.h"

/**
 *Fonction de test Stack 
 * pas de parametre
 */
void testStack()
{
    Stack *s = malloc(sizeof(char)*100);
    
    //test init et is_empty
    init_stack(s);
    assert(is_stack_empty(s) == true ); //reussite
    
    //test push
    pushStack(s,5);
    pushStack(s,4);
    pushStack(s,3);
    pushStack(s,2);
    pushStack(s,1);
    assert(is_stack_empty(s) == false); //reussite
    
    //test pop
    float temp = popStack(s);
    temp = popStack(s);
    assert(popStack(s) == 3 ); //reussite
    //assert(popStack(s) == 3 ); //erreur
    
    //test dup et test peek
    pushStack(s,7);
    dup(s); //le dub marche
    assert(popStack(s) == 7 );//reussite
    //assert(popStack(s) == 7 );
    assert(peekStack(s) == 7 );//reussite
    
    //test swap
    pushStack(s,5);    
    pushStack(s,8);
    swap(s); //fonctionne
    assert(popStack(s) == 5 ); //reussite
    assert(peekStack(s) == 8 ); //reussite
    
    //test clear
    clearStack(s); //reussite
    assert(is_stack_empty(s)==true);
    
}

/**
 *Fonction de test Heap 
 * pas de parametre
 */
void testHeap()
{
    Heap *h = malloc(sizeof(char)*100);
    
    //test init et is_empty
    init_heap(h);
    assert(is_heap_empty(h)==true);//reussite
    
    //test push et pop
    pushHeap(h,2);
    pushHeap(h,1);
    pushHeap(h,3);
    pushHeap(h,5);
    pushHeap(h,4);
    assert(popHeap(h)==5);//reussite
    
    //test peek
    assert (peekHeap(h)==4); //reussite
    //assert (peekHeap(h)==5); //echec
    pushHeap(h,6);
    assert (peekHeap(h)==6); //reussite
    
    //test replace
    assert (replace(h,1)==6); //reussite
    assert (peekHeap(h)==4); //reussite
    
    assert (replace(h,6)==4); //reussite
    assert (peekHeap(h)==6); //reussite
    
    //test heapify
    size_t size = 3;
    float test[] = {1,3,6}; ;
    
    heapify(h,test,size);
    assert (peekHeap(h)==6); //reussite
    
    //test merge
    Heap *src = malloc(sizeof(char)*100);
    init_heap(src);
    pushHeap(src,20);
    pushHeap(src,5);
    pushHeap(src,2);
    
    merge(h,src);
    assert(popHeap(h)==20); //reussite
    assert (peekHeap(h)==6); //reussite
    

}

/**
 * fonction de test de l'Array list
 * pas de parametre
 */
void testArrayList()
{
    Array_list *l = malloc(sizeof(char)*100);
    
    //test add et get_at
    init_array_list(l);
    add(l,4);
    add(l,2);
    add(l,1);
    assert (get_at(l,0)==4);//reussite
    assert (get_at(l,1)==2);//reussite
    assert (get_at(l,2)==1); //reussite
    
    //test insert_at
    insert_at (l,2,3);
    assert (get_at(l,1)==2);//reussite
    assert (get_at(l,2)==3); //reussite
    assert (get_at(l,3)==1);//reussite
    
    // test remove at
    assert (remove_at(l,3) == 1);
    assert (get_at(l,1)==2);
    
    //test clear
    assert (get_at(l,0)==4); //reussite
    clearArray(l);
    //assert (get_at(l,0)==4); //echec
    
}

/**
 *fonction de test de la file (Queue)
 *  pas de parametre
 */
void testQueue()
{ 
    Queue *q = malloc(sizeof(char)*100);
    
    //test init et is empty
    init_queue(q); //reussite
    assert(is_queue_empty(q)==true);
    
    //test enqueue et dequeue
    enqueue(q,5); 
    enqueue(q,4);
    enqueue(q,3);
    enqueue(q,2);
    enqueue(q,1); 
    assert(is_queue_empty(q)==false); //reussite
    assert(dequeue(q) == 5); //reussite
    assert(dequeue(q) == 4);//reussite
    //assert(dequeue(q) == 4);//echec calculé
    
    //test front 
    assert(front(q) == 3); //reussite
    //assert(front(q) == 2); //echec calculé
    
    //test clear
    clearQueue(q);
    assert(is_queue_empty(q)==true); //reussite
    
}

/**
 * Main
 */
int main(int argc, char** argv) {
    /**
    * tests pour verifier le bon fonctionnement du projet
    *
    * @see testStack 
    */
    testStack();
    
    /**
     * @see testQueue
     */
    testQueue();
    
    /**
     * @see testArrayList
     */
    testArrayList();
    
    /**
     * @see testHeap
     */
    testHeap();
    
    return (EXIT_SUCCESS);
}

