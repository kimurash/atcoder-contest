// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 109

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef string str;

template<typename T>
using vec = vector<T>;

i16 H, W;
i16 x, y;
i16 dir;
char grid[MAX][MAX];

void act();
void move();

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> H >> W >> N;

    rep(i, 1, H){
        rep(j, 1, W){
            grid[i][j] = '.';
        }
    }

    x = 1;
    y = 1;
    dir = 0;
    rep(i, 1, N){
        act();
    }

    rep(i, 1, H){
        rep(j, 1, W){
            cout << grid[i][j];
        }
        cout << endl;
    }
    return(0);
}

void act(){
    if(grid[x][y] == '.'){
        grid[x][y] = '#';
        dir = (dir + 1) % 4;
    } else if(grid[x][y] == '#'){
        grid[x][y] = '.';
        dir = (dir - 1 + 4) % 4;
    }
    move();

    return;
}

void move(){
    switch(dir){
        case 0:
            if(x == 1){
                x = H;
            } else{
                x--;
            }
            break;
        case 1:
            if(y == W){
                y = 1;
            } else{
                y++;
            }
            break;
        case 2:
            if(x == H){
                x = 1;
            } else{
                x++;
            }
            break;
        case 3:
            if(y == 1){
                y = W;
            } else{
                y--;
            }
            break;
    }

    return;
}