#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int ans = 0;
        vector<int> arr(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if (arr[i] == 0) {
                dfs(isConnected, i, arr);
                ans++;
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<int>>& conn, int a, vector<int>& arr) {
        arr[a] = 1;
        for (int i = 0; i < conn.size(); i++) {
            if (i == a) continue;
            if (conn[a][i] == 1 && arr[i] == 0) {
                dfs(conn, i, arr);
            }
        }
    }
};