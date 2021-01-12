#pragma once
#include <iostream>
#include <vector>
#include <array>

struct Grid
{
	std::vector<std::vector<int>> m_grid;

	void init();
	void render();
	bool solve();

	std::array<int, 2> findEmptySquare();
	bool checkSquare(int number, std::array<int, 2>);
};
