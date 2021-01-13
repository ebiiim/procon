#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, a, b;
    cin >> x >> a >> b;

    // 1
    cout << ++x << endl;

    // 2
    x *= a + b;
    cout << x << endl;

    // 3, 4
    x *= x;
    cout << x << endl
         << --x << endl;
}
