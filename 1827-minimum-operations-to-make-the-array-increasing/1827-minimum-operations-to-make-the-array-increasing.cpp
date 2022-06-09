class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0) return 0;
        
        int res=0;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                res+=(nums[i-1]-nums[i])+1;
                nums[i]+=(nums[i-1]-nums[i])+1;
            }
        }
        
        return res;
    }
};