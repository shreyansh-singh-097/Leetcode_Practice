class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lMax(n,0);
        vector<int> rmax(n,0);
        lMax[0] = height[0];
        rmax[n-1] = height[n-1];
        for (int i = 1; i < n; i++) {
            lMax[i] = max(lMax[i - 1], height[i]);
        }
        for (int i = n - 2;i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], height[i]);
        }
        int ans = 0;
        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            ans += min(lMax[i], rmax[i]) - height[i];
        }
        return ans;
    }
};


// prefix array approach O(n) SC & TC