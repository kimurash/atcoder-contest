#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MAX 10

using namespace std;

char A[MAX][MAX];
char B[MAX][MAX];
char X[MAX][MAX];

char C[3 * MAX][3 * MAX];

bool judge();

void init_c();
void print_c();
void paste_a(int ax, int ay);
void paste_b(int bx, int by);

bool include_ab(int ax, int ay, int bx, int by);
bool match_x();

int main(){
    int16_t H, W;

    cin >> H >> W;
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            if(i < H && j < W){
                cin >> A[i][j];
            } else{
                A[i][j] = '.';
            }
        }
    }

    cin >> H >> W;
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            if(i < H && j < W){
                cin >> B[i][j];
            } else{
                B[i][j] = '.';
            }
        }
    }

    cin >> H >> W;
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            if(i < H && j < W){
                cin >> X[i][j];
            } else{
                X[i][j] = '.';
            }
        }
    }

    if(judge()){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}

bool judge(){
    // 下方向にx軸をとり,右方向にy軸をとる
    rep(i, 1, 2 * MAX){ // Aの左上x座標
        rep(j, 1, 2 * MAX){ // Aの左上y座標
            rep(k, 1, 2 * MAX){ // Bの左上x座標
                rep(l, 1, 2 * MAX){ // Bの左上y座標
                    init_c();
                    paste_a(i, j);
                    paste_b(k, l);
///*
                    if(!include_ab(i, j, k, l)){
                        continue;
                    }
                    if(!match_x()){
                        continue;
                    }
                    return(true);
//*/
                }
            }
        }
    }

    return(false);
}

void init_c(){
    rep(i, 0, 3 * MAX){
        rep(j, 0, 3 * MAX){
            C[i][j] = '.';
        }
    }
}

void print_c(){
    rep(i, 0, 3 * MAX){
        rep(j, 0, 3 * MAX){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

void paste_a(int ax, int ay){
    rep(i, ax, ax + MAX){
        rep(j, ay, ay + MAX){
            C[i][j] = A[i - ax][j - ay];
        }
    }
}

void paste_b(int bx, int by){
    rep(i, bx, bx + MAX){
        rep(j, by, by + MAX){
            // 黒を上書きしてはいけない
            if(C[i][j] == '.'){
                C[i][j] = B[i - bx][j - by];
            }
        }
    }
}

bool include_ab(int ax, int ay, int bx, int by){
    // Aの黒マスを全て含んでいるか?
    rep(i, ax, ax + MAX){
        rep(j, ay, ay + MAX){
            if(C[i][j] == '#'){
                if(!(MAX <= i && i < 2 * MAX)
                    || !(MAX <= j && j < 2 * MAX)){
                    return(false);
                }
            }
        }
    }

    // Bの黒マスを全て含んでいるか?
    rep(i, bx, bx + MAX){
        rep(j, by, by + MAX){
            if(C[i][j] == '#'){
                if(!(MAX <= i && i < 2 * MAX)
                    || !(MAX <= j && j < 2 * MAX)){
                    return(false);
                }
            }
        }
    }

    return(true);
}

bool match_x(){
    rep(i, 0, MAX){
        rep(j, 0, MAX){
            if(X[i][j] != C[i + MAX][j + MAX]){
                return(false);
            }
        }
    }

    return(true);
}