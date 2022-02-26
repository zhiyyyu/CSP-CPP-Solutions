/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-13 17:02:52
 */
#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        vector<int> ball(n+1);
        int a, b;
        for (int i = 0; i < n;i++){
            cin >> a >> b;
            ball[a-1]++;
            ball[b]--;
        }
        vector<int> ans(n);
        int sum = 0;
        for (int i = 0; i < n;i++){
            sum += ball[i];
            ans[i] = sum;
        }
        for (int i = 0; i < n-1;i++){
            cout << ans[i] << " ";
        }
        cout << ans[n-1] << endl;
        
        cin >> n;
    }
}