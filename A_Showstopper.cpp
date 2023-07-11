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
    vi b(n);
    for (ll &i : a)cin >> i;
    for (ll &i : b) cin >> i;
    
    for (ll i = 0; i < n; i++){
        if (a[i] > a[n-1] && b[i] <= a[i]) {
            swap(a[i],b[i]);
        }
    }
    for (ll i = 0; i < n; i++){
        if (b[i] > b[n-1] && b[i] <= a[n-1]) {
            swap(a[i],b[i]);
        }
    }
    ll maxa = a[n-1];
    ll maxb = b[n-1];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if (a[n-1] == maxa && b[n-1] == maxb) cout << "Yes" << endl;
    else cout << "No" << endl;

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