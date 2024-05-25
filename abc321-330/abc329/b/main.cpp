// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

#define MAX 109

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i16 a;
    vector<i16> A;
    bool exist[MAX] = {false};

    rep(i, 0, N - 1){
        cin >> a;
        if(!exist[a]){
            A.push_back(a);
            exist[a] = true;
        }
    }

    sort(all(A));
    cout << A[A.size() - 2] << endl;

    return(0);
}