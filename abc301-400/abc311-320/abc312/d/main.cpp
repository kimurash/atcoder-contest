// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;
using mint = atcoder::modint998244353;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);
    
    string S;
    cin >> S;

    mint table[S.size() + 1][S.size() + 1];
    table[0][0] = 1;
    rep(j, 1, S.size()){
        table[0][j] = 0;
    }

    rep(i, 1, S.size()){
        rep(j, 0, S.size() - 1){
            if(S[i - 1] != ')'){
                table[i][j + 1] += table[i - 1][j];
            }
            if(j > 0 && S[i - 1] != '('){
                table[i][j - 1] += table[i - 1][j];
            }
        }
    }

    cout << table[S.size()][0].val() << endl;
    return(0);
}