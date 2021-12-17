#include <iostream>

using namespace std;

short int v, p, n;

int main(){
	setlocale(0, "ru");
	cout << "Введите сторону n:";
	cin >> n;

	 _asm
	{
		mov ax, n					// помещаем n в ax
		mul n						// умножение n на ax и помещение результата в ax
		mov p, ax					// помещаем ax в p
		mul n						// умножение n на ax и помещение результата в ax
		mov v, ax					// помещаем ax в v
	}
	cout << "Площадь боковой стороны куба P= " << p << endl;
	cout << "Объём куба V= " << v << endl;
}
