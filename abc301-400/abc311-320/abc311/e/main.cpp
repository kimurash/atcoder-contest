// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAXHW 3009

using namespace std;

bool hole[MAXHW][MAXHW];
int32_t table[MAXHW][MAXHW];

int main(){
    int32_t H, W;
    int32_t N;
    cin >> H >> W >> N;

    rep(i, 1, H){
        rep(j, 1, W){
            hole[i][j] = false;
        }
    }

    int16_t a, b;
    rep(i, 1, N){
        cin >> a >> b;
        hole[a][b] = true;
    }

    int64_t cnt = 0;
    rep(i, 1, H){
        rep(j, 1, W){
            if(hole[i][j]){
                table[i][j] = 0;
            } else{
                table[i][j] = min({
                    table[i - 1][j],
                    table[i][j - 1],
                    table[i - 1][j - 1]
                }) + 1;
                cnt += table[i][j];
            }
        }
    }

    cout << cnt << endl;
    return(0);
}