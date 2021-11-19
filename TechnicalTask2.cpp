#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> getValidSib(vector<int>& start, vector<vector<int>>& matrix) {

    vector<vector<int> > possibleWays;

    if (start[0] - 1 < matrix.size() || start[0] - 1 > 0)
    {
        if (matrix[start[0] - 1][start[1]] > 0)
        {
            possibleWays.push_back({ start[0] - 1 ,start[1] });
        }

    }

   if (start[0] + 1 < matrix.size() && start[1] + 1 > 0)
    {

        if (matrix[start[0] + 1][start[1]] > 0)
        {
            possibleWays.push_back({ start[0] + 1 ,start[1] });
        }

    }    

   if (start[1] - 1 < matrix.size() || start[1] - 1 > 0)
    {
        if (matrix[start[0]][start[1] - 1] > 0)
        {
            possibleWays.push_back({ start[0], start[1] - 1 });
        }

    }

   if (start[1] + 1 < matrix.size() && start[1] + 1 > 0)
   {
       if (matrix[start[0]][start[1] + 1] > 0)
       {
           possibleWays.push_back({ start[0], start[1] + 1 });
       }

   }

    return possibleWays;
}


bool checkPath(vector<int>& start, vector<vector<int>>& matrix) {

     vector<vector<int>> possibleWays;
    
     int size = matrix.size()-1;

     vector < int > current;

     vector < int > finish{ size,size };

    matrix[start[0]][start[1]] = 2;

    possibleWays = getValidSib(start, matrix);


    if (possibleWays.size() > 0)
    {
        for (int i = 0; i < possibleWays.size(); i++)
        {
            current = possibleWays[i];

            bool isSolved = current[0] == finish[0] && (current[1] == finish[1]);

            bool notVisited = matrix[current[0]][current[1]] != 2;

            if (isSolved || notVisited&& checkPath(current,matrix))
            {  
                return true;
            }
        }
    }
    return false;
}

bool func(vector<vector<int>>&matrix) {   
    vector < int > start{0,0};    
    return checkPath(start,matrix);
}


int main(int argc, char* argv[])
{
    int n;

    cout << "Vvedite razmer matrici\n";

    cin >> n;   

    vector<vector<int> > matrix(n);
    
    cout << "Vvedite  matricy\n";

    for (int i = 0; i < n; ++i)
    {
        matrix[i].resize(n);
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    }
    
    cout<<func(matrix);

    
    return 0;
}