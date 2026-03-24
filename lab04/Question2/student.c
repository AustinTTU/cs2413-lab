#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool checkSymmetric(struct TreeNode* leftTree, struct TreeNode* rightTree) {
  if (leftTree == NULL && rightTree == NULL) return true;
  else if (leftTree == NULL || rightTree == NULL) return false;
  if (leftTree->val != rightTree->val) return false;
  else return checkSymmetric(leftTree->right, rightTree->left) && checkSymmetric(leftTree->left, rightTree->right);
}

bool isSymmetric(struct TreeNode* root) {
  // TODO: implement
  if (root == NULL) return true;
  if ((root->left == NULL) && (root->right == NULL)) return true;
  else if (root->left && root->right) return checkSymmetric(root->left, root->right);
  return false;
}