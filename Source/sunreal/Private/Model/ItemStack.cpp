#include "ItemStack.h"

FItemStack::FItemStack(int ItemId, int Quantity)
{
	this->ItemId = ItemId;
	this->Quantity = Quantity;
}

void FItemStack::GetItemDefinition()
{
	return;
}

