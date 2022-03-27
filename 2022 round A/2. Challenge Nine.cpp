void solve() {
   string n;
   cin >> n;
   int len = n.size();
   
   int sum = 0;
   for(char c : n) sum += c - '0';
   
   int tmp = sum % 9;
   if(!tmp) {
       if(n.size() == 1) n += "0";
       else n.insert(1, "0");
   }
   else {
       tmp = 9 - tmp;
       int idx = 0;
       for(idx = 0; idx < len; idx++) {
           if(int(n[idx] - '0') > tmp) {
               break;
           }
       }
       n.insert(idx, to_string(tmp));
   }
   write(n, endl);
}
