class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // first window
        for (int i = 0; i < k; i++) {
            while (dq.size() > 0 && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);
            // remove elements not part of current window
            while (dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            // remove smaller values
            while (dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};