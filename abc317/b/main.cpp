// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

#define MAX 1009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 A[N];
    rep(i, 0, N - 1){
        cin >> A[i];
    }

    sort(A, A + N);

    rep(i, 0, N - 2){
        if(A[i + 1] - A[i] >= 2){
            cout << A[i] + 1 << endl;
            break;
        }
    }

    return(0);
}