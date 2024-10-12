// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 30009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

typedef pair<int32_t, int32_t> pi32;

i32 N;
char grid1[MAX][MAX];
char grid2[MAX][MAX];

void rotate(i32 depth);
pi32 dst(i32 i, i32 j, i16 total);

int main(){
    cin.tie(nullptr);

    cin >> N;

    rep(i, 1, N){
        rep(j, 1, N){
            cin >> grid1[i][j];
        }
    }

    rotate(1);

    rep(i, 1, N){
        rep(j, 1, N){
            cout << grid2[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return(0);
}

void rotate(i32 depth){
    if(N / 2 < depth){
        return;
    }

    i16 total = depth % 4;
    i32 end = N - depth + 1;
    
    i32 ni, nj;
    rep(j, depth, end){
        tie(ni, nj)  = dst(depth, j, total);
        grid2[ni][nj] = grid1[depth][j];
    }

    rep(i, depth + 1, N - depth){
        tie(ni, nj)  = dst(i, depth, total);
        grid2[ni][nj] = grid1[i][depth];

        tie(ni, nj)  = dst(i, end, total);
        grid2[ni][nj] = grid1[i][end];
    }

    rep(j, depth, end){
        tie(ni, nj)  = dst(end, j, total);
        grid2[ni][nj] = grid1[end][j];
    }

    rotate(depth + 1);
}

pi32 dst(i32 i, i32 j, i16 total){
    switch(total){
        case 1:
            return {j, N - i + 1};
        case 2:
            return {N - i + 1, N - j + 1};
        case 3:
            return {N - j + 1, i};
        default:
            return {i, j};
    }
}
