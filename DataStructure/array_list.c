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

#include "array_list.h"


/**
 * initialise l'arraylist
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 */


void init_array_list(Array_list *l)
{
    l->index = -1;
}

/**on insere un valeur dans la liste a une position donnée
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @param position
 *      position ou inserer la valeur
 * @param value
 *      valeur a inserer
 */
void insert_at(Array_list *l, int position, float value)
{
    if (l->index !=-1 && l->index>=position)
    {
        l->index ++;
        
        //decalage des valeurs
        for (int i = position ; i<l->index;i++)
        {
            l->data[l->index] = l->data[l->index -1];
        }
        
        l->data[position] = value;
    }
    else
    {
        printf("Erreur");
    }
}

/**ajoute une nouvelle valeur a la fin de la liste
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @param value
 *      valeur a ajouter
 */
void add(Array_list *l, float value)
{
    if (l->index < ARRAY_LIST_MAX_SIZE -1)
    {
        l->index ++;
        l->data[l->index] =value;
    }
    else
    {
        printf("Erreur");
    }
}

/**
 * Supprime une valeur de la liste a une position donnée
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @param position
 *      position de la valeur a suprimmer
 * @return 
 *      retourne la valeur supprimée
 */
float remove_at(Array_list *l, int position)
{
    if (l->index !=-1 && l->index>=position)
    {
        float temp = l->data[position];
        
        //decalage du tableau
        for (int i = position ; i < l->index ;i++)
        {
            l->data[l->index] = l->data[l->index + 1];
        }        
        
        l->index--;
        
        return temp;
    }
    else
    {
        printf("Erreur");
        //return -1;
    }
}

/**
 * renvoit la donnée d'une position donnée
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 * @param position
 *      positin de la valeur a retourner
 * @return 
 *      valeur de la position demandée
 */
float get_at(Array_list *l, int position)
{
    if (l->index !=-1 && l->index>=position)
    {
        return l->data[position];
    }
    else
    {
        printf("Erreur");
        //return -1;
    }
}

/**Permet de retirer toute les valeurs du tableau 
 * 
 * @param l
 *      comprend  : un tableau une liste de float et la position de la derniere valeur du tableau
 */
void clearArray(Array_list *l)
{
    l->index = -1;
}