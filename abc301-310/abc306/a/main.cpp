#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    cin >> N;

    char S;
    rep(i, 0, N){
        cin >> S;
        printf("%c%c", S, S);
    }
    cout << endl;
}