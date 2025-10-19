/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    private :
    void solve(Node *root,int target,unordered_map<int,int> &mp){
        if(root == NULL){
            return;
        }
        
        solve(root->left,target,mp);
        mp[root->data] = abs(root->data - target);
        solve(root->right,target,mp);
    }
  public:
    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        unordered_map<int,int> mp;
        solve(root,target,mp);
        
        vector<int> ans;
        
        for(int i = 1;i<=k;i++){
            int x = INT_MAX;
            int diff = INT_MAX;
            
            for(auto i : mp){
                if(diff > i.second){
                    diff = i.second;
                    x = i.first;
                }else if(diff == i.second && i.first<x){
                    x = i.first;
                }
            }
            
            ans.push_back(x);
            mp.erase(x);
        }
        
        return ans;
    }
};