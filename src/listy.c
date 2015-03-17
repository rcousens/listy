#include <stdio.h>
#include "single-list/single-linked-list.h"

int main(int argc, char *argv[]){
	sll_node_t list = {
			.value = 13,
			.next = NULL
	};

	sll_add_to_list(&list, 14);
	sll_add_to_list(&list, 15);
	sll_add_to_list(&list, 16);

	sll_print_list(&list);

	sll_node_t* found_node = sll_find_node(&list, 15);

	if (found_node) {
		printf("Found node with value %d at location %p\n", found_node->value, found_node);
	}

	sll_destroy_list(&list);
	return 0;
}