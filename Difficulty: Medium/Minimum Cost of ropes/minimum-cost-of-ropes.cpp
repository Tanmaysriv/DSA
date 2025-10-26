class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num: arr){
            pq.push(num);
        }
        int cost = 0;
        while(pq.size()>1){
            int c1 = pq.top();
            pq.pop();
            int c2 = pq.top();
            pq.pop();
            
            cost += c1+c2;
            pq.push(c1+c2);
        }
        return cost;
    }
};