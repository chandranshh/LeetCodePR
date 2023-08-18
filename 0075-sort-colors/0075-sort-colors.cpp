class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count_0=0, count_1=0, count_2=0;

        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                count_0++;
            }else if(nums[i]==1){
                count_1++;
            }
            else if(nums[i]==2){
                count_2++;
            }
        }
        nums.clear();
        for(int i=0;i<count_0;i++){
            nums.emplace_back(0);
        }
        for(int i=0;i<count_1;i++){
            nums.emplace_back(1);
        }
        for(int i=0;i<count_2;i++){
            nums.emplace_back(2);
        }
    }
};