#pragma once
#include "Block.h"
#include "SudokuVector.h"
#include <string>
#include <algorithm>

using namespace std;

class Field
{
public:
	Field(string input);
	~Field();

	Block* blocks[9];
	SudokuVector* rows[9];
	SudokuVector* cols[9];

private:
	void saveData(int input[]);
};

