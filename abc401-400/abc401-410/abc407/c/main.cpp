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

    string S;
    cin >> S;

    i32 size = S.size();
    i64 ans = size;

    for(int i = size - 1; 0 <= i; i--){
        i32 n = S[i] - '0';
        i32 m = i < size - 1 ? S[i + 1] - '0' : 0;
        i32 cnt = (n - m + 10) % 10;

        ans += cnt;
    }

    cout << ans << endl;

    return(0);
}
