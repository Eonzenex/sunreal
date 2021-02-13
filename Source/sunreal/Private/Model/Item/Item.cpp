#include "Item.h"

FItem::FItem()
{
	this->Name = "";
	this->MaxQuantityPerSlot = 0;
}

FItem::FItem(FString Name, int MaxQuantityPerSlot){
	this->Name = Name;
	this->MaxQuantityPerSlot = MaxQuantityPerSlot;
}