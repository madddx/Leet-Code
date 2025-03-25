#include <vector>
#include <algorithm>
using namespace std;

// Helper function: Checks if, along one dimension, we can partition the rectangles 
// into at least three groups. 
// For the x-dimension, set dim = 0 (using indices 0 and 2 from each rectangle).
// For the y-dimension, set dim = 1 (using indices 1 and 3).
bool canCutDimension(const vector<vector<int>> &rectangles, int dim) {
    // Build intervals for the chosen dimension.
    // For x: interval = [rect[0], rect[2]]
    // For y: interval = [rect[1], rect[3]]
    vector<pair<int,int>> intervals;
    intervals.reserve(rectangles.size());
    for (auto &r : rectangles) {
        if(dim == 0)
            intervals.push_back({r[0], r[2]});
        else
            intervals.push_back({r[1], r[3]});
    }
    // Sort intervals by the start coordinate.
    sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    });
    
    int blocks = 0;
    int curStart = 0, curEnd = 0;
    bool first = true;
    // We merge intervals if they “overlap” in interior.
    // Overlap means: current.start < previous.end.
    // (If current.start == previous.end, they are just touching and are separable.)
    for(auto &in : intervals) {
        int s = in.first, e = in.second;
        if(first){
            curStart = s;
            curEnd = e;
            first = false;
            blocks++; // starting a new block
        } else {
            // If the new interval starts before the current block ends, they overlap.
            if(s < curEnd) {
                curEnd = max(curEnd, e);
            } else {
                // They do not overlap (they might just touch) so this starts a new block.
                blocks++;
                curStart = s;
                curEnd = e;
            }
        }
    }
    return blocks >= 3;
}
 
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try horizontal cuts (using the y dimension) 
        if(canCutDimension(rectangles, 1)) return true;
        // Try vertical cuts (using the x dimension)
        if(canCutDimension(rectangles, 0)) return true;
        return false;
    }
};
