/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2022-02-23 10:10:43
 */
#include<bits/stdc++.h>
using namespace std;
typedef int Module;
typedef enum{
    UPPER,
    LOWER,
    DIGIT,
} MODE;

vector<Module> modules, g, rx;
int w, s;
int n, k;
const int MOD = 929;
string text;

void getModules(const string& t){
    MODE m = UPPER;
    int n = t.size();
    for (int i = 0; i < n;i++){
        switch(m){
        case UPPER:
            if(islower(t[i])){
                modules.push_back(27);
                modules.push_back(t[i] - 'a');
                m = LOWER;
            } else if(isdigit(t[i])){
                modules.push_back(28);
                modules.push_back(t[i] - '0');
                m = DIGIT;
            } else{
                modules.push_back(t[i] - 'A');
            }
            break;
        case LOWER:            
            if(isupper(t[i])){
                modules.push_back(28);
                modules.push_back(28);
                modules.push_back(t[i] - 'A');
                m = UPPER;
            } else if(isdigit(t[i])){
                modules.push_back(28);
                modules.push_back(t[i] - '0');
                m = DIGIT;
            } else{
                modules.push_back(t[i] - 'a');
            }
            break;
        case DIGIT:
            if(isupper(t[i])){
                modules.push_back(28);
                modules.push_back(t[i] - 'A');
                m = UPPER;
            } else if(islower(t[i])){
                modules.push_back(27);
                modules.push_back(t[i] - 'a');
                m = LOWER;
            } else{
                modules.push_back(t[i] - '0');
            }
            break;
        }
    }
    int size = modules.size();
    if(size&1){
        modules.push_back(29);
        size++;
    }
    for (int i = 0; i < size;i+=2){
        int j = i / 2;
        modules[j] = modules[i] * 30 + modules[i + 1];
    }
    modules.resize(size / 2);

    n = modules.size() + 1;
    k = pow(2, s + 1);
    if(s == -1){
        if(n % w){
            int fill = w - n % w;
            n += fill;
            for (int i = 0; i < fill;i++){
                modules.push_back(900);
            }
        }
    } else{
        if((n + k) % w){
            int fill = w - (n + k) % w;
            n += fill;
            for (int i = 0; i < fill;i++){
                modules.push_back(900);
            }
        }
    }
    modules.insert(modules.begin(), n);
}

// 多项式乘法计算g的系数
// 一项一项乘，vector保留系数
void calcGx(){
    g = vector<Module>(k + 1, 0);
    // (x+3)*(x+3^2)*...
    // g * (x + pow3) = g * x + g * pow3
    g[k] = -3;
    g[k - 1] = 1;
    int pow3 = -9;
    // 一共有k项，前i项相乘有（i+1）个参数（从k往前）
    for (int i = 0; i < k - 1;i++){
        // temp result
        vector<Module> tt(k + 1, 0);
        // copy
        for (int j = k - i - 1; j <= k;j++){
            tt[j] = g[j];
        }
        // g = g * pow3
        for (int j = k - i - 1; j <= k;j++){
            g[j] = (g[j] % MOD) * pow3 % MOD;
        }
        // g = g + tt * x （也就是tt向左移动一位）
        for (int j = k - i - 1; j < k;j++){
            g[j] = (g[j] + tt[j + 1]) % MOD;
        }
        g[k - i - 2] = 1;   // 最高次一定是1
        pow3 *= 3;
        pow3 %= MOD;
    }
}

void calcRx(){
    vector<Module> &gx = g;
    // dx最高n次，但是乘了x^k
    vector<Module> dx(modules.size() + k, 0);
    for (int i = 0; i < modules.size();i++){
        dx[i] = modules[i] % MOD;
    }
    // for (int i = 0;i<dx.size();++i){
    //     cout << dx[i] << endl;
    // }
    for (int i = 0; i < modules.size();i++){
        int t = dx[i];  // 最高次
        for (int j = 0; j < gx.size();j++){
            dx[i + j] = (dx[i + j] - gx[j] * t % MOD) % MOD;
        }
    }
    // for (int i = 0;i<dx.size();++i){
    //     cout << dx[i] << endl;
    // }
    for (int i = dx.size() - gx.size() + 1; i < dx.size();i++){
        if(-dx[i] < 0)
            rx.push_back(MOD + (-dx[i] % MOD));
        else
            rx.push_back(-dx[i] % MOD);
    }
    // for (int i = 0;i<dx.size();++i){
    //     cout << dx[i] << endl;
    // }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> w >> s;
    cin >> text;
    getModules(text);
    calcGx();
    calcRx();
    
    for (int i = 0; i < modules.size();i++){
        cout << modules[i] << "\n";
    }
    if(s != -1){
        for (int i = 0; i < rx.size();i++){
            cout << rx[i] << "\n";
        }
    }
    return 0;
}