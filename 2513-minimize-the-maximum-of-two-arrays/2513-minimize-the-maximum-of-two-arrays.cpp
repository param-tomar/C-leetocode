class Solution {
public:
    int minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
        long long low = 1;
        long long high = 2e9;
        long long ans = high;
        long long lcm = (divisor1 / gcd(divisor1, divisor2))*divisor2;

        while (low <= high){
            long long mid = low + (high - low)/2;
            long long count1 = mid - (mid/divisor1);
            long long count2 = mid - (mid/divisor2);
            long long countboth = mid - (mid/lcm);

            //checking if conditions are satisfied
            if(count1 >= uniqueCnt1 && count2 >= uniqueCnt2 && countboth >= (uniqueCnt1 + uniqueCnt2)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid + 1;
            }
            }
            return ans;
    }
};