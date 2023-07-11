#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define st string
#define vi vector<ll>
#define li list<ll>
using namespace std;

void solve () 
{
    ll n,m; cin >> n >> m;
    vi a(n), b(m);
    for (ll &i : a) cin >> i;
    for (ll &i : b) cin >> i;
    sort(a.begin(),a.end());
    ll i = 0;
    ll j = 0;
    while (j < m){
        for (ll i = 0; i < n; i++){
            
            if (j== m) break;
            a[i] = b[j];
            j++;
        }
        sort(a.begin(),a.end());
    }
    ll sm = 0;
    for (ll i : a) sm += i;
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