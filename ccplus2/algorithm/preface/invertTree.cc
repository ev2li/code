#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* invertTree(TreeNode* root){
        if(root == NULL){
            return NULL;
        }

        TreeNode* tmpNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpNode);
        return root;
    }
};

int main(){
    
    return 0;
}