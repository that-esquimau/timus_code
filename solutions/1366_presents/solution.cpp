/*
 * Problem address: http://acm.timus.ru/problem.aspx?space=1&num=1366
 * Classic derangement problem:
 * https://en.wikipedia.org/wiki/Derangement
 * https://oeis.org/A000166
 */

#include <iostream>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::setw;
using std::setfill;

const int BASE = 10000;

class big_integer
{
public:
    big_integer(int seed)
    {
        digits.push_back(seed);
    }
    big_integer(big_integer&& integer)
    {
        digits = std::move(integer.digits);
    }
    big_integer()
    {

    }

    void operator=(big_integer&& integer)
    {
        digits = std::move(integer.digits);
    }

    big_integer operator*(int x)
    {
        big_integer product;
        int carry = 0;
        for (int i = 0; carry || i < digits.size(); ++i)
        {
            if (i < digits.size())
            {
                carry += x * digits[i];
            }
            product.digits.push_back(carry % BASE);
            carry /= BASE;
        }
        return product;
    }

    void output()
    {
        auto i = digits.rbegin();
        cout << *i++;
        while (i != digits.rend())
        {
            cout << setw(4) << setfill('0') << *i++;
        }
        cout << "\n";
    }

private:
    vector<int> digits;

    friend big_integer operator+(const big_integer&, const big_integer&);
};

big_integer operator+(const big_integer& a, const big_integer& b)
{
    big_integer sum;
    int carry = 0;
    for (int i = 0; carry || i < a.digits.size() || i < b.digits.size(); ++i)
    {
        if (i < a.digits.size())
        {
            carry += a.digits[i];
        }
        if (i < b.digits.size())
        {
            carry += b.digits[i];
        }
        sum.digits.push_back(carry % BASE);
        carry /= BASE;
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    big_integer a(1);
    big_integer b(0);
    for (int k = 2; k <= n; ++k)
    {
        auto c = (a + b) * (k - 1);
        a = std::move(b);
        b = std::move(c);
    }
    b.output();
}

int main()
{
    solve();
    return 0;
}
