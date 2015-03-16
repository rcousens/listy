#include <stdio.h>
#include "single-list/single-linked-list.h"

int main(int argc, char *argv[]){
	sll_node* root;

	root = sll_new_list(13);

	sll_add_to_list(root, 14);
	sll_add_to_list(root, 15);
	sll_add_to_list(root, 16);

	sll_print_list(root);

	sll_destroy_list(root);
	return 0;
}