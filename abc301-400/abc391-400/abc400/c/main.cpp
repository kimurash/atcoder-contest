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

    i64 N;
    cin >> N;

    i64 cnt = 0;

    for(i64 A = 2; A <= N; A *= 2){
        i64 low = 1;
        i64 high = 1e9 + 9;

        while(low + 1 < high){
            i64 b = (low + high) / 2;
            if(b <= N / A / b){
                low = b;
            } else{
                high = b;
            }
        }
        cnt += (low + 1) / 2;
    }

    cout << cnt << endl;

    return(0);
}
