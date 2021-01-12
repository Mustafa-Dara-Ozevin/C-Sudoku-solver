#include "Grid.h"
void Grid::init()
{
	std::vector<int> m_row1 = { 0, 0, 7, 0, 0, 3, 9, 0, 2 };
	std::vector<int> m_row2 = { 0, 0, 0, 8, 0, 0, 0, 0, 0 };
	std::vector<int> m_row3 = { 9, 4, 3, 0, 0, 0, 0, 0, 0 };
	std::vector<int> m_row4 = { 6, 9, 0, 0, 0, 0, 0, 0, 5 };
	std::vector<int> m_row5 = { 3, 0, 0, 5, 2, 7, 0, 0, 0 };
	std::vector<int> m_row6 = { 0, 0, 0, 0, 0, 0, 8, 4, 0 };
	std::vector<int> m_row7 = { 0, 0, 0, 0, 4, 8, 0, 0, 0 };
	std::vector<int> m_row8 = { 2, 6, 0, 0, 0, 0, 0, 0, 0 };
	std::vector<int> m_row9 = { 0, 0, 0, 0, 0, 0, 1, 2, 9 };
	m_grid = { m_row1, m_row2, m_row3, m_row4, m_row5, m_row6, m_row7, m_row8, m_row9 };
}
void Grid::render()
{
	std::cout << "---\n";
	for (std::vector<int> row : m_grid)
	{
		for (int i : row)
		{
			std::cout << i << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "---\n";
}

bool Grid::solve()
{
	const auto [rowIndex, columnIndex] = findEmptySquare();
	if (rowIndex == -1)
	{
		return true;
	}

	for (int i = 1; i < 10; i++)
	{
		if (checkSquare(i, { rowIndex, columnIndex }))
		{
			m_grid[rowIndex][columnIndex] = i;

			if (this->solve())
			{
				// this->render();
				return true;
			}

			m_grid[rowIndex][columnIndex] = 0;
		}
	}
	return false;
}

std::array<int, 2> Grid::findEmptySquare()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_grid[i][j] == 0)
			{
				return { i, j };
			}
		}
	}
	return { -1, -1 };
}

bool Grid::checkSquare(int number, std::array<int, 2> emptySquare)
{
	int checkedNumber = number;
	int row_index = emptySquare[0];
	int column_index = emptySquare[1];

	// check on row
	for (int number : m_grid[row_index])
	{
		if (number == checkedNumber)
			return false;
	}
	// check on column
	for (std::vector<int> row : m_grid)
	{
		if (row[column_index] == checkedNumber)
			return false;
	}
	// check on square
	int squareRow = row_index / 3;
	int squareColumn = column_index / 3;
	for (int row = squareRow * 3; row < squareRow * 3 + 3; row++)
	{
		for (int column = squareColumn * 3; column < squareColumn * 3 + 3; column++)
		{
			if (m_grid[row][column] == checkedNumber)
				return false;
		}
	}
	return true;
}
