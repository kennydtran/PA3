#include<iostream>
//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) { return NULL; } //Base case to end recursion
        if (root->val == key) { return rmv(root); } //If the value of root equals key, then remove root 
        TreeNode* r = root; //Assign root to r for searching through key
        while (r != NULL) { //Repeat searching with r until empty
            if (r->val > key) { //If val is greater than key
                if (r->left != NULL && r->left->val == key) { //If left side has a child and val equals key
                    r->left = rmv(r->left); //Remove node on left side
                }
                else { r = r->left; } //If not, left node is assigned to r
            }
            else { //If r is less than key
                if (r->right != NULL && r->right->val == key) { //If right side doesn't equal NULL and val equals key
                    r->right = rmv(r->right); //Remove node on right side
                }
                else { 
                    r = r->right; //If not, right node is assigned to r
                }
            }
        }
        return root; //Return root
    }
    TreeNode* rmv(TreeNode* node) {      
        if (node->left == NULL) { return node->right; } //If left node has no child, return right node
        if (node->right == NULL) { return node->left; } //If right node has no child, return left node
        TreeNode* rgt = node->right; //Assign right node to rgt
        TreeNode* lft = rgtmst(node->left); //Assign left node to lft
        lft->right = rgt; //Assign rgt to right
        return node->left; //Return left node
    }
    TreeNode* rgtmst(TreeNode* rt) {
        if (rt->right == NULL) { return rt; } //If right has no child
        return rgtmst(rt->right); //Return 
    }
};
