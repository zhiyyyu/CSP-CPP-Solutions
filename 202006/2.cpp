/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-11 23:09:57
 */
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int k;
    int v;
} node;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    node A[a], B[b];
    for (int i = 0; i < a;i++){
        cin >> A[i].k >> A[i].v;
    }
    for (int i = 0; i < b;i++){
        cin >> B[i].k >> B[i].v;
    }
    long long ans = 0;
    int u = 0, v = 0;
    while(u < a && v < b){
        if(A[u].k == B[v].k){
            ans += 1ll * A[u].v * B[v].v;
            u++, v++;
        } else if(A[u].k > B[v].k){
            v++;
        } else{
            u++;
        }
    }
    cout << ans << endl;
    return 0;
}