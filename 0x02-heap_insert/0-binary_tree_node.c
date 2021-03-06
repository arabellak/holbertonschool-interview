# include "binary_trees.h"
# include <stdlib.h>

/**
* binary_tree_node - Creates a binary tree.
* @parent: parent.
* @value: Value.
* Return: Pointer to new node or NULL.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	return (new);
}
