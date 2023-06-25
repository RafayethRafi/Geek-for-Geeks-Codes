class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        bool ans = (1<<k) & n;
        
        return ans;
    }
};
