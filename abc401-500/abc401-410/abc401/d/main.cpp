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

    i32 N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    string T = S;
    // oの両隣を.にする
    rep(i, 0, N - 1){
        if(T[i] == 'o'){
            if(0 <= i - 1){
                T[i - 1] = '.';
            }
            if(i + 1 < N){
                T[i + 1] = '.';
            }
        }
    }

    // あと何個の?をoにする必要があるか
    i32 rem = K;
    rep(i, 0, N - 1){
        if(T[i] == 'o'){
            rem--;
        }
    }

    // ?の区間を格納する配列
    vector<pi32> intervals;

    // ?の区間を取得する
    rep(i, 0, N - 1){
        if(T[i] == '?'){
            i32 r = i;
            while(r < N && T[r] == '?'){
                r++;
            }
            intervals.push_back({i, r});
            i = r - 1;
        }
    }

    // oにできる?の最大個数
    int maxo = 0;
    for(auto [l, r] : intervals){
        maxo += (r - l + 1) / 2;
    }

    if(rem == 0){ // 全ての?を.にする
        for(auto [l, r] : intervals){
            rep(i, l, r - 1){
                T[i] = '.';
            }
        }
    } else if(rem == maxo){ // oにできる全ての?をoにする
        for(auto [l, r] : intervals){
            if((r - l) % 2 == 0){
                continue;
            }
            bool odd = true;
            for(i32 i = l; i < r; i++){
                if(odd){
                    T[i] = 'o';
                } else{
                    T[i] = '.';
                }
                odd = !odd;
            }
        }
    }

    cout << T << endl;

    return(0);
}
