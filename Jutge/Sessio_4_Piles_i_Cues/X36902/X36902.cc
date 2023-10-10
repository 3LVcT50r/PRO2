#include <iostream>
#include <stack>
using namespace std;

int main() {

  char sec;
  stack<char> p;
  bool cond = true;

  cin >> sec;

  if (sec == '.') cond = false;

  while (sec != '.' and cond) {
    if (sec == '(' or sec == '[') p.push(sec);
    else {
      if (!p.empty()) {
        if ((p.top() == '(' and sec == ')') or (p.top() == '[' and sec == ']')) {
          p.pop();
        } else cond = false;
      } else cond = false;
    }
    
    cin >> sec;
  }

  if (cond and p.empty()) cout << "Correcte" << endl;
  else cout << "Incorrecte" << endl;
}