#include <iostream>
#include <vector>
using namespace std;

void printPermutation(string &str, int i)
{

    // if we pass string with reference the swapp ing will be done in the original string and the next case will be run on that swapped strign which cause our function to give error

    // but we had to pass string by refrence otherwise it will too much space in our system

    // therefore , here comes THE CONCEPT OF BACK TRACKING  that we use while going back from the recursive call ki string ko vps phle jaisi kr do taki next case ka b answer shi aaye . SO , vps jate time ek aur var swap kr do taki hm shi answer la paye

    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }
    // solve one case
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        // recursive call
        printPermutation(str, i + 1);
        // BACK TRACKING step
        swap(str[i], str[j]);
    }
}

bool isMovementSafe(int maze[][4], int row, int col, vector<vector<bool>> &visited,  int newX, int newY)
{
    if (maze[newX][newY] == 1 && newX >= 0 && newX < row && newY >= 0 && newY < col && visited[newX][newY] == false)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void printAllPaths(int maze[][4], int row, int col, int srcX, int srcY, int destX, int destY, string & output, vector<vector<bool>> &visited)
{
    // here destination coordinate are [row-1][col-1]

    // base case
    if (srcX == destX && srcY == destY)
    {
        cout << output << endl;
        return;
    }

    // ek case solve kro baki recursion dekh lega
    // sari movements ka ek-ek case solve krna hai

    // we can only make a move if that movement is safe bcz our move can be unsafe if it have these possibilities:
    // -> path is closed  -  i.e next locaiton has 0 on it
    // -> we are not going outside the maze -  i.e out of bound
    // -> visited position should not be visited again -  i.e can cause infinite loop
    // there we made a function to handle our movement and ensure that our movement is safe
    // FUNCTION - isMovementSafe();

    // case 1 : up wala
    int newX = srcX - 1;
    int newY = srcY;

    if (isMovementSafe(maze, row, col, visited, newX, newY))
    {
        // make that location visited
        visited[newX][newY] = true;
        // call recursion
        output.push_back('U');
        printAllPaths(maze, row, col, newX, newY, destX, destY, output, visited);
        // Back Tracking - unmark the location that it will be used by the next route/path
        output.pop_back();
        visited[newX][newY] = false;
    }

    // case 2 : down wala
    newX = srcX + 1;
    newY = srcY;
    if (isMovementSafe(maze, row, col, visited, newX, newY))
    {
        // make that location visited
        visited[newX][newY] = true;
        // call recursion
        output.push_back('D');
        printAllPaths(maze, row, col, newX, newY, destX, destY, output, visited);
        // Back Tracking - unmark the location that it will be used by the next route/path
        output.pop_back();
        visited[newX][newY] = false;
    }

    // case 3 : left wala
    newX = srcX;
    newY = srcY - 1;
    if (isMovementSafe(maze, row, col, visited,  newX, newY))
    {
        // make that location visited
        visited[newX][newY] = true;
        // call recursion
        output.push_back('L');
        printAllPaths(maze, row, col, newX, newY, destX, destY, output, visited);
        // Back Tracking - unmark the location that it will be used by the next route/path
        output.pop_back();
        visited[newX][newY] = false;
    }

    // case 4 : right wala
    newX = srcX;
    newY = srcY + 1;
    if (isMovementSafe(maze, row, col, visited, newX, newY))
    {
        // make that location visited
        visited[newX][newY] = true;
        // call recursion
        output.push_back('R');
        printAllPaths(maze, row, col, newX, newY, destX, destY, output, visited);
        // Back Tracking - unmark the location that it will be used by the next route/path
        output.pop_back();
        visited[newX][newY] = false;
    }
}
int main()
{
    // // question - print all possible permutation of the given string
    // string str = "abc";
    // int i = 0;
    // printPermutation(str, i); //is mei b back tracking use hui h 

    // // back tracking

    // question on back tracking

    // 1- rat in a maze
    int maze[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    int row = 4;
    int col = 4;
    int srcX = 0;        // x - coordinate of the source location
    int srcY = 0;        // y - coordinate of the source location
    string output = "";  // output string where we store the path
    int destX = row - 1; // x-coordinate of the destination
    int destY = col - 1; // y-coordinate of the destination
    // create the visited 2D array
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[srcX][srcY] == 0)
    {
        // source position is closed , means Rat cannot move
        cout << "NO path exists " << endl;
    }
    else
    {
        // mark the location visited
        visited[srcX][srcY] = true;
        printAllPaths(maze, row, col, srcX, srcY, destX, destY, output, visited);
    }
}