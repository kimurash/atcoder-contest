// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

    char grid[5][5];

void clear_grid(i16 N);

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    string R, C;
    cin >> R >> C;

    vector<i16> apos(N), bpos(N), cpos(N);
    rep(i, 0, N - 1){
        apos[i] = bpos[i] = cpos[i] = i;
    }

    do{
        do{
            do{
                bool meet = true;
                rep(i, 0, N - 1){
                    if(apos[i] == bpos[i] || bpos[i] == cpos[i] || cpos[i] == apos[i]){
                        meet = false;
                        break;
                    }
                }
                if(!meet){
                    continue;
                }

                clear_grid(N);
                rep(i, 0, N - 1){
                    grid[i][apos[i]] = 'A';
                    grid[i][bpos[i]] = 'B';
                    grid[i][cpos[i]] = 'C';
                }

                rep(i, 0, N - 1){
                    rep(j, 0, N - 1){
                        if(grid[i][j] != '.'){
                            if(grid[i][j] == R[i]){
                                break;
                            } else{
                                meet = false;
                            }
                        }
                    }
                }
                if(!meet){
                    continue;
                }

                rep(j, 0, N - 1){
                    rep(i, 0, N - 1){
                        if(grid[i][j] != '.'){
                            if(grid[i][j] == C[j]){
                                break;
                            } else{
                                meet = false;
                            }
                        }
                    }
                }
                if(!meet){
                    continue;
                }

                cout << "Yes" << endl;
                rep(i, 0, N - 1){
                    rep(j, 0, N - 1){
                        cout << grid[i][j];
                    }
                    cout << endl;
                }
                return(0);

            } while (next_permutation(all(cpos)));
        } while (next_permutation(all(bpos)));
    } while (next_permutation(all(apos)));

    cout << "No" << endl;
    return(0);
}

void clear_grid(i16 N){
    rep(i, 0, N - 1){
        rep(j, 0, N - 1){
            grid[i][j] = '.';
        }
    }
}