class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,-1);
        stack<int>s;
        for(int i = 2*n-1 ;i>=0;i--){
            while(s.size()>0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            res[i%n] =s.empty()? -1 :nums[s.top()];
            s.push(i%n);
        }
        return res;
    }
};


// i%n is current index
// TC = O(2n)=O(n) , SC O(n)