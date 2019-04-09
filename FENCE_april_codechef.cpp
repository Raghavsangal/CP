//CODECHEF: FENCE
#include "bits/stdc++.h"
using namespace std;

const int MAX_DIMENSIONS = 1000000;
const int MAX_FIELDS = 100000;

int r, c, n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
map < pair < int, int >, bool > is_cultivated;

inline bool within_grid(int x, int y) {
    return (1 <= x && x <= r && 1 <= y && y <= c);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        is_cultivated[{x, y}] = true;
    }
    int c,res=0,result=0;
    for (auto entry : is_cultivated) {
        int x = entry.first.first;
        int y = entry.first.second;
        c=0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (within_grid(nx, ny) && is_cultivated.count({nx, ny})) {
                c++;
                // cout << c << " ";
            }
        }
        res=4-c;
        result=result+res;
    }
    cout << result << endl;
    is_cultivated.clear();
}
}