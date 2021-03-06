class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        /*int i=0, j=1;
        int maxdiff=-1;
        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]>nums[i])
                    maxdiff=max(maxdiff, nums[j]-nums[i]);
            }
        }
        
        return maxdiff;*/
        int maxdiff=0;
        int currmin=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            
            currmin=min(currmin, nums[i]);
            maxdiff=max(maxdiff, nums[i]-currmin);
        }
        
        return (maxdiff==0)?-1:maxdiff;
        
        
    }
};