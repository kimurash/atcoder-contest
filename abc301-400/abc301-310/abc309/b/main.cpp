// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    cin >> N;

    char cell;
    int16_t A;
    int16_t B[N][N];
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> cell;
            A = cell - '0';

            if(i == 0){
                if(j == N - 1){
                    B[i + 1][j] = A;
                } else{
                    B[i][j + 1] = A;
                }
            } else if(i == N - 1){
                if(j == 0){
                    B[i - 1][j] = A;
                } else{
                    B[i][j - 1] = A;
                }
            } else{ // 1 <= i <= N - 2
                if(j == 0){
                    B[i - 1][j] = A;
                } else if(j == N - 1){
                    B[i + 1][j] = A;
                } else{
                    B[i][j] = A;
                }
            }
        }
    }

    rep(i, 0, N){
        rep(j, 0, N){
            cout << B[i][j];
        }
        cout << endl;
    }
}