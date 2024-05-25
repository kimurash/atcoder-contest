// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    string S;
    cin >> N >> S;

    int16_t cnter[3] = {0};
    rep(i, 0, N - 1){
        cnter[S[i] - 'A']++;
        if(cnter[0] > 0 && cnter[1] > 0 && cnter[2] > 0){
            cout << i + 1 << endl;
            return(0);
        }
    }
    
    return(0);
}