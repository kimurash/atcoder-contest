// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int16_t N, M;
    cin >> N >> M;

    string C[N], D[M];
    int32_t P[M+1];

    rep(i, 0, N){
        cin >> C[i];
    }
    rep(i, 0, M){
        cin >> D[i];
    }
    rep(i, 0, M + 1){
        cin >> P[i];
    }

    int32_t sum = 0;
    rep(i, 0, N){
        bool flg = false;
        rep(j, 0, M){
            if(C[i] == D[j]){
                sum += P[j+1];
                flg = true;
                break;
            }
        }

        if(!flg){
            sum += P[0];
        }
    }

    cout << sum << endl;
}