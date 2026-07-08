class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int left_max = 0;
        int right_max = 0;
        int paani = 0;
        while(left<right){
            if(height[left] <= height[right]){
                if(height[left] >= left_max){
                    left_max = height[left];
                } else {
                    paani = paani + left_max -  height[left];
                } 
                left ++;
            }
            if(height[right] <= height[left]){
                if(height[right] >= right_max){
                    right_max = height[right];
                }else{
                    paani = paani + right_max - height[right];
                }
                right --;
            }
        }
        return paani;
    }
};