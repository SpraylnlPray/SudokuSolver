#include "pch.h"
#include "Field.h"


Field::Field(string input)
{
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	input.erase(remove(input.begin(), input.end(), ','), input.end());
	int numbers[81];
	for (short i = 0; i < 81; i++)
		numbers[i] = (int)input[i] - 48; // -48 to convert from ascii code to original value

	saveData(numbers);
}


Field::~Field()
{
}

void Field::saveData(int input[])
{
	short blockInputIndex = 0;
	short colInputIndex = 0;
	short rowInputIndex = 0;
	for (short rowIndex = 0; rowIndex < 9; rowIndex++) // Go through the 9 lines of the field
	{
		for (short rowPos = 0; rowPos < 9; rowPos++, rowInputIndex++)
		{
			rows[rowIndex].addValue(input[rowInputIndex], rowPos);
		}
		for (short colIndex = 0; colIndex < 9; colIndex++, colInputIndex++)
		{
			cols[colIndex].addValue(input[colInputIndex], rowIndex);
		}
	}

	for (short blockIndex = 0; blockIndex < 9; blockIndex += 3) // go through the 3 lines of blocks
	{
		for (short linePos = 0; linePos < 27; linePos++, blockInputIndex++) // each line of blocks contains 3*9=27 inputs
		{
			switch (linePos % 9)
			{
			case 0:
			case 1:
			case 2:
				blocks[blockIndex].addValue(input[blockInputIndex]);
				break;
			case 3:
			case 4:
			case 5:
				blocks[blockIndex + 1].addValue(input[blockInputIndex]);
				break;
			case 6:
			case 7:
			case 8:
				blocks[blockIndex + 2].addValue(input[blockInputIndex]);
				break;
			default:
				break;
			}
		}
	}
}
