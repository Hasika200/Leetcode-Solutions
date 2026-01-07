/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long SUM=0;
    long maxP=0;
    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftSum=totalSum(root->left);
        int rightSum=totalSum(root->right);
        int sum=root->val+leftSum+rightSum;
        return sum;
    }
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftsum=find(root->left);
        int rightsum=find(root->right);
        long subtreesum=root->val+leftsum+rightsum;
        long remSum=SUM-subtreesum;
        maxP=max(maxP,subtreesum*remSum);
        return subtreesum;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        maxP=0;
        SUM=totalSum(root);
        find(root);
        return maxP%(1000000007);
    }
};