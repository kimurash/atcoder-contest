// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 1009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 N, Q;
i32 acc[MAX][MAX];

i64 f(i32 A, i32 B, i32 C, i32 D);
i64 g(i32 H, i32 W);

int main(){
    cin.tie(nullptr);

    cin >> N >> Q;

    char grid[N + 1][N + 1];
    rep(i, 0, N){
        rep(j, 0, N){
            if(i == 0 || j == 0){
                grid[i][j] = 'W';
            } else{
                cin >> grid[i][j];
            }
        }
    }

    rep(i, 1, N){
        rep(j, 1, N){
            acc[i][j] = acc[i][j - 1] + (grid[i][j] == 'B');
        }
    }

    rep(j, 1, N){
        rep(i, 1, N){
            acc[i][j] += acc[i - 1][j];
        }
    }
/*
    rep(i, 0, N){
        rep(j, 0, N){
            cout << acc[i][j] << " ";
        }
        cout << endl;
    }
*/
    i32 A, B, C, D;
    rep(i, 1, Q){
        cin >> A >> B >> C >> D;
        cout << f(A + 1, B + 1, C + 1, D + 1) << endl;
    }

    return(0);
}

i64 f(i32 A, i32 B, i32 C, i32 D){
    return(
        g(C, D)
        - g(A - 1, D)
        - g(C, B - 1)
        + g(A - 1, B - 1)
    );
}

i64 g(i32 H, i32 W){
    if(H <= N && W <= N){
        return(acc[H][W]);
    }

    i64 Hq = H / N;
    i64 Hr = H % N;
    i64 Wq = W / N;
    i64 Wr = W % N;

    return(
        acc[N][N] * Hq * Wq
        + acc[Hr][N] * Wq
        + acc[N][Wr] * Hq
        + acc[Hr][Wr]
    );
}
