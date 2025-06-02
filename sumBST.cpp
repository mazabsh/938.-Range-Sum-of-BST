#include<iostream> 

using namespace std; 

struct TreeNode{
    int val; 
    TreeNode* left; 
    TreeNode* right; 
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
};

class Solution{
public: 
      int sumRangeBST(TreeNode* root, int low, int high){
        if(root==nullptr) return 0; 
        int sum=0; 
        if(root->val >=low && root->val <=high) sum+= root->val; 
        sum +=sumRangeBST(root->left, low , high); 
        sum += sumRangeBST(root->right, low, high); 
        return sum; 
      }
};
int main(){
    TreeNode* root = new TreeNode(10); 
    root->left = new TreeNode(5); 
    root->right = new TreeNode(15); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(7); 
    root->right->right = new TreeNode(18); 
    Solution sol; 
    int low = 7; 
    int high =15; 
    cout << sol.sumRangeBST(root, low, high) << endl; 
    return 0; 
}
