//
// Created by ross on 16/03/15.
//

#include "single-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Create a new list
*/
sll_node* sll_new_list(int value)
{
    sll_node* root;
    root = malloc(sizeof(sll_node));
    root->value = value;
    root->next = NULL;
    return root;
}

/*
* Move to end of list by returning last node
*/
sll_node* sll_traverse_to_end(sll_node* list)
{
    if (list) {
        // while not at end of list, move forward
        while(list->next != NULL) {
            list = list->next;
        }
    }

    return list;
}

/*
* Add a value to a list
*/
void sll_add_to_list(sll_node* list, int value)
{
    sll_node* final_node;
    sll_node* new_node;

    // get last node in list
    final_node = sll_traverse_to_end(list);
    new_node = malloc(sizeof(sll_node));
    final_node->next = new_node;
    // create new node
    new_node->value = value;
    new_node->next = NULL;
}

/*
* Print list forward from any point in linked list
*/
void sll_print_list(sll_node* list)
{
    for(; list; list = list->next) {
        printf("Location: %p\t", list);
        printf("Value: %d\n", list->value);
    }
}

/*
* Destroy an existing list
*/
void sll_destroy_list(sll_node* list)
{
    // for each node in list, free until null is reached
    for(sll_node* next = list; next; list = next) {
        next = list->next;
        free(list);
    }
}

