#include <vector>
#include <iostream>
#include <mathops.hpp>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    vector<string> nums;
    string expr = argv[2];
    string num = "";
    bool isEquation = false;
    for (char c : expr)
    {
        if (isdigit(c) || c == '.')
        {
            num += c;
        }
        else if (c == '=')
        {
            isEquation = true;
            nums.push_back(string(1, c));
            num = "";
        }
        else
        {
            if (!num.empty())
            {
                nums.push_back(num);
                num = "";
            }
            if (!isspace(c))
            {
                nums.push_back(string(1, c));
            }
        }
    }
    if (!num.empty())
    {
        nums.push_back(num);
    }

    if (isEquation)
    {
        cout << "equation" << endl;
        solve(nums);
        for (string n : nums)
        {
            cout << n;
        }
    }
    else
    {
        mult_div(nums);
        add_subs(nums);
    }

    double result = stod(nums[0]);
    result = round(result * 100.0) / 100.0;
}