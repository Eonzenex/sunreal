#include "ItemStack.h"

FItemStack::FItemStack()
{
	this->ItemId = 0;
	this->Quantity = 0;
}

FItemStack::FItemStack(int ItemId, int Quantity)
{
	this->ItemId = ItemId;
	this->Quantity = Quantity;
}

void FItemStack::GetItemDefinition()
{
	return;
}

