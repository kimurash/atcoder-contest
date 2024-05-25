// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define COLOR 26

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int16_t, int16_t> pi16;


int main(){
    cin.tie(nullptr);

    i16 H, W;
    cin >> H >> W;

    // 行|列の色の数を管理する配列
    i16 row_color[H + 1][COLOR];
    i16 col_color[W + 1][COLOR];
    rep(i, 1, H){
        rep(color, 0, COLOR - 1){
            row_color[i][color] = 0;
        }
    }
    rep(j, 1, W){
        rep(color, 0, COLOR - 1){
            col_color[j][color] = 0;
        }
    }

    char cookie[H + 1][W + 1];
    rep(i, 1, H){
        rep(j, 1, W){
            cin >> cookie[i][j];
            row_color[i][cookie[i][j] - 'a']++;
            col_color[j][cookie[i][j] - 'a']++;
        }
    }

    // 取り除かれた行|列を管理する配列
    bool row[H + 1];
    bool col[W + 1];
    rep(i, 1, H){
        row[i] = false;
    }
    rep(j, 1, W){
        col[j] = false;
    }

    i16 nrow = H, ncol = W;
    while(nrow >= 2 && ncol >= 2){
        vector<pi16> row_rmv;
        rep(i, 1, H){
            if(row[i]){
                continue;
            }

            rep(color, 0, COLOR - 1){
                if(row_color[i][color] == ncol && ncol >= 2){
                    // 列番号と色をペアで記録する
                    // - 列が取り除かれたことを記録するため
                    // - 取り除く色を列方向のカウントから引くため
                    row_rmv.push_back(make_pair(i, color));
                    break;
                }
            }
        }

        vector<pi16> col_rmv;
        rep(j, 1, W){
            if(col[j]){
                continue;
            }

            rep(color, 0, COLOR - 1){
                if(col_color[j][color] == nrow && nrow >= 2){
                    col_rmv.push_back(make_pair(j, color));
                    break;
                }
            }
        }

        if(row_rmv.size() == 0 && col_rmv.size() == 0){
            break;
        }

        for(pi16 p: row_rmv){
            rep(j, 1, W){
                col_color[j][p.second]--;
            }
            row[p.first] = true;
            nrow--;
        }

        for(pi16 p: col_rmv){
            rep(i, 1, H){
                row_color[i][p.second]--;
            }
            col[p.first] = true;
            ncol--;
        }
    }

    cout << nrow * ncol << endl;
    return(0);
}