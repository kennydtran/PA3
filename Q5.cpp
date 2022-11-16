int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; //If parent node has no child, return 0 (Base case)
        int maxLeft = maxDepth(root->left); //maxLeft is declared; maxDepth proceeding to the left is assigned to maxLeft
        int maxRight = maxDepth(root->right); //maxRight is declared; maxDepth proceeding to the right is assigned to maxRight
        return max(maxLeft, maxRight)+1; //Function is recursed until (child node + 1 = null node
    }
