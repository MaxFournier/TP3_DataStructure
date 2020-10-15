/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#include "queue.h"

/**
 * initialisation de la file
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 */
void init_queue(Queue *q)
{
    q->front =-1;
    q->rear=-1;
}

/**
 * ajoute une valeur en bout de file
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 * @param value
 *      valeur a ajouter
 */
void enqueue(Queue *q, float value)
{
    if (q->rear < QUEUE_MAX_SIZE-1)
    {
        if (q->front ==-1)
        {
            q->front = 0;
        }
        q->rear ++;
        q->data[q->rear] = value;
    }
    else
    {
        printf("Impossible d'ajouter une valeur, le tableau a deja atteint sa taille maximum");
    }
}

/**
 * suprimme et retourne la valeur de debut de file
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 * @return 
 */
float dequeue(Queue *q)
{
    if (q->front > -1)
    {
        int temp = q->front;
        
        q->front++;
        
        //s'il n'y a plus de valeur dans le tableau
        if (q->front > q->rear)
        {
          q->front = q->rear = -1;
        }
        
        return q->data[temp];
        
    }
    else
    {
        printf("Pas de donnée");
        //return -1;
    }
}

/**
 * Permet de savoir si la file est vide ou non
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 * @return 
 *      retourne un bool qui indique l'état du tableau
 */
bool is_queue_empty(Queue *q)
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

/**
 * retourne la valeur de debut de file
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 * @return 
 *      retourne la valeur de debut de file
 */
float front(Queue *q) //aka peek
{
    if (q->front > -1)
    {
        return q->data[q->front];        
    }
    else
    {
        printf("Pas de donnée");
        //return -1;
    }
}

/**
 *   effacement des données de la file
 * 
 * @param q
 *      file, comprend  : un tableau une liste de float et la position de premiere et de la derniere valeur du tableau
 */
void clearQueue(Queue *q)
{
    q->front =-1;
    q->rear=-1;
}