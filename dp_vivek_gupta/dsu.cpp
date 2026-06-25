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

class DSU{
  public:
    int sz;
    vector<int> rep;
    vector<int> val;
    vector<int> rank;
    vector<int> maxi;
    int no;
    DSU(int sz):sz(sz),rep(sz,-1),val(sz,-1),rank(sz,-1),maxi(sz,-1),no(0){};

    void make_set(int n, int key){
      if(n>=sz) return;
      rep[n]=n;
      val[n]=key;
      rank[n]=0;
      maxi[n]=key;
      no++;
    }

    int find_rep(int ind){
      if(rep[ind]==-1) return -1;
      while(rep[ind]!=ind) ind=rep[ind];
      return ind;
    }

    void join(int ind1,int ind2){
      int x=find_rep[ind1];
      int y=find_rep[ind2];
      if(x==y || x==-1 || y==-1) return;
      if(rank[x]<rank[y]){
        rep[x]=y;
        (rank[x]==rank[y])?rank[y]++:;
        maxi[y]=max(maxi[y],maxi[x]);
        no--;
      }
      else{
        rep[y]=x;
        (rank[x]==rank[y])?rank[x]++:;
        maxi[x]=max(maxi[y],maxi[x]);
        no--;
      }
    }
};

void solve(){
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--){solve();}
}

