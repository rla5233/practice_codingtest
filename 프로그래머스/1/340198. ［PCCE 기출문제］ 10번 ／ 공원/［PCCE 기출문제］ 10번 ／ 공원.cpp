#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(std::vector<int> mats, std::vector<std::vector<std::string>> park) 
{
    int rows = park.size();
    int cols = park[0].size();
    
    sort(mats.begin(), mats.end(), greater<int>());
    
    for (int mat : mats) {
        bool canPlace = false;
        
        for (int i = 0; i <= rows - mat; i++) {
            for (int j = 0; j <= cols - mat; j++) {
                bool fits = true;
                
                for (int x = 0; x < mat; x++) {
                    for (int y = 0; y < mat; y++) {
                        if (park[i + x][j + y] != "-1") {
                            fits = false;
                            break;
                        }
                    }
                    if (!fits) break;
                }
                
                if (fits) {
                    canPlace = true;
                    break;
                }
            }
            if (canPlace) break;
        }
        
        if (canPlace) return mat;
    }
    
    return -1;
}