#include <stdio.h>
#include <stdlib.h>

typedef enum { AT_FIRST, AT_SECOND } current_stack_pointer;

typedef struct stack {
    size_t capacity;
    size_t size;
    long* data;
} stack;

void stack_init(stack* stk, size_t init_capacity){
    stk->data = malloc(init_capacity * sizeof(long));
    stk->capacity = init_capacity;
    stk->size = 0;
}

void stack_resize(stack* stk, size_t new_size){
    stk->data = realloc(stk->data, new_size * sizeof(long));
    stk->capacity = new_size;
    if(stk->size > new_size)
        stk->size = new_size;
}

void stack_push(stack* stk, long el){
    stk->data[stk->size++] = el;
    if(stk->size > stk->capacity)
        stack_resize(stk, stk->capacity * 2 + 1);
}

long stack_peek(stack* stk){
    return stk->size == 0 ? 0 : stk->data[stk->size - 1];
}

long stack_pop(stack* stk){
    long res = stack_peek(stk);
    if(stk->size)
        stk->size--;
    return res;
}

void stack_display(stack* stk){
    size_t i = stk->size;
    if(i == 0) return;
    while(i --> 0){
        printf("%ld ", stk->data[i]);
    }
}