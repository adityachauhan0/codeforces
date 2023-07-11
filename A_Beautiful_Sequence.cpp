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
    for (ll i = 0; i < n; i++){
        if (a[i] <= (i+1)) {
            cout << "YES"<< endl;
            return;
        }
    }
    cout << "NO" << endl;
    
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