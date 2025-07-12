#include <iostream>
#include <vector>
using namespace std;
int printA()
{
    cout << "Hello World" << endl;
    return 1;
}
void reverseArray(int arr[], int size)
{

    // method 1 -using new array
    // int newArr[size];
    // for(int i=0;i<size;i++){
    //     newArr[i]=arr[size-i-1];
    //     cout << newArr[i] << " ";
    // }

    // method 2 -using swap function in while loop
    // int left=0;
    // int right=size-1;
    // while(left<right){
    //     swap(arr[left],arr[right]);
    //     left++;
    //     right--;
    // }

    // method 3 -using for loop
    // for (int left = 0, right = size - 1; left < right; left++, right--)
    // {
    //     swap(arr[left], arr[right]);
    // }

    // cout << "Reversed array: ";
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}
void printArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void extremePrintarray(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        if (left == right)
        {
            cout << arr[left] << " ";
            break;
        }
        else
        {
            cout << arr[left] << " ";
            cout << arr[right] << " ";
            left++;
            right--;
        }
    }
}

void print2DArray(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void transpose(int arr[][3], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void sortZeroOneArray(int arr[],int c){
    
    // method 1 
    // int left=0;
    // int right=c-1;
    // while(left<right){
    //     if(arr[left]==0){
    //         left++;
    //     }
    //     else if(arr[right]==1){
    //         right--;
    //     }
    //     else{
    //         swap(arr[left],arr[right]);
    //         left++;
    //         right--;
    //     }
    // }

    // method 2
    int j=0;
    for(int i =0;i<c;i++){
        if(arr[i]==0 ){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    printArray(arr,c);
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        // cout<<v[i]<<" ";
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}
int main()
{

    // int num;
    // cout << "Enter a number: ";
    // cin >> num;
    // Pattern 1-inverted side pyramid by number
    // for(int i=0; i<num;i++){
    //     for(int k=1;k<=num-i;k++){
    //             cout<<k;
    //     }
    //     cout<<endl;
    // }

    // Pattern 2- full pyramid
    // for (int i = 0; i < num; i++)
    // {
    //     for (int k = 1; k < num - i; k++)
    //     {
    //         cout <<" ";
    //     }

    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // Pattern 3- inverted full pyramid
    // for (int i = 0; i < num; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = 0; k < num - i; k++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // Pattern 4- diamond pattern
    // int n = num / 2;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int k = 1; k < n - i; k++)
    //     {
    //         cout << " ";
    //     }

    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = 0; k < n - i; k++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // Pattern 5- hollow pyramid
    // for(int i =0;i<num;i++){
    //     for(int j=0;j<num-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int k =0;k<i+1;k++){
    //         if(k==0||k==i){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // patter-6 inverted hollow pyramid
    // for(int i=0;i<num;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<num-i;k++){
    //         if ((k==0)||(k==num-i-1))
    //         {
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }

    //     }
    //     cout<<endl;
    // }

    // pattrn 6 -hollow pyramid
    // int n=num/2;
    //   for(int i =0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(int k =0;k<i+1;k++){
    //         if(k==0||k==i){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<n-i;k++){
    //         if ((k==0)||(k==n-i-1))
    //         {
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }

    //     }
    //     cout<<endl;
    // }

    // pattern 7- pyramid in square
    // int n=num/2;
    // for (int r=0;r<n;r++){
    //     for(int c=0;c<n-r;c++){
    //         cout<<"* ";
    //     }
    //     for(int c=0;c<(2*r+1);c++){
    //         cout<<"  ";
    //     }
    //     for(int c=0;c<n-r;c++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for (int r=0;r<n;r++){
    //     for(int c=0;c<r+1;c++){
    //         cout<<"* ";
    //     }
    //     for(int c=0;c<((2*(n-r))-1);c++){
    //         cout<<"  ";
    //     }
    //     for(int c=0;c<r+1;c++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // hollow inverted pyramid
    // for(int i=0;i<num;i++){
    //     for(int j=0;j<num-i;j++){
    //         if(i==0||i==num-1||j==0||j==num-i-1){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // pattern -alpha bet
    // for(int r=0;r<num;r++){
    //     char ch;
    //     for (int c = 0; c < r+1; c++)
    //     {
    //         ch='A'+c;
    //         cout<<ch;
    //     }
    //     for( ch=ch-1;ch >='A';ch--){
    //         cout<<ch;
    //     }
    //     cout<<endl;

    // }
    //  int a=10;
    //  cout<<(++a)*(a++)<<endl;
    //     cout<<a<<endl;

    //     double a=3.1421321431;
    //     int c=a;
    //     int d=(int)a;
    //     cout << "Original double: " << a << endl;
    //     cout << "Implicit conversion to int: " << c << endl;
    //     cout << "Explicit conversion to int: " << d << endl;

    // int  a= printA();
    // char  b= printA();
    // // cout<<a<<endl;
    // cout<<b<<endl;

    // doubling the array elements after them input
    //     int arr[10];
    //     int n=sizeof(arr)/sizeof(arr[0]);
    //     int ans=0;
    //     for (int i=0;i<n;i++){
    //         cout <<"enter element "<<i+1<<": ";
    //         cin >> arr[i];
    //         ans+=arr[i];
    //     }
    //    cout << "Sum of array elements: " << ans << endl;

    // linear search
    // int arr[5];
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "enter element " << i + 1 << ": ";
    //     cin >> arr[i];
    // }
    // int find;
    // cout<<"enter elemets to find"<<endl;
    // cin>>find;
    // for(int i = 0; i < n; i++)
    // {
    //     if (arr[i] == find)
    //     {
    //         cout << "Element found at index: " << i << endl;
    //         break;
    //     }
    //     if (i == n - 1)
    //     {
    //         cout << "Element not found" << endl;
    //     }
    // }

    // minimum and maximum in array
    // int arr[10];
    // int n = sizeof(arr) / sizeof(arr[0]);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "enter element of index " << i  << ": ";
    //     cin >> arr[i];
    // }
    // int min=arr[0];
    // int max=arr[0];
    // for(int i=0;i<n;i++){
    //     if(arr[i]<min){
    //         min=arr[i];
    //     }
    //     if(arr[i]>max){
    //         max=arr[i];
    //     }
    // }
    // cout << "Minimum element in the array: " << min << endl;
    // cout << "Maximum element in the array: " << max << endl;

    // // function to reverse an array
    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // // reverseArray(arr, size);
    // extremePrintarray(arr, size);

    //  to print all triplets of an array
    // int narr[]={1,2,3};
    // for(int i=0;i<3;i++){
    //     for(int j =0;j<3;j++){
    //         for(int k=0;k<3;k++){

    //                 cout<<"("<<narr[i]<<","<<narr[j]<<","<<narr[k]<<")"<<endl;

    //         }
    //     }
    // }

    // enterign element in 2D array
    // int arr[3][3];
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << "Enter element at position [" << i << "][" << j << "]: ";
    //         cin >> arr[i][j];
    //     }
    // }
    // cout << "The 2D array is:" << endl;
    // print2DArray(arr, 3, 3);
    // cout << "Transpose of that array is " << endl;
    // transpose(arr, 3, 3);

    // sorting this [0,0,1,1,0,1,0,1]
    int arr[]={0,0,0,0,1,1,0,1,0,1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortZeroOneArray(arr,n);

    // vector<int> v(5);
    // v.push_back(10);
    // printVector(v);
    // vector<int> arr(6,1);
    // printVector(arr);
     
    return 0;
}