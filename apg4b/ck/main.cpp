#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main()
{
    string line;
    getline(cin, line);

    int x = 1;
    rep(i, line.size())
    {
        switch (line[i])
        {
        case '+':
            x++;
            break;
        case '-':
            x--;
            break;
        default:
            break;
        }
    }
    cout << x << endl;
}
