/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-28 09:49:46
 */
#include<bits/stdc++.h>

using namespace std;

typedef struct{
    int y;
    int result;
} Score;

int main(){
    int n;
    cin >> n;
    vector<Score> score(n);
    for (int i = 0; i < n;i++){
        cin >> score[i].y >> score[i].result;
    }
    sort(score.begin(), score.end(), [](const Score &a, const Score &b)->bool {
        if(a.y != b.y) return a.y < b.y;
        return a.result < b.result;
    });
    int l = 0, r = n - 1;
    while(l < n && score[l].result == 0)
        l++;
    while(r >= 0 && score[r].result == 1)
        r--;
    l = fmax(0, l - 2);
    r = fmin(n - 1, r + 2);
    int sum = 0;
    vector<int> prefix(n, 0);
    for (int i = 0; i < n;i++){
        sum += score[i].result == 0;
        prefix[i] = sum;
    }
    sum = 0;
    vector<int> suffix(n);
    for (int i = n-1; i >= 0;i--){
        sum += score[i].result == 1;
        suffix[i] = sum;
    }
    int ans = 0;
    int maxVal = 0;
    for (int theta = l; theta <= r;theta++){
        if(theta>0 && score[theta].y == score[theta-1].y)
            continue;
        int tmp = prefix[theta] + suffix[theta] - (score[theta].result == 0);
        if(tmp >= maxVal){
            maxVal = tmp;
            ans = theta;
        }
    }
    cout << score[ans].y;
    return 0;
}