#include "pch.h"
#include "Block.h"


Block::Block()
{
}


Block::~Block()
{
}

SudokuEntry* Block::getUnassignedCell()
{
	for (short i = 0; i < 9; i++)
		if (entries[i]->value == 0)
			return entries[i];

	return nullptr;
}
