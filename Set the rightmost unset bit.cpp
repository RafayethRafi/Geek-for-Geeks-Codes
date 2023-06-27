class Solution
{
public:
    int setBit(int N)
    {
        int k = N,i=0;

        while(k>0)
        {
            if((k&1 )== 0) return ( N | (1<<i));
            
            i++;
            k>>=1;
        }
        
        return N;
        
    }
};
