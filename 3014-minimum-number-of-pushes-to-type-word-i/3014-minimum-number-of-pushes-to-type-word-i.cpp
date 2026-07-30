class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int push = 1;
        while (n > 8) {
            ans += 8 * push;
            n -= 8;
            push++;
        }
        ans += n * push;
        return ans;
    }
};