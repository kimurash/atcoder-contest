// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef pair<int32_t, int32_t> pi32;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 vote, ans = 0;
    i32 cnt[N + 1] = {0}; // 候補者の得票数
    rep(i, 1, M){
        cin >> vote;
        cnt[vote]++;
        if(cnt[ans] <cnt[vote]){
            ans = vote;
        } else if(cnt[ans] == cnt[vote]){
            ans = min(ans, vote);
        }
        cout << ans << endl;
    }
    
    return(0);
}