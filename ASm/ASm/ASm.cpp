#include <iostream>

using namespace std;

short int a, d, n, s; // s - сумма

int main()
{
	setlocale(0, "ru");
	
	a = 2;
	d = 3;
	n = 0;
	s = 0;

	cout << "Начальные значения" << endl;
	cout << "a = " << a << endl;
	cout << "d = " << d << endl;
	cout << "n = " << n << endl << endl;

	_asm
	{
		mov cx, n
		cmp cx, 0
		je third							// если n=0, то ничего не меняя прыгаем в конец

		mov ax, a
		mov dx, d
		mov bx, s							// сюда запишется результат
		push ax								// помещаем a в начало стека, для определения момента остановки

		first :
		dec cx								// n-1
			mov bx, cx						// в s помещаем n-1
			imul bx, dx						// умножаем (n-1)*d, помещаем в s
			add bx, ax						// складываем a+(n-1)*d, помещаем в s
			push bx							// помещаем s в стек
			cmp cx, 1
			ja first						// если n>1, то повторяем

			mov bx, 0						// обнуляем s для избежания некорректных расчётов

			second:
		pop cx								// читаем в n так как она уже бесполезна
			add bx, cx						// находим сумму
			cmp cx, ax
			jne second						// если n != a

			mov s, bx						// ответ

			third :
	}

	cout << "s = " << s << endl;
}


/*
PUSH - помещение в стек
POP - выталкивание из стека
cmp ax, bx - сравнение
ja - если >
jb - если <
jae - если >=
jbe - если <=
je - если =
jne - если !=
*/




