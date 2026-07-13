class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        string ans = "";
        bool neg = false;
        if (num < 0) {
            neg = true;
            num = -num;
        }
        while (num != 0) {
            ans = char((num % 7) + '0') + ans;
            num /= 7;
        }
        if (neg)
            ans = "-" + ans;
        return ans;
    }
};