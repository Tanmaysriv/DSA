class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        map<int, int> table;
        for(int i = 0; i < intervals.size(); i++) table[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++) 
            ans.push_back(table.lower_bound(intervals[i][1])!=end(table)?table.lower_bound(intervals[i][1]) -> second:-1);
        return ans;
    }
};