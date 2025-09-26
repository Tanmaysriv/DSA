class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(auto i:hash){
            if(i.second==1)return i.first;
        }
        return -1;
    }
};