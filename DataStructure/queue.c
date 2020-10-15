/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "queue.h"

void init_queue(Queue q)
{
    q->front =-1;
    q->rear=-1;
}

void enqueue(Queue q, float value)
{
    if (q->rear < QUEUE_MAX_SIZE-1)
    {
        if (q->front ==-1)
        {
            front = 0;
        }
        q->rear ++;
        q->data[q->rear] = value;
    }
    else
    {
        printf("Impossible d'ajouter une valeur, le tableau a deja atteint sa taille maximum");
    }
}

float dequeue(Queue q)
{
    if (q->front > -1)
    {
        int temp = q->front;
        
        q->front++;
        
        if (q->front > q->rear)
        {
          q->front = q->rear = -1;
        }
        
        return q->data[temp];
        
    }
    else
    {
        printf("Pas de donnée");
        return 0;
    }
}

bool is_queue_empty(Queue q)
{
    if (q->front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

float front(Queue q) //aka peek
{
    if (q->front > -1)
    {
        return q->data[q->front];        
    }
    else
    {
        printf("Pas de donnée");
        return 0;
    }
}


void clear(Queue q)
{
    q->front =-1;
    q->rear=-1;
}