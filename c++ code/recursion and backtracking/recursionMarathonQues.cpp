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
    int option2 = adjacentRob(nums, 1, size - 1);
    int ans = max(option1, option2);
    return ans;
}

int dearangement(int n)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    // recursive call
    int ans = (n - 1) * (dearangement(n - 1) + dearangement(n - 2));
    return ans;
}

const int MOD = 1e9 + 7;

int paintingFence(int n, int k)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return k;
    if (n == 2)
        return (k + 1LL * k * (k - 1)) % MOD;

    // Recursive step
    int ans = (1LL * paintingFence(n - 2, k)  +(paintingFence(n - 1, k)  ) * (k - 1)) % MOD;
    return ans;
}

int solveEditTheDistance(string &w1, string &w2, int i, int j)
{
    // base casse
    if (i >= w1.length())
    {
        // word1 khtm ho gya but word2 bcha h abhi
        return w2.length() - j;
    }
    if (j >= w2.length())
    {
        // word2 khtm ho gya
        return w1.length() - i;
    }
    int ans = 0;
    if (w1[i] == w2[j])
    {
        // matches
        ans = 0 + solveEditTheDistance(w1, w2, i + 1, j + 1);
    }
    else
    {
        // not matches
        //  1. insert
        int option1 = 1 + solveEditTheDistance(w1, w2, i, j + 1);
        // 2. remove
        int option2 = 1 + solveEditTheDistance(w1, w2, i + 1, j);
        // 3. replace
        int option3 = 1 + solveEditTheDistance(w1, w2, i + 1, j + 1);
        ans = min(option1, min(option2, option3));
    }
    return ans;
}
int editTheDistance(string &word1, string &word2)
{
    int i = 0;
    int j = 0;
    int ans = solveEditTheDistance(word1, word2, i, j);
    return ans;
}

int solveMS(vector<vector<int>> & m, int i , int j , int & maxi){
    //base case
    if(i>=m.size()||j>=m[0].size()){
        return 0;
    }
    //jao teeno directions mei 
    int right=solveMS(m,i,j+1,maxi);
    int diag=solveMS(m,i+1,j+1,maxi);
    int down =solveMS(m,i+1,j,maxi);
    //krna kb h 
    if(m[i][j]==0){
        return 0;
    }
    else{
        int ans=1+min(right,min(diag,down));
        maxi=max(maxi,ans);
        return ans;
    }
}
int maximalSquare(vector<vector<int>> &matrix){
    int i =0;
    int j=0;
    int maxSquareSide=INT_MIN;
    solveMS(matrix, i , j,maxSquareSide);
    return maxSquareSide*maxSquareSide;
}

void merge(vector<int> &arr, vector<int>& temp,int s , int e){
    int mid=s+(e-s)/2;
    int k=s;
    int i =s, j =mid+1;
    while(i<=mid && j<=e){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else if(arr[j]<arr[i]){
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=e){
        temp[k++]=arr[j++];
    }
    while(s<=e){
        arr[s]=temp[s];
        s++;
    }
}
void solvemerge(vector<int> &arr, vector<int>& temp,int s , int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    solvemerge(arr, temp, s,mid);
    solvemerge(arr, temp,mid+1,e);
    merge(arr, temp, s,e);
}
void mergesort(vector<int> &arr){
    int i=0;
    int e=arr.size()-1;
    vector<int> temp(e+1,0);
    solvemerge(arr,temp, i, e);
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

    // // ques 3- painting fence algorithm : given with n number of poles in an fence that are goinh to colored with k color atmost 2 can be colored same
    // int n , k;
    // cout<<"Enter the number of poles and the number of colors available : "<<endl;
    // cin >>n >>k;
    // cout<<"total number of possible ways of painting the fence is : "<<paintingFence(n,k);

    // // ques 4 - edit the distance : u are given with two string word1 adn word2 return the minimun number of operations rewuired to convert wrod1 to word2
    // string word1 = "horse";
    // string word2 = "ros";
    // cout << "minmun operations to convert = " << editTheDistance(word1, word2);

    // //ques 5 -  maximal square : given an binary matrix of m*n , find the largest square containing 1 and return its area
    // vector<vector<int>>matrix={{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    // cout<<"square of max 1's : "<<maximalSquare(matrix);

    //doubt class 7 notes/code:

    //doubt class 8 notes/code:

    // //-> merge sort with another approach - temp array approach
    // vector<int> arr={0,1,85,4122,7,1,3,0,985,7};
    // mergesort(arr);
    // for (int e:arr){
    //     cout<<e<<" ";
    // }
    // cout<<endl;
     
     

}