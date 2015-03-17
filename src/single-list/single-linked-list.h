//
// Created by ross on 16/03/15.
//

#ifndef _LISTY_LINKED_LIST_H_
#define _LISTY_LINKED_LIST_H_

typedef struct sll_node {
    int value;
    struct sll_node* next;
} sll_node_t;

void sll_print_list(sll_node_t* list);
void sll_destroy_list(sll_node_t* list);
void sll_add_to_list(sll_node_t* list, int value);
sll_node_t* sll_find_node(sll_node_t* current_node, int value);

#endif //_LISTY_LINKED_LIST_H_
