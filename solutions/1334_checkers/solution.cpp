/*
 * Decription of this problem is bad, in my opinion.
 * Just check if some one can jump over the other after each move.
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::pair;

const int BOARD_SIZE = 8;

const int direction[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

bool validate(int x, int y)
{
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

void solve()
{
    int step = 0;
    string position;
    vector<vector<int>> board(8, vector<int>(8, -1));// -1 stands for empty
    for (int i = 0; i < 32; ++i)
    {
        string position;
        cin >> position;
        int x = position[0] - 'a';
        int y = position[1] - '1';
        int current = step & 1;
        board[x][y] = current;
        int opponent = !current;
        for (int k = 0; k < 4; ++k)
        {
            int x1 = x + direction[k][0];
            int y1 = y + direction[k][1];
            int x2 = x - direction[k][0];
            int y2 = y - direction[k][1];
            int x3 = x + 2 * direction[k][0];
            int y3 = y + 2 * direction[k][1];
            if (validate(x1, y1) && board[x1][y1] == opponent)
            {
                if (validate(x2, y2) && board[x2][y2] == -1 || validate(x3, y3) && board[x3][y3] == -1)
                {
                    cout << step + 1 << "\n";
                    return;
                }
            }
        }
        ++step;
    }
    cout << "Draw\n";
}

int main()
{
    solve();
    return 0;
}
