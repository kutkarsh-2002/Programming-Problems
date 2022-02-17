class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1])
                return i;
        }
        
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
       
        return -1;
    }
};