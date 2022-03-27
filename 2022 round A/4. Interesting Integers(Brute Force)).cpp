
void solve() {
   int a, b;
   read(a, b);
   
   int cnt = 0;
   for(int i = a; i <= b; i++) {
       string tmp = to_string(i);
       
       int sum = 0;
       for(char c : tmp) {
           sum += c - '0';
       }
       
       int ans = 1;
       for(char c : tmp) {
           ans = (ans * (c - '0'))% sum; 
       }
       
       if(ans == 0) cnt++;

   }
   
   write(cnt , endl);
}
