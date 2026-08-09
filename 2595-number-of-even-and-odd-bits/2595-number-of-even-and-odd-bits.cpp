class Solution {
public:
    vector<int> evenOddBit(int n) {
        int evenCount = 0;
        int oddCount = 0;

        for (int i = 0; i < 10; i++) {
            if ((n >> i) & 1) {
                if (i % 2 == 0) {
                    evenCount++;
                } else {
                    oddCount++;
                }
            }
        }

        return {evenCount, oddCount};
    }
};