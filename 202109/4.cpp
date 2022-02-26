/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-13 23:48:34
 */
#include<bits/stdc++.h>

using namespace std;

int n;
int k;
double E;
vector<double> prob;
// vector<int> nums;

int calcVacancy(int cards){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if((cards & 1) == 0)
            cnt++;
        cards >>= 1;
    }
    return cnt;
}

void dfs(int cards, int coins, double p, int cnt){
    int vac = calcVacancy(cards);
    if(vac == 0 || coins/k >= vac){
        E += p * cnt;
        // cout << p << " " << cnt << endl;
        return;
    }
    for (int i = 0; i < n;i++){
        // nums[i]++;
        if((cards >> i) & 1)
            coins++;
        dfs(cards | (1 << i), coins, p * prob[i], cnt + 1);
        // nums[i]--;
        if((cards >> i) & 1)
            coins--;
    }
    return;
}

int main(){
    cin >> n >> k;
    prob = vector<double>(n, 0);
    // nums = vector<int>(n, 0);
    for (int i = 0; i < n;i++){
        cin >> prob[i];
        // cout << prob[i] << endl;
    }
    dfs(0, 0, 1.0, 0);
    printf("%.10f", E);
    return 0;
}