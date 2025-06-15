// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    string ans;
    for(char c: S){
        ans += c;
        if(ans.size() >= 3
            && ans.substr(ans.size() - 3) == "ABC"){
            ans.erase(ans.end() - 3, ans.end());
        }
    }

    return(0);
}