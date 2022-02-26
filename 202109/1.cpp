/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-11 23:10:03
 */
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n;i++)
        cin >> B[i];
    int max = B[0];
    int min = B[0];
    for (int i = 1; i < n;i++){
        if(B[i] != B[i-1]){
            min += B[i];
        }
        max += B[i];
    }
    cout << max << endl
         << min << endl;
}