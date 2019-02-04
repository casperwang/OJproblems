#include <iostream>
#include <vector>
using namespace std;
struct coordinate {
  int x, y;
};
coordinate A, B, C, tmp;
vector <coordinate> ans;
int main() {
  cin >> A.x >> A.y;
  cin >> B.x >> B.y;
  cin >> C.x >> C.y;
  while (!(A.x >= min(B.x, C.x) && A.x <= max(B.x, C.x))) {
    swap(A, B);
    swap(A, C);
  }
  for (int i = min(A.y, min(B.y, C.y)); i <= max(A.y, max(B.y, C.y)); i++) {
    tmp.x = A.x;
    tmp.y = i;
    ans.push_back(tmp);
  }
  if (B.x < A.x) {
    for (int i = B.x; i < A.x; i++) {
      tmp.x = i;
      tmp.y = B.y;
      ans.push_back(tmp);
    }
  } else {
    for (int i = B.x; i > A.x; i--) {
      tmp.x = i;
      tmp.y = B.y;
      ans.push_back(tmp);
    }
  }
  if (C.x < A.x) {
    for (int i = C.x; i < A.x; i++) {
      tmp.x = i;
      tmp.y = C.y;
      ans.push_back(tmp);
    }
  } else {
    for (int i = C.x; i > A.x; i--) {
      tmp.x = i;
      tmp.y = C.y;
      ans.push_back(tmp);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].x << " " << ans[i].y << endl;
  }
  return 0;
}
