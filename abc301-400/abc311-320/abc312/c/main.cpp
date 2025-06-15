// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define MAX 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i32 N, M;
i32 A[MAX], B[MAX];

bool satisfy(i32 x){
    i32 seller = upper_bound(A, A + N, x) - A;
    i32 buyer = (B + M) - lower_bound(B, B + M, x);
    return(seller >= buyer);
}

int main(){
    cin.tie(nullptr);

    cin >> N >> M;

    rep(i, 0, N - 1){
        cin >> A[i];
    }
    rep(i, 0, M - 1){
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + M);

    i32 low = 0, mid, high = 1e9 + 1;
    while(1 < high - low){
        mid = (low + high) / 2;
        if(satisfy(mid)){
            high = mid;
        } else{
            low = mid;
        }
    }

    cout << high << endl;
    return(0);
}

