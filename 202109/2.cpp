/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-12 00:18:50
 */
#include<bits/stdc++.h>

using namespace std;

int n;
int UPPER = 10000;
vector<int> A;
int main(){
    cin >> n;
    A = vector<int>(n + 2, 0);
    queue<pair<int, int>> q;
    set<int> s;
    A[0] = A[n + 1] = 0;
    for (int i = 1; i <= n;i++){
        cin >> A[i];
        if(A[i]) s.insert(A[i]);
    }
    int pre = 0;
    for (int i = 0; i <= n+1;i++){
        if(A[i] == 0){
            if(pre < i){
                q.push({pre, i-1});
            }
            pre = i + 1;
        }
    }
    int ans = q.size();
    for (int i: s){
        int size = q.size();
        for (int _ = 0; _ < size;_++){
            const auto &p = q.front();
            q.pop();
            // bool find = false;
            pre = p.first;
            for (int k = p.first; k <= p.second+1;k++){
                if(A[k] < i){
                    if(pre < k){
                        q.push({pre, k - 1});
                    }
                    pre = k + 1;
                }
            }
        }
        ans = max(ans, (int)q.size());
    }
    cout << ans;
    return 0;
}