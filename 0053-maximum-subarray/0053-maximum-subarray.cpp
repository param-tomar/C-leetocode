class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int current_max = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++) {  //we use size_t as a safe way to count things as it is unsigned and doesnt give compiler error
            current_max = std::max(nums[i], current_max + nums[i]);
            max_so_far = std::max(max_so_far, current_max);
        }
        
        return max_so_far;
    }
};
