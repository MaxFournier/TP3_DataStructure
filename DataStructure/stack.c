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

#include "stack.h"

/**
 * initialisation de la pile
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau 
 */
void init_stack(Stack * s)
{
    s->index =-1;
}

/**
 *  ajoute une valeur au sommet de la pile
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @param value
 *      valeur a ajouter
 */
void pushStack(Stack * s, float value)
{
    if (s->index < STACK_MAX_SIZE-1)
    {
        s->index ++;
        s->data[s->index] = value;
    }
    else
    {
        printf("Impossible d'ajouter une valeur, le tableau a deja atteint sa taille maximum");
    }
}

/**
 * supprime et renvoie la valeur au sommet de la pile
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @return 
 *      retourne la valeur suprimmée de la pile
 */
float popStack(Stack * s)
{
    if (is_stack_empty(s))
    {
        printf("\nPas de donnée");
        //return -1;
    }
    else
    {           
        float temp = s->data[s->index];
        s->index --;
        return temp;
    }
}

/**
 * permet de savoir si la pile est vide ou non
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @return 
 *      retourne un bool montrant si la pile est vide ou non
 */
bool is_stack_empty(Stack * s)
{
    if(s->index == -1)
      return true;
   else
      return false;
}

/**
 * retourne la valeur au sommet de la liste
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @return
 *      valeur au sommet de la pile 
 */
float peekStack(Stack * s) // aka top or front
{
    if (is_stack_empty(s) == false)
    {
        return s->data[s->index];
    }
    else
    {
        printf("Pas de donnée");
        //return -1;
    }
}

/**
 *  duplique la valeur au sommet de la pile
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 */
void dup(Stack * s)
{
    if (is_stack_empty(s) == false && s->index < STACK_MAX_SIZE-1)
    {
        s->index +=1;
        s->data[s->index] = s->data[s->index-1];        
    }
    else
    {
        printf("Erreur");
    }
}

/**
 * echange les deux valeur au sommet de la pile
 *
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 */
void swap(Stack * s)
{
    float temp;
    
    if (s->index>=1)
    {
        temp = s->data[s->index];
        s->data[s->index] = s->data[s->index-1];
        s->data[s->index-1] = temp;        
    }
    else
    {
        printf("Le tableau ne possede pas assez de valeur");
    }
}

/**
 * Efface toutes les données de la pile
 * 
 * @param s
 *      pile, comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 */
void clearStack(Stack * s)
{
    s->index =-1;
}