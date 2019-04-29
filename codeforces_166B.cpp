#include<bits/stdc++.h>
using namespace std;
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a;
    a.assign(n,vector<char>(m,'0'));
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            if(a[i][j]=='W'){
                p.push_back(make_pair(i,j));
            }
        }
    }
    int x,y;
    int c=0;
    for(int i=0;i<p.size();i++){
        // cout << p[i].first << " " << p[i].second << endl;
        // if(a[p[i].first][p[i].second]=='P'){
        //     c++;
        //     a[]
        // }
        for(int k=0;k<4;k++){
            x=p[i].first+row[k];
            y=p[i].second+col[k];
            if(x>=0 and x<n and y>=0 and y<m and a[x][y]=='P'){
                c++;
                a[x][y]='.';
                break;
            }
        }
    }
    cout << c << endl;
}