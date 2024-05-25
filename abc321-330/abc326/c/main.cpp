// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    sort(A, A + N);

    i32 ans = 0;
    rep(i, 0, N - 1){
        i32 end = lower_bound(A, A + N, A[i] + M) - A;
        ans = max(ans, end - i);
    }

    cout << ans << endl;
    return(0);
}