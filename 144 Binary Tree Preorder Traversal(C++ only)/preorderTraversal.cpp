/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Command{
    string s; // go, print
    TreeNode* node;
    Command( string s, TreeNode* node): s(s), node(node){}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
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
                // The order of commands we push into the stack should be the reverse order of the actual sequential implementation
                // Last-in, first-out.
                if( command.node-> right )
                    stack.push( Command("go",command.node->right) );
                if( command.node-> left )
                    stack.push( Command("go",command.node->left) );
                stack.push( Command("print",command.node) );
            }
        }
        
        return res;
    }
};