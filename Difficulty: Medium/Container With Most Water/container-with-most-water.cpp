class Solution {
public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;
        
        while (left < right) {
            int height = min(arr[left], arr[right]);
            int width = right - left;
            maxArea = max(maxArea, height * width);
            
            // Move the pointer which has the smaller height
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};
