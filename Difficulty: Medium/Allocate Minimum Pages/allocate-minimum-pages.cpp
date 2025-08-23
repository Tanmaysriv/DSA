class Solution {
public:
    // Helper function to check if allocation is possible with maxPages limit
    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int students = 1, pages = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxPages) return false; // single book larger than maxPages
            
            if (pages + arr[i] > maxPages) {
                students++;
                pages = arr[i];
                
                if (students > k) return false;
            } else {
                pages += arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1; // not enough books
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
