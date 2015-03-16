//
// Created by ross on 16/03/15.
//

#include "single-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

sll_node* sll_new_list(int value)
{
    sll_node* root;
    root = malloc(sizeof(sll_node));
    root->value = value;
    root->next = NULL;
    return root;
}

sll_node* sll_traverse_to_end(sll_node* list)
{
    if (list) {
        while(list->next != NULL) {
            list = list->next;
        }
    }

    return list;
}

void sll_add_to_list(sll_node* list, int value)
{
    sll_node* final_node;
    sll_node* new_node;

    final_node = sll_traverse_to_end(list);
    new_node = malloc(sizeof(sll_node));
    final_node->next = new_node;
    new_node->value = value;
    new_node->next = NULL;
}

void sll_print_list(sll_node* list)
{
    for(; list; list = list->next) {
        printf("Location: %p\t", list);
        printf("Value: %d\n", list->value);
    }
}

void sll_destroy_list(sll_node* list)
{
    sll_node* next;

    for(; list; list = next) {
        next = list->next;
        free(list);
    }
}

