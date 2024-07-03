#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> boundary;
        
        if (!isLeaf(root)) boundary.push_back(root->val);
        
        // Get left boundary excluding leaf nodes
        addLeftBoundary(root->left, boundary);
        
        // Get all the leaf nodes
        addLeaves(root, boundary);
        
        // Get right boundary excluding leaf nodes
        vector<int> rightBoundary;
        addRightBoundary(root->right, rightBoundary);
        
        // Add right boundary nodes in reverse order to the result
        for (int i = rightBoundary.size() - 1; i >= 0; --i) {
            boundary.push_back(rightBoundary[i]);
        }
        
        return boundary;
    }
    
private:
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }
    
    void addLeftBoundary(TreeNode* node, vector<int>& boundary) {
        while (node) {
            if (!isLeaf(node)) boundary.push_back(node->val);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }
    
    void addLeaves(TreeNode* node, vector<int>& boundary) {
        if (!node) return;
        if (isLeaf(node)) {
            boundary.push_back(node->val);
            return;
        }
        addLeaves(node->left, boundary);
        addLeaves(node->right, boundary);
    }
    
    void addRightBoundary(TreeNode* node, vector<int>& rightBoundary) {
        while (node) {
            if (!isLeaf(node)) rightBoundary.push_back(node->val);
            if (node->right) node = node->right;
            else node = node->left;
        }
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);
    
    Solution solution;
    vector<int> boundary = solution.boundaryOfBinaryTree(root);
    
    for (int val : boundary) {
        cout << val << " ";
    }
    
    // Clean up the dynamically allocated memory (optional, for completeness)
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->right->left;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
