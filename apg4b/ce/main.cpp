#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }

    vector<vector<char>> score(N, vector<char>(N, '-'));
    for (int i = 0; i < M; i++)
    {
        int winner = A.at(i) - 1;
        int loser = B.at(i) - 1;
        score.at(winner).at(loser) = 'o';
        score.at(loser).at(winner) = 'x';
    }

    for (vector<char> vc : score)
    {
        for (int i = 0; i < vc.size(); i++)
        {
            cout << vc.at(i);
            if (i == vc.size() - 1)
                cout << endl;
            else
                cout << ' ';
        }
    }
}
