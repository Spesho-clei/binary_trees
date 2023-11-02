#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the binary tree
 * Return: int, indicating whether the tree is perfect or not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
    int is_full = binary_tree_is_full(tree);
    if (tree == NULL)
        return 0;

    return is_full && ((size_t)1 << height) - 1 == binary_tree_size(tree);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 * Return: size_t, representing the size
 * (number of nodes) of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the binary tree
 * Return: int, indicating whether the tree is full or not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
        if (tree == NULL)
                return (0);
        if (tree->left == NULL && tree->right == NULL)
                return (1);
        if (tree->left && tree->right)
                return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
        return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: size_t, representing the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        size_t left_height = 0, right_height = 0;

        if (tree == NULL)
                return (0);

        left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
        right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

        return (left_height > right_height ? left_height : right_height);
}
