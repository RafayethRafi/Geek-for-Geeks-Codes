class Solution {
  public:
    void bitManipulation(int num, int i) {
        i--;
        cout<<(1&(num>>i))<<" "<<((1<<i)|num)<<" "<<(~(1<<i)&num);
    }
};
