#include <iostream>
#include <windows.h>

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int main() 
{
	setlocale (LC_ALL, "Russian");
	cout << "Доброго времени суток! Вы запустили программу по созданию числовой спирaли." << endl;
	int N = 0, M = 0, B = 0, C = 0, E = 0;
	cout << "Введите высоту числовой спирали. (от 1 до 11)" << endl;
	cin >> N;
	while (N > 11 || N < 1) 
	{
		if (N > 11) 
		{
			SetConsoleTextAttribute(color, 4);
			cout << "Ваше число больше, чем требуется. Попробуйте снова." << endl;
			SetConsoleTextAttribute(color, 7);
		}
		else if (N < 1) 
		{
			SetConsoleTextAttribute(color, 4);
			cout << "Ваше число меньше, чем требуется. Попробуйте снова." << endl;
			SetConsoleTextAttribute(color, 7);
		}
		else {
			cin >> N;
		}
		cin >> N;
	}
	cout << "Введите длину числовой спирали. (от 1 до 11)" << endl;
	cin >> M;
	while (M > 11 || M < 1) 
	{
		if (M > 11) 
		{
			SetConsoleTextAttribute(color, 4);
			cout << "Ваше число больше, чем требуется. Попробуйте снова." << endl;
			SetConsoleTextAttribute(color, 7);
		}
		else if (M < 1) 
		{
			SetConsoleTextAttribute(color, 4);
			cout << "Ваше число меньше, чем требуется. Попробуйте снова." << endl;
			SetConsoleTextAttribute(color, 7);
		}
		cin >> M;
	}
	int spyral[13][13];
	int i = 0, j = 0, X = -1, A = M * N + 1, F = 1, G = 0;
	for (;;)
	{
		cout << "Также выбирете ход числовой спирали. В центр - '1'; от центра - '2'" << endl;
		cin >> E;
		if (E == 1)
		{
			X = 1;
			A = 0;
			break;
		}
		else if (E == 2)
		{
			X = -1;
			break;
		}
		else
		{
			SetConsoleTextAttribute(color, 4);
			cout << "Введено неправильное значение. Пожалуйста введите снова." << endl;
			SetConsoleTextAttribute(color, 7);
		}
	}
	for (;;)
	{
		cout << "Выбирете направление закрученности числовой спирали. По часовой - '1'; против часовой - '2'" << endl;
		cin >> G;
		if ((E == 1 && G == 1) || (E == 2 && G == 2))
		{
			B++;
			C++;
			F = 1;
			break;
		}
		else if ((E == 2 && G == 1) || (E == 1 && G == 2))
		{
			B++;
			F = -1;
			C = M;
			break;
		}
		else
			SetConsoleTextAttribute(color, 4);
			cout << "Введено неправильное значение. Пожалуйста введите снова." << endl;
			SetConsoleTextAttribute(color, 7);
	}
	for (i = 0; i < 13; i++)
		for (j = 0; j < 13; j++)
			spyral[i][j] = -1;
	for (i = 1; i < N + 1; i++)
		for (j = 1; j < M + 1; j++)
			spyral[i][j] = 0;
	while (1)
	{
		i = B;
		j = C;
		while (spyral[i][j] == 0)
		{
			A += X;
			spyral[i][j] = A;
			j = j + F;
		}
		i++;
		j = j - F;
		while (spyral[i][j] == 0)
		{
			A += X;
			spyral[i][j] = A;
			i++;
		}
		i--;
		j = j - F;
		while (spyral[i][j] == 0)
		{ 
			A += X;
			spyral[i][j] = A;
			j = j - F;
		}
		j = j + F;
		i--;
		while (spyral[i][j] == 0) 
		{
			A += X;
			spyral[i][j] = A;
			i--;
		}
		i = 0;
		j = 0;
		B++;
		C = C + F;
		if (B != (N + 3) / 2 && C != (M + 1 + 2 * F) / 2)
		{
			continue;
		}
		else
			break;
	}
	for (i = 1; i < N + 1; i++)
		{
			cout << endl;
			SetConsoleTextAttribute(color, 9);
			for (j = 1; j < M + 1; j++)
				printf("%4d", spyral[i][j]);
		}
	SetConsoleTextAttribute(color, 7);
	return 0;
}