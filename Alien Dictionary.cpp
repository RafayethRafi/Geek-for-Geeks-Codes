//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        
        int i,j, inDegree[K] = {0};
        
        for(i=0;i<N-1;i++)
        {
            string str1 = dict[i];
            string str2 = dict[i+1];
            
            for(j=0; j<min(str1.size(),str2.size()); j++)
            {
                if(str1[j] != str2[j])
                {
                    adj[str1[j] - 'a'].push_back(str2[j] - 'a');
                    inDegree[str2[j] - 'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        vector<int> ans;
        
        for(i=0;i<K;i++)
        {
            if(inDegree[i] == 0)
            q.push(i);
        }
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            
            for(auto u : adj[x])
            {
                inDegree[u]--;
                if(inDegree[u] == 0)
                {
                    q.push(u);
                }
            }
        }
        
        string s= "";
        for(auto u: ans)
        {
            char ch = (u+'a');
            s += ch;
        }
        
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
