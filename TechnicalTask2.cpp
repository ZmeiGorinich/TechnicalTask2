#include <vector>
#include <iostream>

using namespace std;

bool getElementMatrix()
{
	while (true)
	{
		std::cout << "Enter a bool value: ";

		bool a;

		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');

			return a;
		}
	}
}

int getSizeMatrix()
{
	while (true)
	{
		std::cout << "Enter a int value between 2 and 50: ";
		int a;
		std::cin >> a;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			if (a > 50 || a < 2)
			{
				cout << "Vvedite korrektnyi razmer";
			}
			else {
				std::cin.ignore(32767, '\n');

				return a;
			}
		}
	}
}


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

	int size = matrix.size() - 1;

	if (matrix[0][0] == 0 || matrix[size][size] == 0)
	{
		return false;
	}

	vector<vector<int>> possibleWays;

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

			if (isSolved || notVisited && checkPath(current, matrix))
			{
				return true;
			}
		}
	}
	return false;
}

bool func(vector<vector<int>>& matrix) {
	vector < int > start{ 0,0 };
	return checkPath(start, matrix);
}


int main(int argc, char* argv[])
{
	int n;

	n = getSizeMatrix();

	vector<vector<int> > matrix(n);

	cout << "Enter  matrix\n";

	for (int i = 0; i < n; ++i)
	{
		matrix[i].resize(n);
		for (int j = 0; j < n; ++j)
			matrix[i][j] = getElementMatrix();
	}

	cout << func(matrix);

}