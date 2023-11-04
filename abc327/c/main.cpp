// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

i16 A[10][10];

bool check1();
bool check2();
bool check3();

int main(){
    cin.tie(nullptr);
    
    rep(i, 1, 9){
        rep(j, 1, 9){
            cin >> A[i][j];
        }
    }

    if(check1() && check2() && check3()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return(0);
}

bool check1(){
    rep(i, 1, 9){
        i16 cnt[10] = {0};
        rep(j, 1, 9){
            cnt[A[i][j]]++;
            if(cnt[A[i][j]] > 1){
                return(false);
            }
        }
    }

    return(true);
}

bool check2(){
    rep(j, 1, 9){
        i16 cnt[10] = {0};
        rep(i, 1, 9){
            cnt[A[i][j]]++;
            if(cnt[A[i][j]] > 1){
                return(false);
            }
        }
    }

    return(true);
}

bool check3(){
    for(int i = 1;  i < 9; i += 3){
        for(int j = 1; j < 9; j += 3){
            i16 cnt[10] = {0};
            rep(k, 0, 2){
                rep(l, 0, 2){
                    i16 n = A[i + k][j + l];
                    cnt[n]++;
                    if(cnt[n] > 1){
                        return(false);
                    }
                }
            }
        }
    }

    return(true);
}