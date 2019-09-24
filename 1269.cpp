///**Bismillahir Rahmanir Rahim.**
///Amantu Amir, University of Barishal, Bangladesh
///Accepted
#include <bits/stdc++.h>
using namespace std;
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::       sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(cur, v)           cur.assign(v.begin(), v.end())
#define int                   long long int
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
#define small(a, b, c)        min(a, min(b, c))
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

int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

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
//Template end
//-------------------******Alhamdulillah******--------------------//

const int N = 2e5+5;
const int mod = 1e9+7;

void reset(){
 
}

struct node{
    node *child[2];
    node(){
       child[0] = child[1] = NULL;
    }
}*root;

int power[50];
bool check(int a, int b){
    return (bool)(a&(1<<b));
}

void Insert(int n){
    node *cur = root;
    for(int i = 31; i >= 0; i--){
        int idx = check(n, i);
        if(cur->child[idx] == NULL){
            cur->child[idx] = new node();
        }
        cur = cur->child[idx];
    }
}

int query_max(int n){
    node *cur = root; int res = 0;
    for(int i = 31; i >= 0; i--){
        int idx = check(n, i);
        if(cur->child[idx^1]){
            res += power[i];
            cur = cur->child[idx^1];
        }
        else{
            cur = cur->child[idx];
        }
    }
    return res;
}

int query_min(int n){
    node *cur = root; int res = 0;
    for(int i = 31; i >= 0; i--){
        int idx = check(n, i);
        if(cur->child[idx]){
            cur = cur->child[idx];
        }
        else{
            res += power[i];
            cur = cur->child[idx^1];
        }
    }
    return res;
}

void del(node *cur){
    for(int i = 0; i < 2; i++){
        if(cur->child[i]){
            del(cur->child[i]);
        }
    }
    delete(cur);
}
 
int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //fast; 
    power[0] = 1;
    for(int i = 1; i <= 32; i++){
        power[i] = power[i-1]*2;
    }
    int tc = 1, cas = 0; I(tc);
    while(tc--){
        //reset();
        root = new node();
        int n; I(n);
        Insert(0);
        int now = 0;
        int mi = INT_MAX, mx = INT_MIN;
        rep(i, 0, n){
            int a; I(a);
            now ^= a;
            mx = max(mx, query_max(now));
            mi = min(mi, query_min(now));
            Insert(now);
        }
        printf("Case %lld: %lld %lld\n", ++cas, mx, mi);
        del(root);
    }
    return 0;
 
}
 
//--------------------******Alhamdulillah******-------------------//
