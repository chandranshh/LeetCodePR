class Solution {
public:
    int mySqrt(int x) {
        int num = x;
        int first = 1, last = num;
        
        while(first<=last){
            int mid = first + (last - first) / 2;
            if(mid == num / mid){
                return mid;
            }
            else if(mid > num / mid){
                last = mid-1;
            }
            else{
                first = mid+1;
            }
        }
        return last;
    }
};