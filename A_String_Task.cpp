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
    st s;
    cin >> s;
   vi vow = {'a','e','i','o','u','y'};
   for (char i : s){
    i = tolower(i);
        if (!count(vow.begin(),vow.end(),i)) {
            cout << "." <<i;
        }
   }
   cout << endl;
}

int main()
{   
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // ll tt;
    // cin >> tt;
    // while (tt--) 
        solve(); 
    return 0;
}  