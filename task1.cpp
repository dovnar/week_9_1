#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int const size = 10;
	int isq[size];
	int number[size];
	int timeisq, timenumber, maxSize = 0;
	for (int i = 0; i < size; i++)
	{
		cout << "введите isq: ";
		cin >> timeisq;
		cout << "введите номер телефона: ";
		cin >> timenumber;
		if (timeisq == 0||
			timenumber == 0)
		{
			break;
		}
		isq[i] = timeisq;
		number[i] = timenumber;
		maxSize++;
	}
	cout << "Отсортировать по номерам ICQ = 1\nОтсортировать по номерам телефона = 2\n";
	int sort;
	cin >> sort;
	for (int i = 1; i < maxSize; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (isq[j] < isq[j - 1] && sort == 1 ||
				number[j] < number[j - 1] && sort == 2)
			{
				timeisq = isq[j];
				timenumber = number[j];
				isq[j] = isq[j - 1];
				number[j] = number[j - 1];
				isq[j - 1] = timeisq;
				number[j - 1] = timenumber;
			}
			else
			{
				break;
			}
		}
	}
	cout << "isq\t\tномер телефона\n";
	for (int i = 0; i < maxSize; i++)
	{
		cout << isq[i] << "\t" << number[i] << "\n";
	}
	return 0;
}