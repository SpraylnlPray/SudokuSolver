#pragma once
#include "Block.h"
#include "SudokuVector.h"
#include "SudokuEntry.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Field
{
public:
	Field(string input);
	~Field();

	Block* blocks[9];
	SudokuVector* rows[9];
	SudokuVector* cols[9];

	void showData();
	SudokuEntry* getUnassignedCell();

private:
	short gridSize = 9;
	void saveData(SudokuEntry* entries[]);
};

