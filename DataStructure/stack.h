/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: Max Fournier
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

#ifndef STACK_H
#define STACK_H

#define STACK_MAX_SIZE 100

typedef struct {
    float data[STACK_MAX_SIZE];
    int index;
} Stack;

#endif /* STACK_H */

void init_stack(Stack *s);
void pushStack(Stack *s, float value);
float popStack(Stack *s);
bool is_stack_empty(Stack *s);
float peekStack(Stack *s); // aka top or front
void dup(Stack *s);
void swap(Stack *s);
void clearStack(Stack *s);

