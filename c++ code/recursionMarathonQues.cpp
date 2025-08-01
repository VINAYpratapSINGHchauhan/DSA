#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int adjacentRob(vector<int> &houses, int s, int e)
{
    if (s > e)
    {
        return 0;
    }
    // recurisve call
    int option1 = houses[s] + adjacentRob(houses, s + 2, e);
    int option2 = 0 + adjacentRob(houses, s + 1, e);
    int ans = max(option1, option2);
    return ans;
}
int robTheHouse(vector<int> &nums)
{
    int size = nums.size();
    if (size == 1)
    {
        nums[0];
    }
    int index = 0;
    int option1 = nums[index] + adjacentRob(nums, 0, size - 2);
    int option2 = 0 + adjacentRob(nums, 1, size - 1);
    int ans = max(option1, option2);
    return ans;
}
int main()
{
    // recursion marathon questions

    // ques 1 - house robber 2 :u are given a nums array returns the max of non adjacent money u can ron but this time houses ar ein circle means 1st is the adjacent of last
    vector<int> nums = {1, 2, 4, 5, 6, 3};
    cout << "maximum robbery is of amount : " << robTheHouse(nums) << endl;
}