#pragma once


class TruckLoad {
public:
	TruckLoad(Box* pBox = 0, int count = 1);
	Box* getFirstBox();
	Box* getNextBox();
	void addBox(Box* pBox);
private:
	Package* pHead;
	Package* pCurrent;
	Package* pTail;
};

class Package {
public:
	Package(Box* pNewBox) : pBox(pNewBox), pNext(0) {}
	Box* getBox() const { return pBox; }
	Package* getNext() const{ return pNext; }
	void setNext(Package* pPackage) { pNext = pPackage; }

private:
	Box* pBox;
	Package* pNext;
};

class Box {
public:
	double length;
	double width;
	double height;
};