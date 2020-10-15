/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack.h"

void init_stack(Stack * s)
{
    s->index =-1;
}

void push(Stack * s, float value)
{
    if (s->index=!STACK_MAX_SIZE-1)
    {
        s->index += 1;
        s->data[s->index] = value;
    }
    else
    {
        printf("Impossible d'ajouter une valeur, le tableau a deja atteint sa taille maximum");
    }
}

float pop(Stack * s)
{
    if (index =! -1)
    {
        index --;
        return s->data[s->index+1];
    }
    else
    {
        printf("Pas de donnée");
        return 0;
    }
}

bool is_stack_empty(Stack * s)
{
    if(s->index == -1)
      return true;
   else
      return false;
}

float peek(Stack * s) // aka top or front
{
    if (s->index =! -1)
    {
        return s->data[s->index];
    }
    else
    {
        printf("Pas de donnée");
        return 0;
    }
}
void dup(Stack * s)
{
    if (s->index>=0 && s->index < STACK_MAX_SIZE-1)
    {
        s->index +=1;
        s->data[s->index] = s->data[s->index-1];        
    }
    printf("Erreur");
}

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

void clear(Stack * s)
{
    s->index =-1;
}