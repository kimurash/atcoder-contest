// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 L[N];
    i64 low = 0, mid, high = 0;
    rep(i, 0, N - 1){
        cin >> L[i];

        if(L[i] > low){
            low = L[i];
        }

        high += L[i] + 1;
    }

    low--;

    while(low + 1 < high){
        mid = (low + high) / 2; // 横幅

        i64 cnt = 1;
        i64 rem = mid;
        rep(i, 0, N - 1){
            if(rem < L[i]){
                cnt++;
                rem = mid - L[i];
            } else{ // L[i] <= rem
                rem -= L[i];
            }

            if(rem > 0){
                rem--;
            }
        }

        if(cnt > M){ // 横幅が足りない
            low = mid;
        } else{ // 横幅が足りている
            high = mid;
        }
    }

    cout << high << endl;
    return(0);
}