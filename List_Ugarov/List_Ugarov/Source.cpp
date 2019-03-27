#include "Header.h"
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cList L1;
	int K, P;
	char input='\r';
	
	cout << "Изначальный список: ";
	for (int i = 1; i < 3; i++)
		L1.AddEnd(i);
	L1.Display();
	while(input == '\r')
	{
		cout << "Введите K: "; cin >> K;
		cout << "Введите P: "; cin >> P;
		L1.Method(K,P);
		L1.Display();
		cout << "Нажмите Enter, чтобы продолжить.\n";
		input = _getch();
	}
	system("pause");
	cout << endl;
	return 0;
}