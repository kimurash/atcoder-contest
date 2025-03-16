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

    i32 N;
    cin >> N;

    i32 A[N + 1];
    rep(i, 1, N){
        cin >> A[i];
    }

    set<i32> st;
    i32 fwd[N + 1];
    fwd[0] = 0;
    rep(i, 1, N){
        if(st.count(A[i]) == 0){
            st.insert(A[i]);
            fwd[i] = fwd[i - 1] + 1;
        } else {
            fwd[i] = fwd[i - 1];
        }
    }

    st.clear();

    i32 bwd[N + 2];
    bwd[N + 1] = 0;
    for(int i = N; 0 < i; i--){
        if(st.count(A[i]) == 0){
            st.insert(A[i]);
            bwd[i] = bwd[i + 1] + 1;
        } else {
            bwd[i] = bwd[i + 1];
        }
    }

    i32 ans = 0;
    rep(i, 1, N - 1){
        i32 sum = fwd[i] + bwd[i + 1];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return(0);
}
