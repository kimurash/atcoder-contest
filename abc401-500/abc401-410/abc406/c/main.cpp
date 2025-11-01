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

    i32 N;
    cin >> N;

    i32 P[N + 1];
    rep(i, 1, N){
        cin >> P[i];
    }

    string S = "";
    rep(i, 1, N - 1){
        if(P[i] < P[i + 1]){
            S += "<";
        } else if(P[i] > P[i + 1]){
            S += ">";
        }
    }

    vector<pair<char, i32>> vp;
    char ch = S[0];
    i32 cnt = 0;
    rep(i, 0, S.size() - 1){
        if(ch == S[i]){
            cnt++;
        } else{
            vp.push_back({ch, cnt});
            ch = S[i];
            cnt = 1;
        }
    }
    vp.push_back({ch, cnt});

    i64 ans = 0;
    for(int i = 1; i < vp.size() - 1; i++){
        pair<char, i32> p = vp[i];

        if(p.first == '<'){
            continue;
        }

        i64 a = vp[i - 1].second;
        i64 b = vp[i + 1].second;

        ans += a * b;
    }

    cout << ans << endl;
    return(0);
}
