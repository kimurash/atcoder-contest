// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 2000'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

vi64 sieve(i64 N);

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    vector<i64> primes = sieve(MAX);

    i64 ans = 0;

    for(i64 p : primes){
        for(i64 q : primes){
            if(p <= q){
                break;
            }
            if(p * p * q * q <= N){
                ans++;
            } else{
                break;
            }
        }
    }

    for(i64 p : primes){
        i64 cand = 1;
        rep(i, 1, 8){
            cand *= p;
        }
        if(cand <= N){
            ans++;
        } else{
            break;
        }
    }

    cout << ans << endl;
    return(0);
}

vi64 sieve(i64 N){
    bool deleted[N + 1];

    for(i64 i = 2; i <= N; i++){
        deleted[i] = false;
    }

    vi64 primes;

    for(i64 i = 2; i * i <= N; i++){
        if(deleted[i]){
            continue;
        }

        for(i64 j = i * 2; j <= N; j += i){
            deleted[j] = true;
        }
    }

    for(i64 i = 2; i <= N; i++){
        if(!deleted[i]){
            primes.push_back(i);
        }
    }

    return primes;
}
