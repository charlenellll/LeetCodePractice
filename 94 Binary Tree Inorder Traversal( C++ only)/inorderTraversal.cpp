/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// unlike preorder traversal, we need this struct to make all three traversal similar in the form
// or they will be really different
struct Command{
    string s; // go, print
    TreeNode* node;
    Command( string s, TreeNode* node): s(s), node(node){}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;
        
        stack<Command> stack;
        stack.push( Command("go", root) );
        while( !stack.empty() ){
            
            Command command = stack.top();
            stack.pop();
            
            if( command.s == "print" )
                res.push_back( command.node -> val );
            else{
                assert( command.s == "go" );
                if( command.node-> right )
                    stack.push( Command("go",command.node->right) );
                stack.push( Command("print",command.node) );
                if( command.node-> left )
                    stack.push( Command("go",command.node->left) );
            }
        }
        
        return res;
    }
};


// 大部队的解法比较难想

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            s.pop();
            
            result.push_back(cur->val);
            
            cur = cur->right;
        }
        
        return result;
    }
};