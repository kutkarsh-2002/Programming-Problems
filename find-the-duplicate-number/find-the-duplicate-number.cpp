class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort the elements of array in ascending order
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
                if(nums[i]==nums[i+1]){
                    return nums[i];
                    break;
                }
            
        }
        return -1;
        
    }
};