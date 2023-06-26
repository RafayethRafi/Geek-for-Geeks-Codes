class Solution{
    public:
    
    int maxPowerof2(int n)
    {
        int x = log2(n);
        return x;
    }
    
    int countSetBits(int n)
    {
        if(n==0) return 0;
        int x = maxPowerof2(n);
        
        return (pow(2,x-1)*x) + (n- pow(2,x)+1) + countSetBits(n - pow(2,x));
        
    }
};
