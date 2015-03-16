//
// Created by ross on 16/03/15.
//

#ifndef _LISTY_LINKED_LIST_H_
#define _LISTY_LINKED_LIST_H_

typedef struct sll_node_t {
    int value;
    struct sll_node_t* next;
} sll_node;

sll_node* sll_new_list(int value);
sll_node* sll_traverse_to_end(sll_node* list);
void sll_print_list(sll_node* list);
void sll_destroy_list(sll_node* list);
void sll_add_to_list(sll_node* list, int value);

#endif //_LISTY_LINKED_LIST_H_
