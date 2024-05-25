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

    i32 N;
    cin >> N;

    string T;
    cin >> T;
    i32 tlen = T.length();

    string S;
    i32 slen;
    vector<i32> ans;
    rep(i, 1, N){
        cin >> S;
        slen = S.length();

        if(tlen == slen){ // 置換
            i32 cnt = 0;
            rep(j, 0, tlen - 1){
                if(T[j] != S[j]){
                    cnt++;
                    if(cnt > 1){
                        break;
                    }
                }
            }
            if(cnt <= 1){
                ans.push_back(i);
            }
        } else if(abs(slen - tlen) == 1){
            i32 idx = 0;
            if(slen > tlen){ // 削除
                rep(j, 0, slen - 1){
                    if(T[idx] == S[j]){
                        idx++;
                    }
                }
                if(idx == tlen){
                    ans.push_back(i);
                }
            } else{ // 挿入
                rep(j, 0, tlen - 1){
                    if(T[j] == S[idx]){
                        idx++;
                    }
                }
                if(idx == slen){
                    ans.push_back(i);
                }
            }
        }
    }

    cout << ans.size() << endl;
    if(ans.size() > 0){
        cout << ans[0];
        rep(i, 1, ans.size() - 1){
            printf(" %d", ans[i]);
        }
    }
    cout << endl;

    return(0);
}