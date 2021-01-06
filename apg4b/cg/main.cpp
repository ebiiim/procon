#include <bits/stdc++.h>
using namespace std;

int main()
{

    const string YES = "YES";
    const string NO = "NO";

    vector<int> data(5);
    for (int i = 0; i < 5; i++)
    {
        cin >> data.at(i);
    }

    for (int i = 1; i < data.size(); i++)
    {
        if (data[i - 1] == data[i])
        {
            cout << YES << endl;
            return 0;
        }
    }
    cout << NO << endl;
}
