#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*-----------------DEBUG----------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T>
void _print(vector<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T>
void _print(set<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T>
void _print(multiset<T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V>
void _print(map<T, V> v)
{cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}
/*------------------CODE-----------------------------*/

void solve(){
  int n,k;cin>>n>>k;
  if(k>n || k<__builtin_popcount(n)){cout<<"NO\n";return;}
  int x=k-__builtin_popcount(n);
  vector<int> p(32,0);
  for(int i=0;i<32;i++){
    p[i]=((n>>i)&1);
  }
  int j=31;
  while(x>0 && j>0){
    while(p[j]==0) j--;
    if(x>=p[j]){p[j-1]+=2*p[j];x-=p[j];p[j]=0;}
    else{p[j]-=x;p[j-1]+=2*x;x=0;}
    j--;
  }
  //debug(p);
  cout<<"YES\n";
  for(int i=0;i<32;i++){
    while(p[i]--){
      cout<<(1<<i)<<' ';
    }
  }
  cout<<"\n";
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--){solve();}
}

