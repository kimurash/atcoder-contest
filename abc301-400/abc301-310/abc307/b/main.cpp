#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

// 回文か判定する関数
bool is_palindrome(string str1, string str2){
    string concat = str1 + str2;
    string rev = concat;

    reverse(all(rev));

    if(concat == rev){
        return(true);
    } else{
        return(false);
    }
}

int main(){
    int16_t N;
    cin >> N;

    string S[N];
    rep(i, 0, N){ cin >> S[i]; }

    rep(i, 0, N){
        rep(j, 0, N){
            if(i == j){
                continue;
            }
            if(is_palindrome(S[i], S[j])){
                cout << "Yes" << endl;
                return(0);
            }
        }
    }

    cout << "No" << endl;
}