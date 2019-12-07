#pragma once
class SudokuVector;
class Block;

class SudokuEntry
{
public:
	SudokuEntry(int value, int id) : value(value), id(id) {}
	~SudokuEntry() {}

	int value;
	int id;
	SudokuVector* row;
	SudokuVector* col;
	Block* block;
};

