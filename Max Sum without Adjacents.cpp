//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int solve(int *arr, int idx, int dp[])
	{
	    if(idx == 0) return arr[idx];
	    if(idx < 0) return 0;
	    
	    if(dp[idx] != -1) return dp[idx];
	    
	    int pick = arr[idx] + solve(arr,idx - 2, dp);
	    int notPick = 0 + solve(arr,idx - 1, dp);
	    
	    return dp[idx] = max(pick , notPick);
	}
	
	int findMaxSum(int *arr, int n) {
	    
	    int dp[n];
	    memset(dp,-1,sizeof(dp));
	    
	    int ans = solve(arr,n-1, dp);

	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends






// 2nd type of solve 

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent

	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n,-1);
	       
	    dp[0] = arr[0];
	    
	    for(int i = 1;i<n;i++)
	    {
	        int pick = arr[i];
	        if(i>1) pick += dp[i-2];
	        
	        int notPick = dp[i-1];
	        
	        dp[i] = max(pick , notPick);
	    }

	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


// 3rd way with space complexity O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent

	int findMaxSum(int *arr, int n) {
	    
	    vector<int> dp(n,-1);
	       
	    int prev2 = 0;
	    int prev = arr[0];
	    int cur = prev;
	    
	    for(int i = 1;i<n;i++)
	    {
	        int pick = arr[i] + prev2;
	        
	        int notPick = prev;
	        
	        cur = max(pick , notPick);
	        prev2 = prev;
	        prev = cur;
	    }

	    return cur;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
