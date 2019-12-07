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

	void addValue(int val, int index)
	{
		values[index] = val;
		count++;
	}

	int count = 0;
	int values[9];
};

