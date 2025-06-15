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

i64 N;
i64 cnt;
set<i64> dang;

void stamp(i32 i, i32 j);
void check(i32 i, i32 j);

int main(){
    cin.tie(nullptr);

    i32 M;
    cin >> N >> M;

    i32 a, b;
    rep(i, 1, M){
        cin >> a >> b;
        stamp(a, b);
    }

    i64 ans = N * N - cnt;
    cout << ans << endl;
    return(0);
}

void stamp(i32 i, i32 j){
    check(i, j);

    check(i + 2, j + 1);
    check(i + 1, j + 2);

    check(i - 1, j + 2);
    check(i - 2, j + 1);

    check(i - 2, j - 1);
    check(i - 1, j - 2);

    check(i + 1, j - 2);
    check(i + 2, j - 1);

    return;
}

void check(i32 i, i32 j){
    if(1 <= i && i <= N && 1 <= j && j <= N){
        i64 id = i * N + j;
        if(dang.count(id) == 0){
            dang.insert(id);
            cnt++;
        }
    }
}
