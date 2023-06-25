class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = __builtin_popcount(n);

        if(n>0 && cnt == 1) return true;
        else return false;
    }
};

class Solution {
public:

    int sol(int n)
    {
        if(n==0) return 0;

        else return (n&1) + sol(n>>1);
    }

    bool isPowerOfTwo(int n) {
        if(n<=0) return false;

        if(sol(n) == 1) return true;
        else return false;
    }
};
