class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> preSumMap;
        int sum = 0,i;
        int maxlen = 0;
        
        for(i=0;i<N;i++)
        {
            sum += A[i];
            
            if(sum==K)
            {
                maxlen = i+1;
            }
            int rem = sum - K;
            
            if(preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
            
            if(preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxlen = max(maxlen,len);
            }
            
        }
        
        return maxlen;
        
    } 

};
