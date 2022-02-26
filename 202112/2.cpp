/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2022-02-22 22:35:46
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, N;
int r;
vector<int> a;

ll mae(int i){
    int left = a[i], right = a[i + 1];
    int start = ceil(1.0 * left / r) * r, end = right / r * r;
    if(right < start){
        return 1ll * (right - left) * abs(i - left / r);
    }
    ll ret = 0;
    ret += 1ll * (start - left) * abs(left / r - i);
    ret += 1ll * (right - end) * abs(end / r - i);

    for (int j = start; j < end;j+=r){
        ret += 1ll * r * abs(j / r - i);
        // cout << start << " " << start+r << " " << 1ll * r * abs(j / r - i) << " ";
    }
    // cout << endl;
    return ret;
}

int main(){
    cin >> n >> N;
    r = N / (n + 1);
    a = vector<int>(n + 2, 0);
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    a[n + 1] = N;
    ll err = 0;
    for (int i = 0; i <= n;i++){
        // cout << i << ": " << endl;
        err += mae(i);
    }
    cout << err;
    return 0;
}