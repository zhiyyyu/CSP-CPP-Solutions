/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-27 23:22:07
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, L;
    cin >> n >> m >> L;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> H(L, 0);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> mat[i][j];
            H[mat[i][j]]++;
        }
    }
    for (int i = 0; i < L-1;i++){
        cout << H[i] << " ";
    }
    cout << H[L - 1];
    return 0;
}