#pragma once
#include "Block.h"
#include "SudokuVector.h"
#include "SudokuEntry.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <ctype.h>

using namespace std;

class SudokuField
{
public:
	SudokuField(string input);
	~SudokuField();

	Block* blocks[9];
	SudokuVector* rows[9];
	SudokuVector* cols[9];

	void showData();
	SudokuEntry* getUnassignedCell();

	bool InputIsValid;

private:
	short gridSize = 9;
	void createRowsAndCols(SudokuEntry* entries[]);
	void createBlocks(SudokuEntry* entries[]);
	void saveData(string input);
};

