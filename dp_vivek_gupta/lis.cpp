#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> nos(n);
  for(int &x:nos){cin>>x;}
  vector<int> par(n,-1);
  vector<int> piles(1,0);
  for(int i=1;i<n;i++){
    auto it=lower_bound(piles.begin(),piles.end(),i,[&](int idx1,int idx2){return nos[idx1]<nos[idx2];});
    int pos=it-piles.begin();
    if(pos!=0) par[i]=piles[pos-1];
    if(pos<piles.size()){
      piles[pos]=i;
    }
    else{
      piles.push_back(i);
    }
  }
  vector<int> ans;
  int idx=piles.back();
  while(idx!=-1){
    ans.push_back(nos[idx]);
    idx=par[idx];
  }
  reverse(ans.begin(),ans.end());
  cout<<ans.size()<<"\n";
  for(int &x:ans){
    cout<<x<<' ';
  }
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t = 1;
    //cin >> t;

    while (t--){solve();}
}


