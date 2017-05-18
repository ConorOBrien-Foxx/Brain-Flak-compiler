#include <stdio.h>
#include <stdlib.h>

#define num_type long
#define NUM_FMT "%ld"
#define OUT_TYPE long

typedef enum { AT_FIRST, AT_SECOND } current_stack_pointer;

typedef struct stack {
    size_t capacity;
    size_t size;
    num_type* data;
} stack;

void stack_init(stack* stk, size_t init_capacity){
    stk->data = malloc(init_capacity * sizeof(num_type));
    stk->capacity = init_capacity;
    stk->size = 0;
}

void stack_resize(stack* stk, size_t new_size){
    stk->data = realloc(stk->data, new_size * sizeof(num_type));
    stk->capacity = new_size;
    if(stk->size > new_size)
        stk->size = new_size;
}

void stack_push(stack* stk, num_type el){
    stk->data[stk->size++] = el;
    if(stk->size > stk->capacity)
        stack_resize(stk, stk->capacity * 2);
}

num_type stack_peek(stack* stk){
    return stk->size == 0 ? 0 : stk->data[stk->size - 1];
}

num_type stack_pop(stack* stk){
    num_type res = stack_peek(stk);
    if(stk->size)
        stk->size--;
    return res;
}

void stack_display(stack* stk){
    size_t i = stk->size;
    if(i == 0) return;
    while(i --> 0){
        printf(NUM_FMT, (OUT_TYPE) stk->data[i]);
    }
}