/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-28 09:38:45
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int w, num;
    int y = 0;
    while(n--){
        cin >> w >> num;
        y += w * num;
    }
    y = fmax(0, y);
    cout << y;
    return 0;
}