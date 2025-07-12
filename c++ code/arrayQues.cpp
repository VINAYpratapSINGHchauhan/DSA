#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Arrays important Questions through vectors
void printvector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// function to sort the colours like [0,0,2,2,0,2,1,1,1,0,0] ans =[0,...,1....,2...]
void sortcolours(vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int i = 0;
    while (i <= right)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[left]);
            i++;
            left++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[right]);
            right--;
        }
        else
        {
            i++;
        }
    }
    printvector(arr);
}
void shiftbyK(vector<int> &v, int k)
{
    // vector<int> kArray;
    // int lastIndex=v.size()-1;
    // for(int i=lastIndex-k+1;i<=lastIndex;i++){
    //     kArray.push_back(v[i]);
    // }
    // for(int i=lastIndex;i>=k;i--){
    //     v[i]=v[i-k];
    // }
    // for(int i=0;i<k;i++){
    //     v[i]=kArray[i];
    // }
    // printvector(v);

    //  method 2 by modulus operator
    int n = v.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int newI = (i + k) % n;
        ans[newI] = v[i];
    }
    v = ans;
    printvector(v);
}
void findMissing(vector<int> &v)
{
    int n = v.size();
    int Osum = (n * (n + 1)) / 2;
    int Asum = 0;
    for (int i = 0; i < n; i++)
    {
        Asum += v[i];
    }
    cout << "Missing number is : " << (Osum - Asum) << endl;
}
void print2Dvec(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void rotateBy90(vector<vector<int>> &v)
{
    int n = v.size();
    // transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < v[i].size(); j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    // reversing each row of the tranposed vector in order to obtained the required ans
    // reversing method 1- by logic
    // for(int i=0;i<n;i++){
    //     int left=0;
    //     int right=v[i].size()-1;
    //     while(left<right){
    //         swap(v[i][left],v[i][right]);
    //         left++;
    //         right--;
    //     }
    // }
    // revrsing method 2- by reversal method
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }


cout << "Rotated 2D vector is : " << endl;
print2Dvec(v);
}
int main()
{

    // problem 1- sort the colours like [0,0,2,2,0,2,1,1,1,0,0] ans =[0,...,1....,2...]
    // vector<int> arr={2,0,0,2,2,0,2,1,1,1,0,0,2};
    // sortcolours(arr);

    // problem 2 - shifting arar by k elements (k>0)
    // vector<int> arr={10,20,30,40,50,60,70,80,90,100,110,120};
    // int k;
    // cout<<"enter value of k : ";
    // cin>>k;
    // printvector(arr);
    // shiftbyK(arr,k);

    // problem 3 - find the missing number that is from the range of array
    // vector<int> arr={0,1};
    // findMissing(arr);

    // problem 4 - shifting array by 90 degrees
    vector<vector<int>> mat{{1, 2}, {1, 2}, {122, 0}};
    cout << "Original matrix : " << endl;
    print2Dvec(mat);
    rotateBy90(mat);
}