class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        vector<int> answer (n,1);

        //calculating previous elements
        int previous = 1;
        for (int i = 0; i < nums.size(); i++){
            answer[i] = previous;
            previous = previous*nums[i];
        }
        //calculating next elements
            int next = 1;
        for (int i = n-1; i >= 0; i--){
            answer[i] = answer[i]*next;
            next = next*nums[i];
        }
        return answer;
    }
};