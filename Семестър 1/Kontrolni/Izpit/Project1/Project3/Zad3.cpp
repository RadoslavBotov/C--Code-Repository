#include<iostream>

void inputN(int &N)
{
	do
	{
		std::cout << "> N: ";
		std::cin >> N;
	} while (N < 0 || N > 128);
}

void input(int &homeRow, int &homeColumn, int &grannyRow, int &grannyColumn, int &maxVolume, int N)
{
	do
	{
		std::cout << "> HomeRow, HomeColumn: ";
		std::cin >> homeRow >> homeColumn;
	} while ((homeRow < 0 || homeRow >= N) || (homeColumn < 0 || homeColumn >= N));

	do
	{
		std::cout << "> GrannyRow, GrannyColumn: ";
		std::cin >> grannyRow >> grannyColumn;
	} while ((grannyRow < 0 || grannyRow >= N) || (grannyColumn < 0 || grannyColumn >= N));
	
	do
	{
		std::cout << "> Max volume: ";
		std::cin >> maxVolume;
	} while (maxVolume < 0);
}

int** allocateMatrixMemory(int N)
{
	int** matrix = new int* [N];

	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];

	return matrix;
}

bool** allocateMatrixVisited(int N)
{
	bool** matrix = new bool* [N];

	for (int i = 0; i < N; i++)
		matrix[i] = new bool[N];

	return matrix;
}

void deleteMatrixMemory(int **matrix, int N)
{
	for (int i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void deleteMatrixMemory(bool** matrix, int N)
{
	for (int i = 0; i < N; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void inputMatrix(int** matrix, int N)
{
	std::cout << "> Map: " << std::endl;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> matrix[i][j];
}

void inputMatrix(bool** matrix, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			matrix[i][j] = false;
}

bool outOfBounds(int homeRow, int homeColumn, int N)
{
	return homeRow < 0 || homeRow >= N || homeColumn < 0 || homeColumn >= N;
}

bool validVolume(int maxVolume, int currentVolume)
{
	bool a = currentVolume < maxVolume;
	bool b = currentVolume > 0;
	return a && b;
}

bool foundRoute(int **map, bool **visited, int homeRow, int homeColumn, int grannyRow, int grannyColumn, int maxVolume, int currentVolume, int N, int paths)
{
	if (outOfBounds(homeRow, homeColumn, N) || visited[homeRow][homeColumn] || !validVolume(maxVolume, currentVolume))
		return false;

	if (homeRow == grannyRow && homeColumn == grannyColumn)
	{
		paths++;
		if (paths >= 2)
			return true;
	}

	visited[homeRow][homeColumn] = true;

	homeRow++;
	currentVolume += map[homeRow][homeColumn];
	foundRoute(map, visited, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, currentVolume, N, paths);
	currentVolume -= map[homeRow][homeColumn];
	homeRow--;

	homeRow--;
	currentVolume += map[homeRow][homeColumn];
	foundRoute(map, visited, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, currentVolume, N, paths);
	currentVolume -= map[homeRow][homeColumn];
	homeRow++; 
	
	homeColumn++;
	currentVolume += map[homeRow][homeColumn];
	foundRoute(map, visited, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, currentVolume, N, paths);
	currentVolume -= map[homeRow][homeColumn];
	homeColumn--;

	homeColumn--;
	currentVolume += map[homeRow][homeColumn];
	foundRoute(map, visited, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, currentVolume, N, paths);
	currentVolume -= map[homeRow][homeColumn];
	homeColumn++;
}

int main()
{
	int N = 5, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, paths = 0;

	inputN(N);
	int** map = allocateMatrixMemory(N);
	inputMatrix(map, N);
	input(homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, N);

	bool** visited = allocateMatrixVisited(N);
	inputMatrix(visited, N);

    std::cout << foundRoute(map, visited, homeRow, homeColumn, grannyRow, grannyColumn, maxVolume, map[homeRow][homeColumn], N, paths);

	deleteMatrixMemory(map, N);
	deleteMatrixMemory(visited, N);

	return 0;
}