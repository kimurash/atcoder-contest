#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t N;
    cin >> N;

    rep(i, 0, N){
        int32_t A;
        int32_t sum = 0;
        rep(i, 0, 7){
            cin >> A;
            sum += A;
        }
        if(i != 0){
            cout << " ";
        }
        cout << sum;
    }
    cout << endl;
}