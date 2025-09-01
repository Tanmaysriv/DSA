class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=0;
        for(int candy : candies)
        {
            maxCandies=max(maxCandies,candy);
        }
        vector<bool>res;
        for(auto candy : candies)
        {
            res.push_back(candy+extraCandies >= maxCandies);
        }
        return res;
    }
};