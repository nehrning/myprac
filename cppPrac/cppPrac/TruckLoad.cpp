#include "stdafx.h"
#include "TruckLoad.h"

TruckLoad::TruckLoad(Box * pBox, int count)
{
	pHead = pTail = pCurrent = 0;
	if ((count > 0) && (pBox != 0))
		for (int i = 0; i < count; i++)
			addBox(pBox + i);
}

Box * TruckLoad::getFirstBox()
{
	pCurrent = pHead;
	return pCurrent->getBox();
}

Box * TruckLoad::getNextBox()
{
	if (pCurrent)
		pCurrent = pCurrent->getNext();
	else
		pCurrent = pHead;
	return pCurrent ? pCurrent->getBox() : 0;
}


void TruckLoad::addBox(Box * pBox)
{
	Package* pPackage = new Package(pBox);
	if (pHead)
		pTail->setNext(pPackage);
	else
		pHead = pPackage;
	pTail = pPackage;
}
