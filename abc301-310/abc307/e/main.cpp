#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

#define MODULUS 998'244'353

using namespace std;

int main(){
    int64_t N, M;
    cin >> N >> M;

    int64_t mpow = M - 1; // M-1のべき乗

    int64_t ans[N + 1] = {0};
    // ans[1] = M;
    ans[2] = (M * (M - 1)) % MODULUS;
    rep(i, 3, N + 1){
        mpow = (mpow * (M - 1)) % MODULUS;
        ans[i] = (M * mpow - ans[i-1]) % MODULUS;
        if(ans[i] < 0){
            ans[i] += MODULUS;
        }
    }

    cout << ans[N] << endl;
}