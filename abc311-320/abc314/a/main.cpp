// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    char pi[] = "1415926535897932384626433832"
                "7950288419716939937510582097"
                "4944592307816406286208998628"
                "0348253421170679";

    i16 N;
    cin >> N;

    pi[N] = '\0';
    cout << "3.";
    printf("%s\n", pi);

    return(0);
}