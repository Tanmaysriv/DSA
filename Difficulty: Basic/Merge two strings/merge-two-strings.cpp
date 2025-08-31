
string merge(string S1, string S2) {
    // your code here
    int n=S1.size();
    int m=S2.size();
    string res="";
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        res+=S1[i++];
        res+=S2[j++];
    }
    while(i<n)
    {
        res+=S1[i++];
    }
    while(j<m)
    {
        res+=S2[j++];
    }
    return res;
}