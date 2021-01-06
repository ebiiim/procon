#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, price, N;
    string text;
    cin >> p;
    if (p == 2)
    {
        cin >> text;
        cout << text << "!" << endl;
    }
    cin >> price >> N;
    cout << price * N << endl;
}
