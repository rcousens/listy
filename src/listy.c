#include <stdio.h>
#include "single-list/single-linked-list.h"

int main(int argc, char *argv[]){
	sll_node list;
	list.value = 13;
	list.next = NULL;

	sll_add_to_list(&list, 14);
	sll_add_to_list(&list, 15);
	sll_add_to_list(&list, 16);

	sll_print_list(&list);

	sll_destroy_list(&list);
	return 0;
}