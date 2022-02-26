/*
 * @Email: 3284799532@qq.com
 * @Author: Deng Zehui
 * @Github: nArrow4
 * @Date: 2021-08-28 12:48:41
 */
#include<bits/stdc++.h>

using namespace std;

int n, X, Y;

struct Pos{
    int x;
    int y;
    int i;

    Pos(int x, int y, int i){
        this->x = x;
        this->y = y;
        this->i = i;
    }

    bool operator< (const Pos& b) const{
        int d1 = (x - X) * (x - X) + (y - Y) * (y - Y);
        int d2 = (b.x - X) * (b.x - X) + (b.y - Y) * (b.y - Y);
        if(d1 != d2)
            return d1 > d2;
        return i > b.i;
}
};

int main(){
    cin >> n >> X >> Y;
    priority_queue<Pos> pq;
    int x, y;
    for (int i = 0; i < n;i++)
    {
        cin >> x >> y;
        pq.push(Pos(x, y, i));
    }
    for (int i = 0; i < 3;i++){
        Pos f = pq.top();
        cout << f.i+1 << endl;
        pq.pop();
    }
    return 0;
}