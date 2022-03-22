/*
Brute Forces 
O(2^N * N^3)
N = 15 is accepted Range
*/
vector<string> v;
string S;
int N;

//O(2^N)
void makeFullString(string s, int idx) {
    //base case
    if(idx >= N) {
        v.push_back(s);
        return;
    }
    
    //recursion
    if(s[idx] != '?') makeFullString(s, idx+1);
    else {
        s[idx] = '0';
        makeFullString(s, idx+1);
        
        s[idx] = '1';
        makeFullString(s, idx+1);
        
        s[idx] = '?';
    }
    return;
}

bool isPal(string s) {
    int l = 0;
    int r = s.size() - 1;
    bool ret = true;
    while(l < r) {
        if(s[l] != s[r]) ret = false;
        l++; r--;
    }
    return ret;
}


void solve() {
    v.clear();
   read(N, S);
   makeFullString(S, 0);
   
   bool isPossible = false;
   for(string s : v) {
       bool isStringNoPal = true;
       
       for(int idx = 0; idx < N; idx++) {
           if(idx + 4 < N) {
               string cand = s.substr(idx, 5);
               if(isPal(cand)) isStringNoPal = false;         
           }
           if(idx + 5 < N) {
               string cand = s.substr(idx, 6);
               if(isPal(cand)) isStringNoPal = false;  
           }
       }
       if(isStringNoPal) isPossible = true;
   }
   if(isPossible) write("POSSIBLE", endl);
   else write("IMPOSSIBLE", endl);
}
