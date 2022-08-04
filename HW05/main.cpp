#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s){
  stack <char> st;
  int length = s.length();
  char ch;

  for(int i = 0; i < length; i++){
    ch = s[i];
    if(ch == '('  || ch == '[' || ch == '{'){
      st.push(ch);
    }
    else if(ch == ')'){
      if(st.empty()){
        st.push(ch);
      }
      else if (st.top() == '('){
        st.pop();
      }
      else {
        st.push(ch);
      }
    }
    else if(ch == '}'){
      if(st.empty()){
        st.push(ch);
      }
      else if(st.top() == '{'){
        st.pop();
      }
      else{
        st.push(ch);
      }
    }
    else if(ch == ']'){
      if(st.empty()){
        st.push(ch);
      }
      else if(st.top() == '['){
        st.pop();
      }
      else {
        st.push(ch);
      }
    }
  }
  if(st.empty()) {
    return true;
  }
  else {
    return false;
  }
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