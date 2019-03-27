#include <iostream>
#include <stdio.h>


using namespace std;

#define List struct list
List{ int Dn; List *Nx; };

class cList {
protected: List * p;
public:
	cList() {
		p = NULL;
	}

	bool Empty() {
		return p == NULL;
	}

	void Display() {
		List* t = p;
		if (p) {
			while (t) {
				cout << t->Dn << " ";
				t = t->Nx;
			}
		}
		else
			cout << "-->|";
		cout << endl;
	}

	void AddHead(int D) {
		List* q = new List;
		q->Dn = D;
		q->Nx = p;
		p = q;
	}

	void AddEnd(int D) {
		List* q = new List;
		q->Dn = D;
		q->Nx = NULL;
		List* t = p;
		if (p) {
			while (t->Nx)
				t = t->Nx;
			t->Nx = q;
		}
		else p = q;
	}

	long Length() {
		if (p) {
			List* t = p;
			long i = 0;
			while (t) {
				t = t->Nx;
				i++;
			}
			return i;
		}
		return 0;
	}

	void DelHead() {
		List* q = p;
		p = p->Nx;
		delete(q);
	}

	bool DelElem(int i)
	{
		if (i < 0 || i > Length())
		{
			return 0;
		}
		if (i == 1)
		{
			DelHead();
			return 1;
		}
		List* cur = p;
		List* prev = cur;
		while (--i)
		{
			if (i == 1) prev = cur;
			cur = cur->Nx;
		}
		prev->Nx = cur->Nx;
		delete cur;
		return 1;
	}

	bool Method(int i, int j)
	{
		if (i < 1 || j < 1 || i>Length() || j > Length())
		{
			cout << "Недопустимые параметры!\n";
			return false;
		}

		if (i == j)
		{
			DelElem(i);
		}
		else
		{
			if (i > j)
			{
				int temp = i;
				i = j;
				j = temp;
			}
			List* curIN = p;
			List* curJN = p;
			List* curI = p;
			List* curJ = p;
			List* curJNNT = p;
			for(int c=i-1;c>1;c--)
			{
				curI = curI->Nx;
			}
			for(int c=j-1;c>1;c--)
			{
				curJ = curJ->Nx;
			}
			curIN = curI->Nx;
			curJN = curJ->Nx;
			curJNNT = curJN->Nx;

			if ((i == 1) && (i+1 == j))
			{
				p = curJN;
				p->Nx = curI;
				curI->Nx = curJNNT;
			}
			else if (i == 1)
			{
				p = curJN;
				p->Nx = curI->Nx;
				curJ->Nx = curI;
				curI->Nx = curJNNT;
			}
			else if (i + 1 == j)
			{
				curI->Nx = curJN;
				curJN->Nx = curJ;
				curJ->Nx = curJNNT;
			}
			else
			{
				curI->Nx = curJN;
				curJN->Nx = curIN->Nx;
				curJ->Nx = curIN;
				curIN->Nx = curJNNT;
			}
		}
	}
};

