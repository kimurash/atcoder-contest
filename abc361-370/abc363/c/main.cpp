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

bool check(string S){
    string T = S;
    reverse(all(T));
    return(S == T);
}

int main(){
    cin.tie(nullptr);

    i16 N, K;
    string S;
    cin >> N >> K >> S;

    sort(all(S));

    i32 cnt = 0;
    do{
        bool include = false;
        rep(i, 0, N - K){
            string T = S.substr(i, K);
            if(check(T)){
                include = true;
                break;
            }
        }
        if(!include){
            cnt++;
        }
    } while(next_permutation(all(S)));

    cout << cnt << endl;
    return(0);
}
