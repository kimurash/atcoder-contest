// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

char P1[3][4][4];
char P2[3][4][4];

void print_ans(string ans);

void copy(char src[][4], char dst[][4]);
void rotate(char src[][4], char dst[][4]);

void recur(i16 depth, char grid[][4]);

bool can_paste(char poly[][4], char grid[][4], i16 si, i16 sj);
bool in_grid(i16 i, i16 j);
bool is_fill(char grid[][4]);

int main(){
    cin.tie(nullptr);

    rep(i, 0, 2){
        rep(j, 0, 3){
            rep(k, 0, 3){
                cin >> P1[i][j][k];
            }
        }
    }

    char grid[4][4];
    rep(i, 0, 3){
        rep(j, 0, 3){
            grid[i][j] = '.';
        }
    }

    rep(i, 0, 3){
        rep(j, 0, 3){
            rep(k, 0, 3){
                recur(0, grid);

                rotate(P1[2], P2[2]);
                copy(P2[2], P1[2]);
            }

            rotate(P1[1], P2[1]);
            copy(P2[1], P1[1]);
        }

        rotate(P1[1], P2[1]);
        copy(P2[1], P1[1]);
    }

    cout << "No" << endl;
    return(0);
}

void print_ans(string ans){
    cout << ans << endl;
    exit(0);
}


void copy(char src[][4], char dst[][4]){
    rep(i, 0, 3){
        rep(j, 0, 3){
            dst[i][j] = src[i][j];
        }
    }

    return;
}

void rotate(char src[][4], char dst[][4]){
    rep(i, 0, 3){
        rep(j, 0, 3){
            dst[j][3 - i] = src[i][j];
        }
    }

    return;
}

void recur(i16 depth, char grid[][4]){
    if(depth >= 3){
        if(is_fill(grid)){
            print_ans("Yes");
        }
        return;
    }

    rep(si, -3, 3){
        rep(sj, -3, 3){
            char clone[4][4];
            copy(grid, clone);

            if(can_paste(P1[depth], clone, si, sj)){
                recur(depth + 1, clone);
            }
        }
    }
}

bool can_paste(char poly[][4], char grid[][4], i16 si, i16 sj){
    rep(i, 0., 3){
        rep(j, 0, 3){
            if(poly[i][j] == '#'){
                if(!in_grid(si + i, sj + j)){
                    return(false);
                }
                if(grid[si + i][sj + j] == '#'){
                    return(false);
                }
                grid[si + i][sj + j] = poly[i][j];
            }
        }
    }

    return(true);
}

bool in_grid(i16 i, i16 j){
    return(0 <= i && i <= 3 && 0 <= j && j <= 3);
}

bool is_fill(char grid[][4]){
    rep(i, 0, 3){
        rep(j, 0, 3){
            if(grid[i][j] != '#'){
                return(false);
            }
        }
    }

    return(true);
}