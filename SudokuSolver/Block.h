#pragma once
#include "SudokuEntry.h"

using namespace std;

class Block
{
public:
	Block();
	~Block();

	bool containsValue(int val)
	{
		for (short i = 0; i < 9; i++)
			if (entries[i]->value == val)
				return true;

		return false;
	}

	void addValue(SudokuEntry* entry)
	{
		entries[counter] = entry;
		counter++;
	}

	SudokuEntry* getUnassignedCell();

	SudokuEntry* entries[9];
	int counter = 0;
};

