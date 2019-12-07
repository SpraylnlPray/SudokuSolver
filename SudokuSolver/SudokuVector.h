#pragma once
#include "SudokuEntry.h"
#include <iostream>

using namespace std;

class SudokuVector
{
public:
	SudokuVector();
	~SudokuVector();

	bool containsValue(int val) 
	{
		for (short i = 0; i < 9; i++)
			if (entries[i]->value == val)
				return true;

		return false;
	}

	void addValue(SudokuEntry* entry, int index)
	{
		entries[index] = entry;
	}

	void showData()
	{
		for (short i = 0; i < 9; i++)
		{
			if (i % 3 == 0)
				cout << " || " << entries[i]->value;
			else
				cout << " | " << entries[i]->value;
		}
		cout << " ||" << endl;
	}

	bool HasUnassignedCell()
	{
		for (short i = 0; i < 9; i++)
			if (entries[i] == 0)
				return true;

		return false;
	}

	SudokuEntry* entries[9];
};

