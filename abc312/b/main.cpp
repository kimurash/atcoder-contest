// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAX 109

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

string ul[] = {
    "###.",
    "###.",
    "###.",
    "....",
};

string lr[] = {
    "....",
    ".###",
    ".###",
    ".###",
};

char grid[MAX][MAX];

bool is_tak_code(i16 i, i16 j){
    // 左上を確認
    rep(k, 0, 3){
        rep(l, 0, 3){
            if(grid[i + k][j + l] != ul[k][l]){
                return(false);
            }
        }
    }

    // 右下を確認
    rep(k, 0, 3){
        rep(l, 0, 3){
            if(grid[i + 5 + k][j + 5 + l] != lr[k][l]){
                return(false);
            }
        }
    }

    return(true);
}

int main(){
    cin.tie(nullptr);
    
    i16 N, M;
    cin >> N >> M;

    rep(i, 1, N){
        rep(j, 1, M){
            cin >> grid[i][j];
        }
    }

    rep(i, 1, N - 9 + 1){
        rep(j, 1, M - 9 + 1){
            if(is_tak_code(i, j)){
                printf("%d %d\n", i, j);
            }
        }
    }

    return(0);
}