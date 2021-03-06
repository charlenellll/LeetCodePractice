class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long long> record;
        for(int i = 0; i < nums.size(); i++){
            
                //this is an iterator object, make sure it exists                        this is its value
            if( record.lower_bound((long long)nums[i] - (long long)t) != record.end() && *record.lower_bound((long long)nums[i] - (long long)t) <= (long long)nums[i] + (long long)t )
                return true; // y >= x-t exists && y <= x + t 看视频
            
            record.insert(nums[i]);
            if( record.size() == k+1 )
                record.erase( nums[i-k] );
        }
        return false;
    }
};