///**Bismillahir Rahmanir Rahim.**

#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(tmp, v)           tmp.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i <= r; i++)
#define rep2(i, l, r)         for (int i = l; i >= r; i--)
#define sf(n)                 scanf("%d", &n)
#define sff(n, m)             scanf("%d %d",&n,&m)
#define sfl(n)                scanf("%lld", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfff(n, m, o)         scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define sp                    printf(" ")
#define nl                    printf("\n")
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld", n)
#define pb                    push_back
#define mid(b, e)             (b+e)/2
#define left(node)            node*2
#define right(node)           node*2+1
#define pii                   pair<int,int>
#define mp                    make_pair
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

struct trie{
  trie *child[5];
  int endmark;
  trie(){
    endmark = 0;
    rep(i, 0, 3){
      child[i] = NULL;
    }
  }
}*root;

int index(char ch){
  if(ch == 'A') return 0;
  else if(ch == 'C') return 1;
  else if(ch == 'G') return 2;
  else return 3;
}

void Insert(string s){
  trie *cur = root; int len = s.size()-1;
  rep(i, 0, len){
    int idx = index(s[i]);
    if(cur->child[idx] == NULL){
      cur->child[idx] = new trie();
    }
    cur = cur->child[idx];
    cur->endmark++;
  }
}

ll ans;
void dfs(trie *cur, int depth){
  ll x = (cur->endmark)*depth;
  ans = max(ans, x);
  rep(i, 0, 3){
    if(cur->child[i] != NULL){
      dfs(cur->child[i], depth+1);
    }
  }
}


void del(trie *cur){
  rep(i, 0, 3){
    if(cur->child[i] != NULL){
      del(cur->child[i]);
    }
  }
  delete(cur);
}


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0; cin >> tc;
    while(tc--){
     root = new trie(); ans = 0;
     int n; cin >> n; string s;
     rep(i, 1, n){
      cin >> s; Insert(s);
     }
     dfs(root, 0);
     printf("Case %d: %lld\n", ++cas, ans);
     del(root);
    }
    return 0;

}

//-----------------------------------***********************----------------------------------------------//
