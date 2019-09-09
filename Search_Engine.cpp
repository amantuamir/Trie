///**Bismillahir Rahmanir Rahim.**
///Accepted
#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(cur, v)           cur.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sfs(s)                scanf("%s", s)
#define sfl(n)                scanf("%lld", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfffl(n, m, o)        scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define debug                 cout << " debug\n"
#define yes                   cout << "YES\n"
#define no                    cout << "NO\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld\n", n)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define P(n)                  cout << n
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout << a << " " << b << " " << c << "\n"
#define R(n)                  return n
#define mid(b, e)             (b+e)/2
#define left(node)            node*2
#define right(node)           node*2+1
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first
#define PI                    3.1415926
 
struct greaters{
    bool operator()(const long& a, const long& b) const{
        return a > b;
    }
};
 
//-----------------------------------***********************----------------------------------------------//
 
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 2e5+5;
const int mod = 1e9+7;
 
void reset(){
 
}

int x;
struct node{
    node *child[26+15];
    int mark;
    node(){
        mark = x;
        rep(i, 0, 26){
            child[i] = NULL;
        }
    }
}*root;

void Insert(string s, int xx){
    node *cur = root; int l = s.size();
    rep(i, 0, l){
        int idx = s[i] - 'a';
        if(cur->child[idx] == NULL){
            cur->child[idx] = new node();
        }
        cur = cur->child[idx];
        cur->mark = max(cur->mark, xx);
        //cout << cur->mark << " " << idx << endl;
    }
}

int ans;
void search(string s){
    node *cur = root; int l = s.size();
    int flag = 0;
    rep(i, 0, l){
        int idx = s[i] - 'a';
        if (cur->child[idx] == NULL){
            flag = 1; break;
        }
        cur = cur->child[idx];
    }
    if(flag) ans = -1;
    else ans = cur->mark;
}
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fast;
    int tc = 1, cas = 0;
    while(tc--){
        reset();
        root = new node();
        int n, q; II(n,q); string s; 
        rep(i, 0, n){
            II(s, x);
            Insert(s, x);
        }
        while(q--){
        I(s); search(s); P(ans);nl;
        }
    }
    return 0;
 
}
 
//-----------------------------------***********************----------------------------------------------//
