/*
Algorithm: Hash, String
Time Complexity: O(T*logN)
Explain:
set 안에 내가 원하는 값이 있는가를 확인하는 방법은

find와 count가 있다
find는 그 위치를 알 수 있고
count는 여부만 알 수 있다

여기서는 count를 썼다
만약 find를 썼다면, vowel.end()인지 여부를 확인했을 것이다

1) vowel 문제는 hashSet을 쓴다
2) 소문자로 만들고 싶으면, tolower을 쓴다
3) set에서 값이 있는지 알고 싶다면 find나 count를 쓴다
*/
#include<bits/stdc++.h>
using namespace std;
#define len(x) (int) (x).size()
#define all(x) x.begin(), (x).end()
#define endl "\n"
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define fi first
#define se second

int main()
{
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  
  set<char> vowel ={'a', 'e', 'i', 'o', 'u'};
  for(int t = 1; t <= T; t++){
    string ret;
    cin >> ret;
    string bs = " is ruled by ";
    char pivot = tolower(ret.back());
    ret += bs;
    if(vowel.count(pivot)) {
        ret += "Alice.";
    } else if(pivot != 'y') {
        ret += "Bob.";
    } else ret += "nobody.";
    
    cout << "Case #" << t << ": " << ret << endl;
  }
}
