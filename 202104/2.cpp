/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-27 23:22:28
 */
#include<bits/stdc++.h>
// #define TIMEIT

using namespace std;

int main(){
#ifdef TIMEIT
    clock_t start = clock();
#endif
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    vector<vector<int>> mat(n, vector<int>(n));
    vector<vector<int>> prefix(n, vector<int>(n));
    // vector<vector<int>> prefix2(n, vector<int>(n));
    for (int i = 0; i < n;i++){
        int sum = 0;
        for (int j = 0; j < n;j++){
            cin >> mat[i][j];
            sum += mat[i][j];
            prefix[i][j] = sum;
        }
    }
    int ans = 0;
    for (int i = 0; i < n;i++){
        int top = fmax(0, i - r);
        int bot = fmin(n - 1, i + r);
        for (int j = 0; j < n;j++){
            // cout << prefix[i][j] << " ";
            int left = fmax(0, j - r);
            int right = fmin(n - 1, j + r);
            int tmp = 0;
            for (int k = top; k <= bot;k++){
                tmp += (left > 0 ? prefix[k][right] - prefix[k][left-1] : prefix[k][right]);
            }
            if(tmp <= t*(right-left+1)*(bot-top+1))
                ans++;
        }
        // cout << endl;
    }
    cout << ans;
#ifdef TIMEIT
    clock_t end = clock();
    cout << "time: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}