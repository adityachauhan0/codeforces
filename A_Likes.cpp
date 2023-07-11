#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define st string
#define vi vector<ll>
#define li list<ll>
#define pb push_back
#define endl "\n"
#define vp vector<pair<ll,ll>>
using namespace std;

void solve () 
{
    ll n;
    cin >> n;
    vi a(n);
    for (ll &i : a) cin >> i;
    ll pc = 0, nc = 0;
    for (ll i : a) {
        if (i > 0) pc++;
        else if (i < 0) nc++;
    }
    ll ppc = pc - nc;
    for (ll i = 1; i <= pc; i++){
        cout << i << " ";
    }
    for (ll i = pc-1; i >= ppc; i--){
        cout << i<< " ";
    }
    cout << endl;
    
    while (nc--){
        cout << 1 << " "<< 0 << " ";
    }
    for (ll i = 1; i <= ppc; i++){
        cout << i << " ";
    }
    cout << endl;
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