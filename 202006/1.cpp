/*
 * @Email: zhiyyyu@gmail.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-10-11 23:09:54
 */
#include<bits/stdc++.h>

using namespace std;

typedef struct Point{
    int x;
    int y;
    char cls;
} Point;

int main(){
    int n, m;
    cin >> n >> m;
    Point points[n];
    for (int i = 0; i < n;i++){
        cin >> points[i].x >> points[i].y >> points[i].cls;
    }
    int a, b, c;
    for (int i = 0; i < m;i++){
        cin >> a >> b >> c;
        int aa = 0, bb = 0;
        bool canSplit = true;
        for (int j = 0; j < n;j++){
            int tmp = a + points[j].x * b + points[j].y * c;
            if(points[j].cls == 'A'){
                if(aa == 0){
                    aa = tmp > 0 ? 1 : -1;
                } else if(tmp * aa < 0){
                    canSplit = false;
                    break;
                }
            } else{
                if(bb == 0){
                    bb = tmp > 0 ? 1 : -1;
                } else if(tmp * bb < 0){
                    canSplit = false;
                    break;
                }
            }
        }
        cout << (canSplit ? "Yes" : "No") << endl;
    }
}