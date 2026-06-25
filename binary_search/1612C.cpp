#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int, int>
#define ull unsigned long long
#define ld __float128
#define sz(a) ((int)(a).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppd pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define fwd(i, a, b) for (int i = a; i < b; i++)
#define double long double
#define take(n) \
    int n = 0;  \
    cin >> n
#define take2(n, m)   \
    int n = 0, m = 0; \
    cin >> n >> m
#define take3(x, y, z)       \
    int x = 0, y = 0, z = 0; \
    cin >> x >> y >> z
#define sortt(v) sort(v.begin(), v.end());
#define itarr(n) \
    int arr[n];  \
    fwd(i, 0, n) { cin >> arr[i]; }
#define itarrx(x, m) \
    int x[m];        \
    fwd(i, 0, m) { cin >> x[i]; }
#define vec(v, n) \
    vi v(n, 0);   \
    fwd(i, 0, n) { cin >> v[i]; };
#define set_tox(arr, n, x) \
    fwd(i, 0, n) { arr[i] = x; }
#define take_graph(n, m)             \
    vector<vector<int> > g(n, vi()); \
    int a, b;                        \
    fwd(i, 0, m)                     \
    {                                \
        cin >> a >> b;               \
        a--;                         \
        b--;                         \
        g[a].pb(b);                  \
        g[b].pb(a);                  \
    }
#define take_graph_dir(n, m)         \
    vector<vector<int> > g(n, vi()); \
    int a, b;                        \
    fwd(i, 0, m)                     \
    {                                \
        cin >> a >> b;               \
        a--;                         \
        b--;                         \
        g[a].pb(b);                  \
    }
#define endl "\n"
/* #define what_is(x) cout << #x << " is " << x << endl;
#define check(arr, n)                       \
    fwd(i, 0, n) { cout << arr[i] << ' '; } \
    cout << endl;
const int INF = 1e18;
int tt; */
const int MOD = 998244353;
#define mp(a, b) make_pair(a, b)
#define MAXN 400005

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

// void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

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
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
/*-----------------CODE-----------------------------*/
void solve()
{
    int k,x;cin>>k>>x;
    if(x>=k*k) cout<<2*k-1<<endl;
    else if(x>=k*(k+1)/2){
        x-=k*(k+1)/2;
        int lo=0,hi=k;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if((mid*k-mid*(mid+1)/2)>=x) hi=mid;
            else lo=mid+1;
        }
        cout<<hi+k<<endl;
    }
    else{
        int lo=1,hi=k+1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mid*(mid+1)/2>=x) hi=mid;
            else lo=mid+1;
        }
        cout<<hi<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

