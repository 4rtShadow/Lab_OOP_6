#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

int maxint(int array[], int count)
{
	int max = array[0];
	int max_count = 0;
	for (int i = 1; i < count; i++)
	{
		if (max < array[i])
		{
			max = array[i];
			max_count = i;
		}
	}
	return max_count;
}

class fraction {
private:
	int num, den;
	char ch;
	void lowterms() // сокращение дроби
	{
		long tnum, tden, temp, gcd;
		tnum = labs(num); // используем неотрицательные
		tden = labs(den); // значения (нужен cmath)
		if (tden == 0) // проверка знаменателя на 0
		{
			cout << "Недопустимый знаменатель!"; exit(1);
		}
		else if (tnum == 0) // проверка числителя на 0
		{
			num = 0; den = 1; return;
		}
		// нахождение наибольшего общего делителя
		while (tnum != 0)
		{
			if (tnum < tden) // если числитель больше знаменателя,
			{
				temp = tnum; tnum = tden; tden = temp;
			} // меняем их местами
			tnum = tnum - tden; // вычитание
		}
		gcd = tden; // делим числитель и знаменатель на
		num = num / gcd; // полученный наибольший общий делитель
		den = den / gcd;
	}
public:
	fraction()
	{
		num = 0, den = 1;
	}
	fraction(int num, int den)
	{
		this->num = num;
		this->den = den;
		lowterms();
	}
	void set()
	{
		cout << "Введите дробь вида а/в: ";
		cin >> num >> ch >> den;
		lowterms();
	}
	void get()
	{
		lowterms();
		cout << num << '/' << den;
	}
	void add(fraction frac1, fraction frac2)
	{
		num = frac1.num * frac2.den + frac1.den * frac2.num;
		den = frac1.den * frac2.den;
		lowterms();
	}
	double sr(int sred)
	{
		double lenght;
		lenght = (double)num / (double)den;
		lenght /= (double)sred;
		return lenght;
	}
};

enum Suit { clubs, diamonds, hearts, spades };
class card {
private:
	int number;
public:
	static const int jack = 11;
	static const int queen = 12;
	static const int king = 13;
	static const int ace = 14;
	Suit suit;
	card() 
	{ }
	void Set(int n, Suit s)
	{
		suit = s, number = n;
	}
	void display()
	{
		if (number >= 2 && number <= 10)
		{
			cout << number;
		}
		else
		{
			switch (number)
			{
			case jack: cout << "J"; break;
			case queen: cout << "Q"; break;
			case king: cout << "K"; break;
			case ace: cout << "A"; break;
			}
		}
		switch (suit)
		{
		case clubs: cout << static_cast<char>(5); break;
		case diamonds: cout << static_cast<char>(4); break;
		case hearts :cout << static_cast<char>(3); break;
		case spades: cout << static_cast<char>(6); break;
		}
	}

};

class cash {
private:
	string cashstr;
	long double cashnum;
public:
	void set()
	{
		cout << "Введите количество долларов: ";
		cin.get();
		getline(cin, cashstr);
	}
	void get()
	{
		cout << "Преобразованное число $" << setiosflags(ios::fixed)  << setprecision(2) << mstold() << endl;
	}
	void setLong()
	{
		cout << "Введите количество долларов: ";
		cin >> cashnum;
	}
	void getLong()
	{
		cout << "Преобразованное число: " << ldtoms() << endl;
	}
	long double mstold()
	{
		long double preobraz;
		string str = cashstr;
		int len = cashstr.length(), x = str.find(' ');
		while (x < str.size())
		{
			str.replace(x, 1, "");
			x = str.find(' ');
		}
		x = str.find('$');
		str.replace(x, 1, "");
		x = str.find('.');
		str.replace(x, 1, "");
		preobraz = stold(str)/100;
		return preobraz;

	}
	string ldtoms()
	{
		string preob = to_string((long)(cashnum*100));
		string preob_1 = "";
		int len = preob.length(), count = 0, three = 0;
		for (int i = len-1; i >= 0; i--)
		{
			if (three == 3)
			{
				preob_1 = " " + preob_1;
			}
			preob_1 = preob[i] + preob_1;
			count += 1;
			three += 1;
			if (count == 2)
			{
				preob_1 = "." + preob_1;
				three = 0;
			}
		}
		preob_1 = "$" + preob_1;
		return preob_1;

	}
};

class safearay {
private:
	static const int LIMIT = 100;
	int array[LIMIT];
public:
	safearay()
	{
		for (int i = 0; i < LIMIT; i++)
		{
			array[i] = 0;
		}
	}
	void putel(int i, int znach)
	{
		if (i >= 0 && i <= LIMIT - 1)
		{
			array[i] = znach;
		}
		else if (i > LIMIT - 1)
		{
			cout << "Введённый вами индекс превышает размерность массива!\n";
		}
		else
		{
			cout << "Введённый вами индекс не может быть отрицательным!\n";
		}
	}

	int setel(int i)
	{
		if (i >= 0 && i <= LIMIT - 1)
		{
			return array[i];
		}
		else if (i > LIMIT - 1)
		{
			cout << "Введённый вами индекс превышает размерность массива!\n";
			return NULL;
		}
		else
		{
			cout << "Введённый вами индекс не может быть отрицательным!\n";
			return NULL;
		}
	}
};

class queue {
private:
	static const int MAX = 5;
	int array[MAX];
	int head, tail;
public:
	queue()
	{
		for (int i = 0; i < MAX; i++)
		{
			array[i] = 0;
		}
		head = MAX;
		tail = MAX;
	}
	void print()
	{
		for (int i = 0; i < MAX; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void put(int var)
	{
		for (int i = 1; i < MAX; i++)
		{
			array[i-1] = array[i];
		}
		array[tail - 1] = var;
		head--;
		if (head == -1)
		{
			head++;
		}
	}
	int get()
	{
		if (head != MAX)
		{
			return array[head++];
		}
		else
		{
			cout << "В очереди нет людей!\n";
			return NULL;
		}

	}
};

class matrix {
private:
	int i, j;
	int array[10][10];
public:
	matrix()
	{
		array[10][10];
		i = 10, j = 10;
	}
	matrix(const int i, const int j) {
		if (i <= 10 && j <= 10) 
		{
			this->i = i;
			this->j = j;
			array[i][j];
		}
		else
		{
			this->i = 10;
			this->j = 10;
			array[10][10];
		}
	}
	void set(const int i, const int j)
	{
		if (i <= 10 && j <= 10)
		{
			this->i = i;
			this->j = j;
			array[i][j];
		}
		else
		{
			cout << "Вы ввели больше доступного размер!\n";
			this->i = 10;
			this->j = 10;
			array[10][10];
		}
	}
	void putel(int i, int j, int value)
	{
		if (i <= this->i && j <= this->j)
		{
			array[i][j] = value;
		}
		else
		{
			cout << "Вы ввели не корректные границы массива!\n";
		}
	}
	int getel(int i, int j)
	{
		if (i <= this->i && j <= this->j)
		{
			cout << "Значение " << array[i][j] << " по индексам i = " << i << " j = " << j << endl;
			return array[i][j];
		}
		else
		{
			cout << "Вы ввели не корректные границы!\n";
			return NULL;
		}
	}
};

class bMoney {
private:
	long double money;
	string ldtoms()
	{
		string preob = to_string((long)(money * 100));
		string preob_1 = "";
		int len = preob.length(), count = 0, three = 0;
		for (int i = len - 1; i >= 0; i--)
		{
			if (three == 3)
			{
				preob_1 = " " + preob_1;
			}
			preob_1 = preob[i] + preob_1;
			count += 1;
			three += 1;
			if (count == 2)
			{
				preob_1 = "." + preob_1;
				three = 0;
			}
		}
		preob_1 = "$" + preob_1;
		return preob_1;

	}
	long double mstold(string String)
	{
		long double preobraz;
		string str = String;
		int len = str.length(), x = str.find(' ');
		while (x < str.size())
		{
			str.replace(x, 1, "");
			x = str.find(' ');
		}
		x = str.find('$');
		str.replace(x, 1, "");
		x = str.find('.');
		str.replace(x, 1, "");
		preobraz = stold(str) / 100;
		return preobraz;

	}
public:
	bMoney()
	{
		money = 0.0;
	}
	bMoney(char bMon[])
	{
		money = mstold(bMon);
	}
	void obnulytor()
	{
		money = 0.0;
	}
	void madd(bMoney bMoney1)
	{
		money += bMoney1.money;
	}
	void getmoney()
	{
		string S;
		cout << "Введите сумму денег(в долларах): ";
		cin.get();
		getline(cin, S);
		money = mstold(S);
	}
	void putmoney()
	{
		cout << "Общая сумма долларов: " << ldtoms() << endl ;
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
    bool end = true, do_end = true;
	int number, count, x, index, value, ind1, ind2;
	char ch;
	const int MAX = 100;
	int IntNum[MAX];
	double sr;
	card deck[52], deck_player[4][13];
	fraction Fraction[MAX], frac_sr;
	cash Cash[100], LongCash[100];
	safearay saf;
	queue que;
	matrix matrix1;
	bMoney Money[100];
	do
	{
		cout << "Введите номер задания: ";
		cin >> number;
		switch (number)
		{
		case 4:
			count = 0, do_end = true;
			do
			{
				if (count == 100)
				{
					cout << "Массив полон!\n";
					break;
				}
				cout << "Ведите целое число: ";
				cin >> IntNum[count++];
				cout << "Хотите продолжить ввод?(y/n)\n";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			x = maxint(IntNum, count);
			cout << "Максимальное число: " << IntNum[x] << " с индексом " << x << endl;
			break;
		case 5:
			count = 0, do_end = true;
			do
			{
				if (count == 100)
				{
					cout << "Массив полон!\n";
					break;
				}
				Fraction[count++].set();
				cout << "Хотите продолжить ввод?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			frac_sr = Fraction[0];
			for (int i = 1; i < count; i++)
			{
				frac_sr.add(frac_sr, Fraction[i]);
			}
			sr = frac_sr.sr(count);
			cout << "Среднее значение дробей: " << sr << endl;
			break;
		case 6:
			for (int i = 0; i < 52; i++)
			{
				int num = (i % 13) + 2;
				Suit su = Suit(i / 13);
				deck[i].Set(num, su);
			}
			cout << "Исходная колода карт:\n";
			for (int i = 0; i < 52; i++)
			{
				deck[i].display();
				cout << " ";
				if (!((i+1)%13))
					cout << endl;
			}
			srand(time(NULL));
			for (int i = 0; i < 52; i++)
			{
				int k = rand() % 52;
				card temp = deck[i];
				deck[i] = deck[k];
				deck[k] = temp;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					deck_player[i][j] = deck[i * 13 + j];
				}
			}
			cout << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << "Колода карт " << i + 1 << " игрока: ";
				for (int j = 0; j < 13; j++)
				{
					deck_player[i][j].display();
					cout << " ";
				}
				cout << endl;
			}
			cout << "\nПеремешанная колода:\n";
			for (int i = 0; i < 52; i++)
			{
				deck[i].display();
				cout << " ";
				if (!((i + 1) % 13))
					cout << endl;
			}
			break;
		case 7:
			count = 0, do_end = true;
			do
			{
				if (count == 100)
				{
					cout << "Массив полон!\n";
					break;
				}
				Cash[count].set();
				Cash[count++].get();
				cout << "Хотите ввести ещё?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			break;
		case 8:
			do_end = true;
			do
			{
				cout << "Введите индекс: ";
				cin >> index;
				cout << "Введите значение: ";
				cin >> value;
				saf.putel(index, value);
				cout << "Хотите ввести ещё значение?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			do_end = true;
			do
			{
				cout << "Введите индекс: ";
				cin >> index;
				x = saf.setel(index);
				if (x != NULL)
				{
					cout << "Значение " << x << " по индексу " << index << endl;
				}
				cout << "Хотите ещё ввести индекс?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			break;
		case 9:
			do_end = true;
			cout << "Введите число в массив: ";
			cin >> value;
			que.put(value);
			que.print();
			do
			{
				cout << "Что вы хотите, ввести число или вывести?(v/n) ";
				cin >> ch;
				if (ch == 'v')
				{
					cout << "Введите число в массив: ";
					cin >> value;
					que.put(value);
					que.print();
				}
				else
				{
					cout << "Число: " << que.get() << endl;
					que.print();
				}
			} while (do_end);
			break;
		case 10:
			matrix1.set(8, 5);
			do_end = true;
			do
			{
				cout << "Хотите ввести данные в матрицу, вывести или выйти?(v/n/e) ";
				cin >> ch;
				switch (ch)
				{
				case 'v':
					cout << "Введите индексы и значение: ";
					cin >> ind1 >> ind2 >> value;
					matrix1.putel(ind1, ind2, value);
					break;
				case 'n':
					cout << "Введите индексы: ";
					cin >> ind1 >> ind2;
					value = matrix1.getel(ind1, ind2);
					break;
				case 'e':
					do_end = false;
					break;
				default:
					cout << "Такой команды нет!\n";
					break;
				}
			} while (do_end);
			break;
		case 11:
			do_end = true, count = 0;
			do
			{
				if (count == 100)
				{
					cout << "Массив полон!\n";
					break;
				}
				LongCash[count++].setLong();
				cout << "Хотите ввести ещё?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			for (int i = 0; i < count; i++)
			{
				LongCash[i].getLong();
			}
			break;
		case 12:
			do_end = true, count = 1;
			Money[0].obnulytor();
			do
			{
				if (count == 100)
				{
					cout << "Массив полон!\n";
					break;
				}
				Money[count++].getmoney();
				cout << "Хотите ещё ввести индекс?(y/n) ";
				cin >> ch;
				(ch == 'n') ? do_end = false : do_end = true;
			} while (do_end);
			for (int i = 1; i < count; i++)
			{
				Money[0].madd(Money[i]);
			}
			Money[0].putmoney();
			break;
		default:
			end = false;
			break;
		}
	} while (end);
	return 0;
}
