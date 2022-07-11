/*
Algorithm: DP, Lower_bound
Time_Complexity: O(MNlogM)
Explaination:

방법은 알았다 
하지만, 구현이 힘들었다

교훈:
1. i,j로 그냥 인덱스 쓰는 게 좋다
2. bottom-top dp의 경우, if(K[j] != S[i]) {dp[i][j] = 1e15; continue;} 조건에 맞지 않으면 버리는 걸 유의하자
3. 이차원 배열을 만들고 싶으면  vector<vector<ll>> dp(N, vector<ll>(M, 1e15));  이렇게 쉽게 만들자
4. 정렬된 배열에서 나보다 작거나 같은 값을 찾고 싶으면, 
      auto it = mm[S[i-1]].upper_bound(j);
      if(it != mm[S[i-1]].end()) {
        int jr = *it;
        dp[i][j] = min(dp[i][j], dp[i-1][jr] + abs(j - jr));
      }
      if(it != mm[S[i-1]].begin()) {
        it--;
        int jl = *it;
        dp[i][j] = min(dp[i][j], dp[i-1][jl] + abs(j - jl));
      }
이런 식으로, it--해서 찾자. 단, 처음이 아닌지 꼭 확인하자 
5. Hash를 이렇게 하면 좋다
  //Hashing
  map<int, set<int> > mm;

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define vt vector
#define pb push_back
#define pi pair<int, int> >;
#define pl pair<ll, ll> >;
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb)/2;
		f(mb)?rb=mb:lb=mb+1; 
	} 
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while(lb<rb) {
		ll mb=(lb+rb+1)/2;
		f(mb)?lb=mb:rb=mb-1; 
	} 
	return lb;
}


/*read*/
template<class A> void read(vt<A>& v);
template<class A, size_t S> void read(ar<A, S>& a);
template<class T> void read(T& x) {
	cin >> x;
}
void read(double& d) {
	string t;
	read(t);
	d=stod(t);
}
void read(long double& d) {
	string t;
	read(t);
	d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x) {
	EACH(a, x)
		read(a);
}


/*to_string*/
string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b?"true":"false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
		res+=char('0'+v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
		res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    EACH(x, v) {
		if(!f)
			res+=' ';
		f=0;
		res+=to_string(x);
	}
    return res;
}

/*write*/
template<class A> void write(A x) {
	cout << to_string(x);
}
template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}
void print() {
	write("\n");
}
template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}






void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

template<class T> void offset(ll o, T& x) {
	x+=o;
}
template<class T> void offset(ll o, vt<T>& x) {
	EACH(a, x)
		offset(o, a);
}
template<class T, size_t S> void offset(ll o, ar<T, S>& x) {
	EACH(a, x)
		offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
	return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template<class T, class U> void vti(vt<T> &v, U x, size_t n) {
	v=vt<T>(n, x);
}
template<class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
	v=vt<T>(n);
	EACH(a, v)
		vti(a, x, m);
}

const int d4[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
const int d8[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
  int N; cin >> N;
  vector<int> S(N);
  for(int &x : S) cin >> x;
  
  int M; cin >> M;
  vector<int> K(M);
  for(int &x : K) cin >> x;

  //2D array
  vector<vector<ll>> dp(N, vector<ll>(M, 1e15)); 
  //Hashing
  map<int, set<int> > mm;
  for(int i = 0; i < M; i++) {
    mm[K[i]].insert(i);
  }
  //init
  for(int i = 0; i < M; i++) {
    if(K[i] == S[0]) dp[0][i] = 0;
  }
  
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < M; j++){
      if(K[j] != S[i]) {dp[i][j] = 1e15; continue;}

      auto it = mm[S[i-1]].upper_bound(j);
      if(it != mm[S[i-1]].end()) {
        int jr = *it;
        dp[i][j] = min(dp[i][j], dp[i-1][jr] + abs(j - jr));
      }
      if(it != mm[S[i-1]].begin()) {
        it--;
        int jl = *it;
        dp[i][j] = min(dp[i][j], dp[i-1][jl] + abs(j - jl));
      }
    }
  }

  print(*min_element(all(dp[N-1])));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	read(t);
	FOR(t) {
		write("Case #", i+1, ": ");
		solve();
	}
}
