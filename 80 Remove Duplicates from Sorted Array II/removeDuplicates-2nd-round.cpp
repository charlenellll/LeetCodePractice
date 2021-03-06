// 8 ms, faster than 99.00%

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = 1;
        if( nums.size() == 0 ) return 0;
        int k = 1;
        for(int i = 1; i < nums.size(); i++){
            if( nums[i] > nums[k-1] || (nums[i] == nums[k-1] && flag < 2) ){
                if( nums[i] > nums[k-1] ) flag = 0;
                flag ++;
                if( i != k ) swap(nums[i], nums[k]);
                k++;
            }
        }
        return k;
    }
};