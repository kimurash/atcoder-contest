// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    char vowel[] = {'a', 'i', 'u', 'e', 'o'};

    rep(i, 0, S.size() - 1){
        bool flg = true;
        rep(j, 0, 4){
            if(S[i] == vowel[j]){
                flg = false;
                break;
            }
        }

        if(flg){
            cout << S[i];
        }
    }
    cout << endl;

    return(0);
}