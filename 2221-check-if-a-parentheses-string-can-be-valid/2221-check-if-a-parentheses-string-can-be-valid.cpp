class Solution {
public:
bool canBeValid(string s, string locked) {
                int bal = 0;
 int swappable = 0; // # of ')'s which can be turned into '('
  for (int i=0; i<s.size(); i++) {
     if (locked[i]=='0') {
      // Place ')', unless forced otherwise
      if (bal>0) {
               bal--;
           swappable++;
          } 
          else {
     bal++;
   }
      } else {
  if (s[i]=='(') {
 bal++;
     }
      else {
      if (bal == 0) {
     // Balance is about to be negative
  // Swap a previous ')' into '(' if possible
 if (swappable==0) {
  return false;
      }
   swappable--;
   bal+=2;
    }
 bal--;
}
  }
 }
   return bal==0;
  }
 };
  