// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int main(){
    int32_t N;
    cin >> N;

    string S;
    set<string> strf, strb;
    rep(i, 0, N){
        cin >> S;

        if(strf.count(S) == 0 && strb.count(S) == 0){
            strf.insert(S);
            reverse(all(S));
            strb.insert(S);
        }
    }

    cout << strf.size() << endl;
}