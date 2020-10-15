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
#include "heap.h"

/**
 * fonction pour trier en un tas 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 */
 void sort(Heap *h)
{
    int i, j, fils, fils2;
    float stock;
    
    //on range le tableau pour faire un tas
    for (i = 0; i <= h->index / 2; i++) {

        //on calcule la position de la valeur fils
        fils = 2 * i + 1;
        fils2 = 2 * i + 2;

        //on compare la valeur fils et la valeur pere
        if (h->data[fils] > h->data[i]) {

            j = fils;

            //tant que la valeur fils est plus grande que la valeur pere et valeur pere > 0 on echange
            while (j > 0 && h->data[j] > h->data[(j - 1) / 2]) {
                stock = h->data[j];
                h->data[j] = h->data[(j - 1) / 2];
                h->data[(j - 1) / 2] = stock;

                j = (j - 1) / 2;
            }
        }

        //meme comparaison mais on verifie en plus que la valeur fils de cette position existe
        if (h->data[fils2] > h->data[i] && fils2 <= h-> index) {
            j = fils2;
            //tant que la valeur fils est plus grande que la valeur pere et valeur pere > 0 on echange
            while (j > 0 && h->data[j] > h->data[(j - 1) / 2]) {
                stock = h->data[j];
                h->data[j] = h->data[(j - 1) / 2];
                h->data[(j - 1) / 2] = stock;
                j = (j - 1) / 2;
            }
        }

    }//fin du rangement

}

 /**
  * initialisation  de h
  * 
  * @param h 
  *    comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
  */
void init_heap(Heap *h)
{
    h->index =-1;
}

/**
 * Permet de savoir si h est vide ou non
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @return 
 *      bool montrant sir h->data est vide ou non
 */
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

/**
 * 
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @return 
 *      retourne la valeur la racine du tableau une fois celle ci retirée 
 */
float popHeap(Heap *h) //pop the root value
{
    if(h->index != -1)
    {
        float temp = h->data[0];
        h->data[0]= h->data[h->index];
        
        h->index --;
        
        /**
         * @see sort 
         */
        sort(h);
        return temp;
    }
    else
    {
        printf("Erreur");
        //return -1;
    }
}

/**
 * ajoute une valeur au tableau h->data
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @param value
 *          valeur a ajouter au tableau
 */
void pushHeap(Heap *h, float value)
{
    if (h->index < HEAP_MAX_SIZE-1)
    {
        h->index++;
        h->data [h->index] = value;
        /**@see sort*/
        sort(h);
    }
    else
    {
        printf("Erreur");
    }
}

/**
 * Supprime la valeur en racine et ajoute une nouvelle valeur au tableau
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @param value
 *      valeur ajoutée au tableau
 * @return 
 *      retourne la valeur supprimée du tableau
 */
float replace(Heap *h, float value) // pop root and push a new key.
{
    if (h->index != -1)
    {
        float temp = h->data[0];
        h->data[0] = value;
        /**@see sort*/
        sort(h);
        return temp;
    }
    else
    {
        printf("Erreur");
        //return -1;
    }
}

/**Permet d'acceder a la valeur racine du tas
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @return 
 *      retourne la racine du tas
 */
float peekHeap(Heap *h) // return root value but dont remove it
{
    if (h->index != -1)
    {
        return h->data[0]; 
    }
    else
    {
        printf("Erreur");
        //return -1;
    }
}

//En option
/**converti un tableau en tas
 * 
 * @param h 
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @param array
 *      tableau de float
 * @param array_size
 *      taille du tableau
 */
void heapify(Heap *h, float array[], size_t array_size) //create Heap from array
{
    /**@see init_heap*/
    init_heap(h);
    
    for (int i = 0; i<array_size ; i++)
    {
        /**@see pushHeap*/
        pushHeap(h,array[i]);        
    }
}

/**fusionne deux tas
 * 
 * @param dest
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau  
 * @param src
 *      comprend  : un tableau de données rangées en tas et la position de la derniere valeur du tableau 
 *      src doit etre inseré dans l'autre tableau
 */
void merge(Heap *dest, Heap *src) //merge src into dest
{
    for (int i = 0; i<= src->index ; i++)
    {
        /**@see pushHeap*/
        pushHeap(dest,src->data[i]);
    }
}

