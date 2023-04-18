//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        
        q.push({0,start});
        int mod = 100000;
        
        while(!q.empty())
        {
            int num = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            for(int i=0;i<arr.size();i++)
            {
                int newV = (num * arr[i]) % mod;
                
                if(steps + 1 < dist[newV])
                {
                    dist[newV] = steps+1;
                    
                    if(newV == end) return dist[newV];
                    
                    q.push({dist[newV], newV});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
