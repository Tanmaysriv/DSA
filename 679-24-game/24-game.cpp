class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) nums.push_back((double)c);
        return solve(nums);
    }
    
private:
    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                
                vector<double> next;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                for (int op = 0; op < 4; op++) {
                    // Skip duplicates only for + and *
                    if ((op == 0 || op == 2) && i > j) continue;
                    
                    if (op == 0) next.push_back(nums[i] + nums[j]);
                    if (op == 1) next.push_back(nums[i] - nums[j]);
                    if (op == 2) next.push_back(nums[i] * nums[j]);
                    if (op == 3) {
                        if (fabs(nums[j]) < 1e-6) continue;
                        next.push_back(nums[i] / nums[j]);
                    }
                    
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};
