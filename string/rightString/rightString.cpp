#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    cout << s << endl;
    return 0;

}
