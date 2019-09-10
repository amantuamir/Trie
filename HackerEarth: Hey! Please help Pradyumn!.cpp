///**Bismillahir Rahmanir Rahim.**
///Amantu Amir, University of Barishal, Bangladesh
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
const int N = 3e4+5;
const int mod = 1e9+7;

string toString(int n){
    stringstream ss; ss << n;
    string s; ss >> s;
    return s;
}

int toInt(string s){
    stringstream ss; ss << s;
    int n; ss >> n;
    return n;
}
 
void reset(){
 
}

int id; string dic[N];
struct node{
    node *child[26+1];
    int endmark;
    node(){
        endmark = -1;
        rep(i, 0, 26){
            child[i] = NULL;
        }
    }
}*root;

void Insert(string s){
    node *cur = root; int l = s.size();
    transform(all(s), s.begin(), ::tolower);
    rep(i, 0, l){
        //s[i] = tolower(s[i]);
        int idx = s[i] - 'a';
        if(cur->child[idx] == NULL){
            cur->child[idx] = new node();
        }
        cur = cur->child[idx];
    }
    dic[id] = s;
    cur->endmark = id++;
}

void dfs(node *cur){
    if(cur->endmark > -1){
        P(dic[cur->endmark]); nl;
    }
    rep(i, 0, 26){
        if(cur->child[i] != NULL){
            dfs(cur->child[i]);
        }
    }
}

void search(string s){
    node *cur = root; int l = s.size();
    rep(i, 0, l){
        int idx = s[i] - 'a';
        if(cur->child[idx] == NULL){
            Insert(s);
            P("No suggestions"); nl; return;
        }
        cur = cur->child[idx];
    }
    dfs(cur);
}


 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int tc = 1, cas = 0;
    while(tc--){
        reset();
        root = new node();
        int n; I(n);
        rep(i, 0, n){
           string s; I(s); Insert(s);
        }
        int q; I(q);
        while(q--){
            string s; I(s); search(s);
        }
    }
    return 0;
 
}
 
//-----------------------------------***********************----------------------------------------------//
