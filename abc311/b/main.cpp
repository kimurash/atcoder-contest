// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

int main(){
    int16_t N, D;
    cin >> N >> D;

    string S[N];
    rep(i, 0, N - 1){
        cin >> S[i];
    }

    int16_t maxspan = 0, span = 0;
    rep(d, 0, D - 1){
        bool allfree = true;
        rep(n, 0, N - 1){
            if(S[n][d] != 'o'){
                allfree = false;
                break;
            }
        }

        if(allfree){
            span++;
            maxspan = max(maxspan, span);
        } else{
            span = 0;
        }
    }

    cout << maxspan << endl;
    return(0);
}