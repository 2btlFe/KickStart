void solve() {
   string I, P;
   read(I, P);
   
   int pI, pP;
   pI = pP = 0;
   
   int flag = 1;
   while(pI < I.size()) {
       if(pP >= P.size()) {
           flag = 0;
           break;
       }
       
       if(I[pI] == P[pP]) {
           pI++;
           pP++;
       }
       else {
           pP++;
       }
   }
   
    if(!flag) write("IMPOSSIBLE", endl);
    else {
       write(P.size() - I.size(), endl); 
    }
}
