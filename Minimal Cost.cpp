//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int solve(int n,int k,vector<int> &height, int dp[])
    {
        if(n==0) return 0;
        
        int cost = INT_MAX;
        if(dp[n] != -1) return dp[n];
        
        for(int i=1;i<=k;i++)
        {
            if(n-i >= 0)
            cost = min(cost, solve(n-i,k,height,dp) +abs( height[n]-height[n-i]));
        }
        
        return dp[n] = cost;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(n-1,k,height,dp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
