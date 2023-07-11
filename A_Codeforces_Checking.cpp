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
    vector<char> codeforces = {'c','o','d','e','f','o','r','c','e','s'};
    char s; cin >> s;
    if (count(codeforces.begin(),codeforces.end(),s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
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