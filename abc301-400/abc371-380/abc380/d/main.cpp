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

string S;
vi64 sizevec;

char recur(i64 K);
char flip(char c);

int main(){
    cin.tie(nullptr);

    cin >> S;

    i64 len = S.length();
    rep(i, 0, 60){
        sizevec.push_back(len);
        len *= 2;
    }

    i32 Q;
    cin >> Q;

    i64 K;
    rep(i, 1, Q){
        cin >> K;
        if(i != 1){
            cout << " ";
        }
        cout << recur(K);
    }
    cout << endl;

    return(0);
}

char recur(i64 K){
    if(K <= sizevec[0]){
        return(S[K - 1]);
    }

    rep(i, 1, 60){
        if(K <= sizevec[i]){
            i64 offset = K - sizevec[i - 1];
            char c = recur(offset);
            return(flip(c));
        }
    }

    // never reach here
    return('A');
}

char flip(char c){
    if('a' <= c && c <= 'z'){
        return('A' + c - 'a');
    }else{
        return('a' + c - 'A');
    }
}
