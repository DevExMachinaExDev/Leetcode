#include <algorithm>

class Solution 
{
    private:
        struct TreeNode 
        {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        };

        int maxDepthFound = 0;

    public:
        int maxDepth(TreeNode* root) 
        {
             if (root == nullptr)
                return 0;

            maxDepthRecursive(root, maxDepthFound);
            return maxDepthFound;
        }

        void maxDepthRecursive(TreeNode* root, int currentDepth)
        {
            currentDepth++;
            maxDepthFound = std::max(maxDepthFound, currentDepth);
            
            if (root->left != nullptr)
                maxDepthRecursive(root->left,  currentDepth);

            if (root->right != nullptr)
                maxDepthRecursive(root->right,  currentDepth);
        }
};