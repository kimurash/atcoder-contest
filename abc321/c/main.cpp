// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return(true);
    }
    return(false);
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return(true);
    }
    return(false);
}

int main(){
    cin.tie(nullptr);

    i64 K;
    cin >> K;

    vector<i64> ans;
    for (int b = 2; b < (1 << 10); b++) {
        bitset<10> bs(b);
        i64 num = 0;
        for(int d = 9; d >= 0; d--){
            if(bs.test(d)){
                num *= 10;
                num += d;
            }
        }
        ans.push_back(num);
    }

    sort(all(ans));

    cout << ans[K - 1] << endl;
    return(0);
}