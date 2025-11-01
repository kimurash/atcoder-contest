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

    i32 N, Q;
    cin >> N >> Q;

    i32 A[N];
    rep(i, 0, N - 1){
        A[i] = i + 1;
    }

    i32 rotate_cnt = 0;

    i16 query;
    rep(i, 1, Q){
        cin >> query;

        if(query == 1){
            i32 p, x;
            cin >> p >> x;

            i32 idx = (p - 1 + rotate_cnt) % N;
            A[idx] = x;

        } else if(query == 2){
            i32 p;
            cin >> p;

            i32 idx = (p - 1 + rotate_cnt) % N;
            cout << A[idx] << endl;

        } else if(query == 3){
            i32 k;
            cin >> k;

            rotate_cnt = (rotate_cnt + k) % N;
        }
    }

    return(0);
}
