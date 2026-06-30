class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_seen[3] = {-1, -1, -1};
        int count = 0;
        int n = s.length();
        for (int r = 0; r < n; r++) {
            last_seen[s[r] - 'a'] = r;    
            if (last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1) {
                int min_index = min({last_seen[0], last_seen[1], last_seen[2]});
                count += min_index + 1;
            }
        }   
        return count;
    }
};