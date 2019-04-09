PROBLEM CODE: FENCE
#include "bits/stdc++.h"
using namespace std;

const int MAX_DIMENSIONS = 1000000;
const int MAX_FIELDS = 100000;

int r, c, n;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int visited[MAX_FIELDS];
vector < int > adj[MAX_FIELDS];
map < pair < int, int >, int > cell_id;
map < pair < int, int >, bool > is_cultivated;

inline bool within_grid(int x, int y) {
    return (1 <= x && x <= r && 1 <= y && y <= c);
}

inline int compute_size(int x) {
    visited[x] = true;
    int res = 4 - ((int)(adj[x].size()));
    for (int y : adj[x]) {
        if (!visited[y]) {
            res += compute_size(y);
        }
    }
    return res;
}

int main() {
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d %d", &x, &y);
        is_cultivated[{x, y}] = true;
        cell_id[{x, y}] = i;
    }
    for (auto entry : is_cultivated) {
        int x = entry.first.first;
        int y = entry.first.second;
        cout << x << y <<endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (within_grid(nx, ny) && is_cultivated.count({nx, ny})) {
                cout << nx << ", " << ny << endl;
                adj[cell_id[{x, y}]].push_back(cell_id[{nx, ny}]);
            }
        }
    }
    for(int x=0;x<=n;x++){
        cout << x << ": ";
        for(auto y:adj[x]){
            cout << y <<",";
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans +=compute_size(i);
        }
    }
    printf("%d\n", ans);
}