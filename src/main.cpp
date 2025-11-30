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
    for (char c : expr)
    {
        if (isdigit(c) || c == '.')
        {
            num += c;
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
        nums.push_back(num);
    {
    }

    for (string t : nums)
        cout << t << " ";
    cout << endl;

    mult_div(nums);
    add_subs(nums);

    double result = stod(nums[0]);
    result = round(result * 100.0) / 100.0;

    cout << result;
}