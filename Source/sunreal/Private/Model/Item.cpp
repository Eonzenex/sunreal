#include "Item.h"

FItem::FItem(int Id, FString Name, int MaxQuantityPerSlot){
	this->Id = Id;
	this->Name = Name;
	this->MaxQuantityPerSlot = MaxQuantityPerSlot;
}
