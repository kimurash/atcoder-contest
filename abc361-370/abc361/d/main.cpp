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

bool check(string S, string T);

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    S += "..";
    T += "..";

    if(!check(S, T)){
        cout << -1 << endl;
        return(0);
    }

    queue<string> yet;
    map<string, i32> dist;
    
    yet.push(S);
    dist[S] = 0;
    
    while(!yet.empty()){
        string now = yet.front();
        yet.pop();

        if(now == T){
            cout << dist[now] << endl;
            return(0);
        }

        i16 j;
        rep(i, 0, N){
            if(now[i] == '.' && now[i + 1] == '.'){
                j = i;
                break;
            }
        }

        rep(i, 0, N){
            if(now[i] != '.' && now[i + 1] != '.'){
                string next = now;
                next[j]     = now[i];
                next[j + 1] = now[i + 1];
                next[i]     = '.';
                next[i + 1] = '.';
                if(dist.count(next) == 0){
                    dist[next] = dist[now] + 1;
                    yet.push(next);
                }
            }
        }
    }

    cout << -1 << endl;
    return(0);
}

bool check(string S, string T){
    i16 w1 = 0, w2 = 0;
    i16 b1 = 0, b2 = 0;
    
    rep(i, 0, S.size()){
        if(S[i] == 'W') w1++;
        if(T[i] == 'W') w2++;
        if(S[i] == 'B') b1++;
        if(T[i] == 'B') b2++;
    }

    return(w1 == w2 && b1 == b2);
}
