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
    vector<st> a(2*n - 2);
    for (st &i : a) cin >> i;
    map<ll,vector<st>> d = {};
    for (ll i = 0; i < a.size(); i++){
        d[a[i].size()] = {};
    }
    for (ll i = 0; i < a.size(); i++){
        d[a[i].size()].push_back(a[i]);
    }
    for (ll i = 1; i < n; i++){
        st f = d[i][1];
        reverse(f.begin(),f.end());
        if (d[i][0] != f) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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