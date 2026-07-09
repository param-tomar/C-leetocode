class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //// sort using vector iterators
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> merged;
        //Put the first interval into our result to start with
        merged.push_back(intervals[0]);

        for(int i = 0; i < n; i++){

            // Grab a reference to the last interval we saved
            // and the current interval we are inspecting
            vector<int>& last_merged = merged.back();
            vector<int>& current = intervals[i];

            // If current start <= last merged end, they overlap
            if(current[0]<=last_merged[1]){
                last_merged[1] = max(last_merged[1],current[1]);
            }
            // No overlap, safely push the current interval as a new independent group
            else{
                merged.push_back(current);
            }
        }
        return merged;
    }
};