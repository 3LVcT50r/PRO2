#include <iostream>
#include <stack>
using namespace std;

int main() {
  int num;
  cin >> num;

  stack<int> p;

  int pil;

  for (int i = num/2; i > 0; --i) {
    cin >> pil;
    p.push(pil);
  }

  if (num%2 != 0) cin >> pil;

  bool cond = true;
  int i = num/2;
  while (i > 0 and cond) {
    cin >> pil;
    if (p.top() == pil) p.pop();
    else {
      cond = false;
      p.pop();
    }
    --i;
  }
  if (cond) cout << "SI" << endl;
  else cout << "NO" << endl; 
}