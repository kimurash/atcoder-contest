// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    i64 cumsum1[N + 1];
    i64 cumsum2[N + 1];

    cumsum1[0] = cumsum2[0] = 0;
    rep(i, 0, N - 1){
        if(S[i] == 'a'){
            cumsum1[i + 1] = cumsum1[i] + 1;
            cumsum2[i + 1] = cumsum2[i];
        } else if(S[i] == 'b'){
            cumsum1[i + 1] = cumsum1[i];
            cumsum2[i + 1] = cumsum2[i] + 1;
        }
    }

    i64 answer = 0;

    rep(l, 1, N){
        int ar = lower_bound(cumsum1, cumsum1 + N + 1, cumsum1[l - 1] + A) - cumsum1;
        int br = lower_bound(cumsum2, cumsum2 + N + 1, cumsum2[l - 1] + B) - cumsum2 - 1;
        answer += max(0, br - ar + 1);
    }

    cout << answer << endl;

    return(0);
}
