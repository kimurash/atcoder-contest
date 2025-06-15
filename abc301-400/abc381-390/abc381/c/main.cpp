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

i32 count(string S, i32 center);

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    string S;
    cin >> S;

    i32 ans = 1;

    rep(i, 0, N - 1){
        if(S[i] == '/'){
            i32 offset = count(S, i);
            ans = max(ans, 2 * (offset - 1) + 1);
            i += offset;
        }
    }

    cout << ans << endl;
    return(0);
}

i32 count(string S, i32 center){
    i32 offset = 1;
    while(0 <= center - offset && center + offset < S.size()){
        if(S[center - offset] != '1'){
            break;
        }
        if(S[center + offset] != '2'){
            break;
        }
        offset++;
    }

    return(offset);
}
