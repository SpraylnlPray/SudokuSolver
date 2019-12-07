#include "pch.h"
#include "Field.h"


Field::Field(string input)
{
	input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
	input.erase(remove(input.begin(), input.end(), ','), input.end());
	
	SudokuEntry* entries[81];
	for (short i = 0; i < 81; i++)
		entries[i] = new SudokuEntry((int)input[i] - 48, i);

	for (short i = 0; i < gridSize; i++)
	{
		blocks[i] = new Block();
		rows[i] = new SudokuVector();
		cols[i] = new SudokuVector();
	}

	saveData(entries);
}


Field::~Field()
{
}

void Field::showData()
{
	for (short i = 0; i < gridSize; i++)
	{
		if (i % 3 == 0)
			cout << " =========================================" << endl;
		else
			cout << " -----------------------------------------" << endl;
		rows[i]->showData();
	}
	cout << " =========================================" << endl;
}

bool Field::solve()
{
	SudokuEntry* emptyCell = getUnassignedCell();
	if (!emptyCell)
		return true;

	for (short i = 0; i < gridSize; i++)
	{
		if (!emptyCell->block->containsValue(i) &&
			!emptyCell->row->containsValue(i) &&
			!emptyCell->col->containsValue(i))
		{
			emptyCell->value = i;
			if (solve())
				return true;

			emptyCell = 0;
		}
	}

	return false;
}

SudokuEntry* Field::getUnassignedCell()
{
	for (short i = 0; i < gridSize; i++)
	{
		SudokuEntry* unassignedCell = blocks[i]->getUnassignedCell();
		if (unassignedCell)
			return unassignedCell;
	}

	return nullptr;
}

void Field::saveData(SudokuEntry* entries[])
{
	short blockInputIndex = 0;
	short colInputIndex = 0;
	short rowInputIndex = 0;
	for (short rowIndex = 0; rowIndex < gridSize; rowIndex++) // Go through the gridSize lines of the field
	{
		for (short rowPos = 0; rowPos < gridSize; rowPos++, rowInputIndex++)
		{
			entries[rowInputIndex]->row = rows[rowIndex];
			rows[rowIndex]->addValue(entries[rowInputIndex], rowPos);
		}
		for (short colIndex = 0; colIndex < gridSize; colIndex++, colInputIndex++)
		{
			entries[colInputIndex]->col = cols[colIndex];
			cols[colIndex]->addValue(entries[colInputIndex], rowIndex);
		}
	}

	for (short blockIndex = 0; blockIndex < gridSize; blockIndex += 3) // go through the 3 lines of blocks
	{
		for (short linePos = 0; linePos < 27; linePos++, blockInputIndex++) // each line of blocks contains 3*gridSize=27 inputs
		{
			switch (linePos % gridSize)
			{
			case 0:
			case 1:
			case 2:
				entries[blockInputIndex]->block = blocks[blockIndex];
				blocks[blockIndex]->addValue(entries[blockInputIndex]);
				break;
			case 3:
			case 4:
			case 5:
				entries[blockInputIndex]->block = blocks[blockIndex + 1];
				blocks[blockIndex + 1]->addValue(entries[blockInputIndex]);
				break;
			case 6:
			case 7:
			case 8:
				entries[blockInputIndex]->block = blocks[blockIndex + 2];
				blocks[blockIndex + 2]->addValue(entries[blockInputIndex]);
				break;
			default:
				break;
			}
		}
	}
}
