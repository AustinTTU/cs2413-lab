/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* root) {
    if (root == NULL) return 0;
    else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height > right_height) return left_height+1;
        else return right_height+1;
    }
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    (void)root;

    if (root == NULL) return true;
    // Checking BST properties:
    if (root->left != NULL) if ((root->left->val > root->val)|| (root->left->val == root->val)) return false;
    if (root->right != NULL) if ((root->right->val < root->val) || (root->right->val == root->val)) return false;

    // Getting height:
    int left_height = height(root->left);
    int right_height = height(root->right);

    if ((left_height - right_height < 0) || (right_height - left_height < 0)) return false; // Checking balance

    return isAVL(root->left) && isAVL(root->right); // recursive call
}