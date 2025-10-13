class Solution {
  private:
  int getAns(Node* root, unordered_map<Node*,int>&mp){
      if(!root){
          return 0;
      }
      if(mp.find(root)!=mp.end()){
          return mp[root];
      }
      int include=root->data;
      if(root->left){
          include=include+getAns(root->left->left,mp)+getAns(root->left->right,mp);
      }
      if(root->right){
          include=include+getAns(root->right->left,mp)+getAns(root->right->right,mp);
      }
      int exclude=0;
      exclude=exclude+getAns(root->left,mp);
      exclude=exclude+getAns(root->right,mp);
      return mp[root]=max(include,exclude);
  }
  public:
    int getMaxSum(Node *root) {
        unordered_map<Node*,int>mp;
        return getAns(root,mp);
    }
};