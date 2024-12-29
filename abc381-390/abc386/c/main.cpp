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

bool check(string S, string T, int pos);

int main(){
    cin.tie(nullptr);

    i16 K;
    cin >> K;

    string S, T;
    cin >> S >> T;

    if(S == T){
        cout << "Yes" << endl;
        return(0);
    }

    int slen = S.size();
    int tlen = T.size();

    if(K < abs(slen - tlen)){
        cout << "No" << endl;
        return(0);
    }

    if(slen == tlen){
        int cnt = 0;
        rep(i, 0, slen - 1){
            if(S[i] != T[i]){
                cnt++;
            }
        }
        if(cnt <= K){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    } else{
        int fcnt = 0;
        int bcnt = 0;
        int minlen = min(slen, tlen);
        
        while(fcnt < minlen && S[fcnt] == T[fcnt]){
            fcnt++;
        }

        while(bcnt < minlen && S[(slen - 1) - bcnt] == T[(tlen - 1) - bcnt]){
            bcnt++;
        }

        if(minlen <= fcnt + bcnt){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }

    return(0);
}

