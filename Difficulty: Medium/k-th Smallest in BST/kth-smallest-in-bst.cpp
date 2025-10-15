/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, int &k, int &ans) {
        if (!root || ans != -1) return;  // Base case and early stop

        // Traverse left subtree
        inorder(root->left, k, ans);

        // Visit current node
        k--;
        if (k == 0) {  // If current node is kth smallest
            ans = root->data;
            return;
        }

        // Traverse right subtree
        inorder(root->right, k, ans);
    }
    
    int kthSmallest(Node *root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};