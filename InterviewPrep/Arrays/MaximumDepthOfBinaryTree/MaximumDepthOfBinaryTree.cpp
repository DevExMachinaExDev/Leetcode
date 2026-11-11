/**
 * Definition for a binary tree node.

 */
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

    public:
        int maxDepth(TreeNode* root) 
        {
            return -1;
        }
};