class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   k = k%n;
	   int temp[k],i;
	   
	   for(i=0;i<k;i++)
	   {
	       temp[i] = arr[i];
	   }
	   
	   for(i=k;i<n;i++)
	   {
	       arr[i-k] = arr[i];
	   }
	   
	   for(i=n-k ; i<n;i++)
	   {
	       arr[i] = temp[i- (n-k)];
	   }
	} 
		 

};
