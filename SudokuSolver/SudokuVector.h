#pragma once

using namespace std;

class SudokuVector
{
public:
	SudokuVector();
	~SudokuVector();

	bool containsValue(int val) 
	{
		for (short i = 0; i < 9; i++)
			if (values[i] == val)
				return true;
	}

	int values[9];
};

