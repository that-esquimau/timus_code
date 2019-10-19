/*
 * Problem address: http://acm.timus.ru/problem.aspx?space=1&num=2081
 * Tags: greedy algorithm.
 */

#include <iostream>
#include <string>
#include <iomanip>

using std::cin;
using std::cout;
using std::string;
using std::setw;
using std::setfill;

int n;

string code[3]; // put user input here.
string digits[3][10] = // encoding of the digits
{
    { "._.", "...", "._.", "._.", "...", "._.", "._.", "._.", "._.", "._."},
    { "|.|", "..|", "._|", "._|", "|_|", "|_.", "|_.", "..|", "|_|", "|_|" },
    { "|_|", "..|", "|_.", "._|", "..|", "._|", "|_|", "..|", "|_|", "._|" }
};

bool match_digit(int x, int index)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (code[i][index + j] != '.' && code[i][index + j] != digits[i][x][j])
                return false;
        }
    }
    return true;
}

bool match(int x)
{
    int minute = x / 60;
    int second = x % 60;
    return match_digit(minute / 10, 0) && match_digit(minute % 10, 4) && match_digit(second / 10, 10) && match_digit(second % 10, 14);
}

void output_element(int x)
{
    cout << setw(2) << setfill('0') << x;
}

void solve()
{
    int candidate = 3599; // minute * 60 + second, greedily iterate all legal time values decreasingly to check if it is a correct value for current input.
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < 3; ++k)
        {
            cin >> code[k];
        }
        // Because these is alway a solution, so we just blindly select and output it.
        while (candidate >= 0 && !match(candidate))
        {
            --candidate;
        }
        output_element(candidate / 60);
        cout << ":";
        output_element(candidate % 60);
        cout << "\n";
        --candidate;
    }
}

int main()
{
    solve();
    return 0;
}
