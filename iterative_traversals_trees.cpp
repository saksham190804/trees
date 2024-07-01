
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root) st.push(root);
        while(st.size()){
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return ans;
    }
};



vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        ans.push_back(node->val);

        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != NULL || !st.empty()) {
        if (current != NULL) {
            st.push(current);
            current = current->left;
        } else {
        	if(st.empty()) return ans;
            current = st.top();
            st.pop();
            ans.push_back(current->val);
            current = current->right;
        }
    }

    return ans;
}