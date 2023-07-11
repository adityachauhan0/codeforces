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
    ll sm = 0;
    bool nch = false;
    for (ll i =0; i < n; i++){
        ll x; cin >> x;
        a.push_back(x);
        if (x == -1){
            nch = true;
        }
        sm += x;
    }
    bool dch = false;
    for (ll i = 0; i < n-1; i++){
        if (a[i] == -1 && a[i+1] == -1){
            dch = true;
            break;
        }
    }
    if (dch){
        cout << sm + 4 << endl;
        return;
    }
    if (!nch){
        cout << sm - 4 << endl;
        return;
    }
    cout << sm << endl;
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