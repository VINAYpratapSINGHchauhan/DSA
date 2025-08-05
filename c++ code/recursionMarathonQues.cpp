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
        return nums[0];
    }
    int index = 0;
    int option1 = adjacentRob(nums, 0, size - 2);
    int option2 =adjacentRob(nums, 1, size - 1);
    int ans = max(option1, option2);
    return ans;
}

int dearangement(int n){
    //base case
    if(n==1)return 0;
    if(n==2)return 1;
    //recursive call
    int ans =(n-1)*(dearangement(n-1)+dearangement(n-2));
    return ans;
}

const int MOD = 1e9 + 7;

int paintingFence(int n, int k) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return k;
    if (n == 2) return (k + 1LL * k * (k - 1)) % MOD;

    // Recursive step
    int ans = (1LL * (paintingFence(n - 1, k) + paintingFence(n - 2, k)) * (k - 1)) % MOD;
    return ans;
}

int main()
{
    // recursion marathon questions

    // // ques 1 - house robber 2 :u are given a nums array returns the max of non adjacent money u can ron but this time houses ar ein circle means 1st is the adjacent of last
    // vector<int> nums = {1, 2, 4, 5, 6, 3};
    // cout << "maximum robbery is of amount : " << robTheHouse(nums) << endl;

    // //ques 2 - count dearrangements (permutation such that no element appears in its original position)
    // int n=6; //that is the number of elemnst in our arrangements
    // cout<<"number of favourable dearangements possible : "<<dearangement(n);

    // ques 3- painting fence algorithm : given with n number of poles in an fence that are goinh to colored with k color atmost 2 can be colored same
    int n , k;
    cout<<"Enter the number of poles and the number of colors available : "<<endl;
    cin >>n >>k;
    cout<<"total number of possible ways of painting the fence is : "<<paintingFence(n,k);
}