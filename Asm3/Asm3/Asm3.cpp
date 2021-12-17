#include <iostream>

using namespace std;

short int a, b, c, d;

int main() {
	setlocale(0, "ru");

	a = 4;
	b = 4;
	c = 4;
	d = 4;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	_asm
	{
		mov ax, a
		mov bx, b
		mov cx, c
		mov dx, d

		cmp ax, bx				// сравниваем
		ja first				// если ax>bx, иначе переходим к метке first
								// если ax<=bx, иначе идем дальше
		cmp bx, cx
		ja power				// переход к возведению в степень
		cmp cx, dx
		ja power				// переход к возведению в степень

		mov ax, dx				// замена каждого эллемента наибольшим
		mov bx, dx
		mov cx, dx
		mov dx, dx
		jmp last				// переходим в конец

		power :					// возведение во 2-ю степень
		imul ax, ax
			imul bx, bx
			imul cx, cx
			imul dx, dx
			jmp last			// переходим к концу программы

			first :				// проверка a>b>c>d, иначе переходим к power
		cmp bx, cx
			jbe power
			cmp cx, dx
			jbe power

			last :
		mov a, ax
			mov b, bx
			mov c, cx
			mov d, dx
	}

	cout << "a= " << a << endl;
	cout << "b= " << b << endl;
	cout << "c= " << c << endl;
	cout << "d= " << d << endl;
}
