// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i64 sum = 0;
    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
        sum += A[i];
    }
    i64 ave = sum / N;
    i64 rem = sum % N;

    sort(A, A + N);

    i64 diff_sum = 0;
    rep(i, 0, N - 1){
        if(i < N - rem){
            diff_sum += abs(A[i] - ave);
        } else{
            diff_sum += abs(A[i] - (ave + 1));
        }
    }

    cout << diff_sum / 2 << endl;
    return(0);
}