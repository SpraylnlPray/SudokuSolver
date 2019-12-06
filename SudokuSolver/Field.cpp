#include "pch.h"
#include "Field.h"


Field::Field(string input)
{
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	input.erase(remove(input.begin(), input.end(), ','), input.end());
	int numbers[81];
	for (short i = 0; i < 81; i++)
		numbers[i] = (int)input[i] - 48;

	for (size_t i = 0; i < 9; i++)
	{
		blocks[i] = new Block();
		rows[i] = new SudokuVector();
		cols[i] = new SudokuVector();
	}

	saveData(numbers);
}


Field::~Field()
{
}

void Field::saveData(int input[])
{
	for (short i = 0; i < 9; i += 3) // go through the lines of blocks (3 blocks per line)
	{
		for (short j = 0; j < 27; j++) // each line of blocks contains 3*9=27 inputs
		{
			switch (j % 9)
			{
			case 0:
			case 1:
			case 2:
				blocks[i]->addValue(input[j]);
				break;
			case 3:
			case 4:
			case 5:
				blocks[i + 1]->addValue(input[j]);
				break;
			case 6:
			case 7:
			case 8:
				blocks[i + 2]->addValue(input[j]);
				break;
			default:
				break;
			}
		}
	}
}
