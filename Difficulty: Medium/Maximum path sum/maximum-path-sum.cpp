/*class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int solve(Node*root,int& ans){
      if(root==NULL){
          return 0;
      }
      int left=max(0,solve(root->left,ans));
      int right=max(0,solve(root->right,ans));
      int curr=root->data+left+right;
      ans=max(ans,curr);
      return root->data+max(left,right);
  }
    int findMaxSum(Node *root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};