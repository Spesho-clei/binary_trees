#include "binary_trees.h"

/**
 * *binary_tree_insert_left - inserts a node as the
 * left-child of another node
 * @parent: pointer to the node where the left-child
 * will be inserted
 * @value: value to be stored in the new node
 * Return: pointer to a binary tree node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
