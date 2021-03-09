class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==0) return;
        int swaps = 0;
        int past1stZero=0;
        for(int i=0;i<nums.size();i++){
            if(past1stZero==0 && nums[i]==0){
                past1stZero=1;
            }
            if(nums[i]!=0 && past1stZero==1){
                swaps++;
            }
        }
        if(swaps==0 || swaps == nums.size()) return;
        int i = 0;
        while(swaps!=0){
            if(nums[i]==0){
                int j = i+1;
                while(j<nums.size() && nums[i]==0){
                    if(nums[j]!=0){
                        nums[i]=nums[j];
                        nums[j]=0;
                        swaps--;
                    }
                    j++;
                }
            } else {
                i++;
            }
        }
    }
};