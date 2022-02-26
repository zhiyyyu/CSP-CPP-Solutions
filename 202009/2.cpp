/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-28 15:06:38
 */
#include<bits/stdc++.h>

using namespace std;

int x_l, y_d, x_r, y_u;

bool inline inRange(int x, int y){
    return x_l <= x && x <= x_r && y_d <= y && y <= y_u;
}

int main(){
    int n, k, t;
    cin >> n >> k >> t >> x_l >> y_d >> x_r >> y_u;
    int flag1;
    int flag2;
    int x, y, cnt = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n;i++){
        flag1 = 0;
        flag2 = 0;
        cnt = 0;
        for (int j = 0; j < t;j++){
            cin >> x >> y;
            if(inRange(x, y)){
                if(flag1 == 0)
                    flag1 = 1;
                if(flag2 == 0 && ++cnt >= k){
                    flag2 = 1;
                }
            } else{
                cnt = 0;
            }
        }
        ans1 += flag1;
        ans2 += flag2;
    }
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}