#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  vector<long long> v(3);
  cin>>v[0]>>v[1]>>v[2];
  sort(v.begin(),v.end());
  long long x=v[0],y=v[1],z=v[2];
  long long k,ans=0;cin>>k;
  for(long long i=1LL;i<=min(x,k);i++){
    if(k%i!=0) continue;
    long long j=i;
    while(j*j<=k/i){
      if((k/i)%j!=0){j++;continue;}
      long long l=(k/i)/j;
      if(l>z){j++;continue;}
      ans=max(ans,1LL*(x-i+1LL)*(y-j+1LL)*(z-l+1LL));
      j++;
      //cout<<i<<' '<<j<<' '<<l<<"\n";
    }
  }
  cout<<ans<<"\n";
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--){solve();}
}


