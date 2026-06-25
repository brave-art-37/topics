
// My final answer = 0.506343627475


#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


using ll=long long;

//no of iteration or decimal precision required
const long long MAXN=143;
const long long TRIALS=2*1e5+17;

//equilibrium points for the 3 regions
ll eq1(ll c, ll d){return MAXN/2;}
ll eq3(ll c, ll d){return (d*d+MAXN*MAXN)/(2*MAXN);}

//to simulate one game
bool simulate(ll c, ll d){

  //players and equilibrium points
  ll x1 = uid(0,MAXN);
  ll x_final = x1;
  ll y1 = uid(0,MAXN);
  ll y_final = y1;
  ll p=eq1(c,d), r=eq3(c,d);

  if(x1 < c) x_final = uid(0,MAXN);

  // Spears decision uses x1, y1
  // Region 1: x1 < c
  if (x1 < c) {
      if (y1 < p) y_final = uid(0,MAXN);
      else y_final = y1;
  }
  // Region 3: x1 > d
  else if (x1 > d) {
      if (y1 < r) y_final = uid(0,MAXN);
      else y_final = y1;
  }
  // Region 2: c <= x1 <= d  (always reroll)
  else {
      y_final = uid(0,MAXN);
  }

  return (y_final >= x_final);

}

void solve(){
  ll E=20;

  ll c=MAXN/2-E;

  //to get min val over all c
  long double mini_c=LLONG_MAX;
  ll val_c=c; // actual_d=0;

  while(c<MAXN/2+E){
    ll d=c;

    //to get max val over all d
    long double maxi_d=0;
    //ll val_d=d;
    ll count=0;

    vector<long double> vals;
    while(d<c+2*E){

      count++;

      long double wins=0;
      //simulate many games
      for(int i=0;i<TRIALS;i++){
        wins+=simulate(c,d);
      }
      wins/=TRIALS;

      //if no of wins greater than found till now
      //if(wins>maxi_d) maxi_d=wins,val_d=d;
      vals.push_back(wins);
      d++;
    }
    sort(vals.begin(),vals.end(),greater<long double>());
    maxi_d=(vals[0]+vals[1]+vals[2])/3;

    //if max over d is smaller than found till now
    if(maxi_d<mini_c) mini_c=maxi_d, val_c=c; // actual_d=val_d;

    c++;
  }
  cout<<setprecision(10)<<"c="<<c<<" min_c="<<mini_c<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

