class Solution {
public:
    void maxHeapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            maxHeapify(nums, n, largest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Start from the last non-leaf node up to the root
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(nums, n, i);
        }
        
        int currentHeapSize = n;
        for (int i = 0; i < k - 1; i++) {
            // Swap the root (max element) with the last element of the current heap
            std::swap(nums[0], nums[currentHeapSize - 1]);
            currentHeapSize--;
            maxHeapify(nums, currentHeapSize, 0);
        }
        
        return nums[0];
    }
};