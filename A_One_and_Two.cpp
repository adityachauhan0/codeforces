#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define st string
#define vi vector<ll>
#define li list<ll>
using namespace std;

void solve () 
{
    ll n;
    cin >> n;
    vi a = {};
    ll cnt = 0;
    for (ll i = 0; i < n; i++){
        ll x; cin >> x;
        a.push_back(x);
        if (x == 2){
            cnt ++;
        }
    }
    if (cnt == 0){
        cout << 1 << endl;
        return;
    }
    if (cnt % 2 == 0){
        ll cntt = 0;
        for (ll i = 0; i < n; i++){
            if (a[i] == 2){
                cntt ++;
                if (cntt == cnt/2){
                    cout << i+1 << endl;
                    return;
                }
            }
        }

    }
    else {
        cout << "-1" << endl;
    }
}

int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) 
        solve(); 
    return 0;
}  