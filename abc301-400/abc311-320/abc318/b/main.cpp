// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 100

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 sheet[MAX + 1][MAX + 1];
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            sheet[i][j] = 0;
        }
    }

    i16 A, B, C, D;
    rep(n, 1, N){
        cin >> A >> B >> C >> D;
        rep(i, A, B - 1){
            rep(j, C, D - 1){
                sheet[i][j]++;
            }
        }
    }

    i32 cnt = 0;
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            if(sheet[i][j] > 0){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return(0);
}