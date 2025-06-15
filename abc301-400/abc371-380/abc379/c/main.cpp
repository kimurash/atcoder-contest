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

typedef pair<int32_t, int32_t> pi32;

int main(){
    cin.tie(nullptr);

    i64 N;
    i32 M;
    cin >> N >> M;

    vector<pi32> stone(M);
    rep(i, 0, M - 1){
        cin >> stone[i].first;
    }
    i64 sum = 0;
    rep(i, 0, M - 1){
        cin >> stone[i].second;
        sum += stone[i].second;
    }

    if(sum != N){
        cout << -1 << endl;
        return(0);
    }

    sort(all(stone));

    i64 acc = 0;
    i64 init = 0;
    rep(i, 0, M - 1){
        i64 x = stone[i].first;
        i64 a = stone[i].second;

        if(acc < x - 1){
            cout << -1 << endl;
            return(0);
        } else{
            init += x * a;
        }

        acc += a;
    }

    cout << N * (N + 1) / 2 - init << endl;
    return(0);
}
