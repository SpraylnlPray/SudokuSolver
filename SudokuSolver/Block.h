#pragma once

using namespace std;

class Block
{
public:
	Block();
	~Block();

	bool containsValue(int val)
	{
		for (short i = 0; i < 9; i++)
			if (values[i] == val)
				return true;
	}

	void addValue(int val)
	{
		values[counter] = val;
		counter++;
	}

	int values[9];
	int counter = 0;
};

