class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_water = 0;

        while(left < right) {
            // Area calculation
            int h = min(height[left], height[right]);
            int l = right - left;
            int area = h * l;
            max_water = max(max_water, area);

            // Pointer movement
            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        } // The loop now correctly includes the logic above
        
        return max_water;
    }
};