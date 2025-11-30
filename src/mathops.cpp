#include <iostream>
#include <vector>
using namespace std;

void mult_div(vector<string> &nums)
{
    for (int j = 0; j < nums.size(); j++)
    {
        if ((nums[j] == "*" || nums[j] == "/") && j > 0 && j < nums.size() - 1)
        {
            double new_num;
            if (nums[j] == "*")
                new_num = stod(nums[j - 1]) * stod(nums[j + 1]);
            else
                new_num = stod(nums[j - 1]) / stod(nums[j + 1]);

            nums.erase(nums.begin() + j - 1, nums.begin() + j + 2);
            nums.insert(nums.begin() + j - 1, to_string(new_num));
            j--;
        }
    }
}

void add_subs(vector<string> &nums)
{
    for (int k = 0; k < nums.size(); k++)
    {
        if ((nums[k] == "+" || nums[k] == "-") && k > 0 && k < nums.size() - 1)
        {
            double new_num;
            if (nums[k] == "+")
                new_num = stod(nums[k - 1]) + stod(nums[k + 1]);
            else
                new_num = stod(nums[k - 1]) - stod(nums[k + 1]);

            nums.erase(nums.begin() + k - 1, nums.begin() + k + 2);
            nums.insert(nums.begin() + k - 1, to_string(new_num));
            k--;
        }
    }
}
