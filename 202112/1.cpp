/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2022-02-22 22:13:42
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, N;
    cin >> n >> N;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    int ans = 0, f = 0, i = 0;
    for (int x = 0; x < N;x++){
        if(i < n && x >= a[i+1]){
            i++;
            f = i;
        }
        ans += f;
    }
    cout << ans;
    return 0;
}