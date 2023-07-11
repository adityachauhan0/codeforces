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
    ll n,k;
    cin >> n >> k;
    if (n < k) cout << k << endl;
    else {
        ll x = 2*k;
        while (x <= n){
            x += k;
        }
        cout << x << endl;
        return;
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