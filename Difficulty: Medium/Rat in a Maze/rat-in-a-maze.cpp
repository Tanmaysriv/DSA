class Solution {
  public:
    bool boundary_cond(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n)return true;
        return false;
    }
    void solve(vector<vector<int> > &maze,int i,int j,vector<string> &ans,string &temp){
        int n=maze.size();
        if(boundary_cond(i,j,n))return ;
        if(maze[i][j]==0)return ;
        
        if((i==n-1) && (j==n-1)){
            ans.push_back(temp);
            return ;
        }
        maze[i][j]=0;
        //UDRL
        
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        char dir[4]={'D','L','R','U'};
        
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];
            temp.push_back(dir[k]);
            solve(maze,nr,nc,ans,temp);
            temp.pop_back();
        }
        maze[i][j]=1;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string temp;
       
        solve(maze,0,0,ans,temp);
        return ans;
    }
};