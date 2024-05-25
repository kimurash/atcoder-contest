// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    char answer[N + 2];
    rep(i, 0, N){
        i16 result = 0;
        rep(j, 1, 9){
            if(N % j != 0){
                continue;
            }
            i32 q = N / j;
            if(i % q != 0){
                continue;
            }
            result = j;
            break;
        }

        if(result == 0){
            answer[i] = '-';
        } else{
            answer[i] = '0' + result;
        }
    }

    answer[N + 1] = '\0';
    printf("%s\n", answer);

    return(0);
}