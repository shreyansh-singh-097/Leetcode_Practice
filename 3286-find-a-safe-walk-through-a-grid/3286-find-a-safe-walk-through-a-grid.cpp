#include <vector>
#include <deque>
#include <climits>

class Solution {
public:
    bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        std::deque<std::pair<int, int>> dq;
        
        dist[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    
                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;
                        
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        return (health - dist[m - 1][n - 1]) >= 1;
    }
};