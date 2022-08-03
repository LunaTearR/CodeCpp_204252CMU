#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// bool isBalanced(string s) {
//   int c1 = 0;
//   int c2 = 0;
//   int c3 = 0;
//   for(int i = 0; i < s.length(); i++){
//     if(s[i] == '(' ){
//       c1 += 1;
//     }
//     else if(s[i] == '['){
//       c2 += 1;
//     }
//     else if(s[i] == '{'){
//       c3 += 1;
//     }
//     else if(s[i] == ')'){
//       c1 -= 1;
//     }
//     else if(s[i] == ']'){
//       c2 -= 1;
//     }
//     else if(s[i] == '}'){
//       c3 -= 1;
//     }
//   }
//   if(c1 == 0 && c2 == 0 && c3 ==0){
//     return true;
//   }
//   else {
//     return false;
//   }
// }

bool isBalanced(string s) {




  return false;
}

int main() {
  string s;
  cin >> s;
  while (s != "-1") {
    if(isBalanced(s)) {
      cout << "Parentheses are balanced" << endl;
    } else {
      cout << "Parentheses are not balanced" << endl;
    }
    cin >> s;
  }
    
}
