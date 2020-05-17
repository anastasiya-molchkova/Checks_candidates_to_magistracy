/* Рейтинг бакалавра заочного отделения при поступлении в магистратуру определяется средним баллом по диплому, 
умноженным на коэффициент стажа работы по специальности, который равен: 
нет стажа — 1, 
меньше 2-ух лет — 13, 
от 2 до 5 лет — 16. 
Написать программу расчёта рейтинга студента при заданном среднем балле диплома (от 3 до 5) 
и вывести сообщение о приёме в магистратуру (при проходном балле 45). */

#include <iostream>
using std::cout; using std::cin; using std::endl;

double get_expirience()
{
	cout << "Сколько лет бакалавр работал по специальности? ";
	double answer{ 0 };
	cin >> answer;
	const unsigned short maximum_expirience_by_task = 5;
	const unsigned short maximum_expirience = 50;
	while (cin.fail() || (answer < 0) || (answer > maximum_expirience_by_task))
	{
		if ((answer > maximum_expirience_by_task) && (answer <= maximum_expirience))
		{
			cout << "Замысел программы не предполагает настолько большого опыта, но мы её доработали!" << '\n';
			break; // выходим из while, т.к. будем работать и с таким опытом
		}
		cin.clear();
		cin.ignore(10000, '\n');
		if (answer > maximum_expirience)
			cout << "Бакалавры столько не работают, введите опыт поскромнее! ";
		else // введено что-то не double или отрицательное
			cout << "Ваш ответ не корректен, нужно ввести сколько лет бакалавр работал по специальности: ";
		cin >> answer;
	}
	return answer;
}

double get_expirience_koefficient(const double expirience)
{
	if (expirience == 0)
		return 1;
	if (expirience < 2)
		return 13;
	else return 16;
}

double get_average_score()
{
	cout << "Средний балл бакалавра по диплому: ";
	double answer{ 0 };
	cin >> answer;
	const unsigned short minimum = 3;
	const unsigned short maximum = 5;
	while (cin.fail() || (answer < minimum) || (answer > maximum))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		if ((answer > 0) && (answer < minimum))
			cout << "Извините, но мы не верим, что можно так плохо учиться! Введите средний балл по диплому ещё раз: ";
		else
		{
			if (answer > maximum)
				cout << "Извините, но средний балл не может быть выше " << maximum << "! Не льстите себе, введите средний балл по диплому ещё раз: ";
			else // введено что-то не double или отрицательное
				cout << "Ваш ответ не корректен, нужно ввести средний балл бакалавра по диплому: ";
		}
		cin >> answer;
	}
	return answer;
}

double rating_calculation(const double average_score, const double expirience_parameter)
{
	return (average_score * expirience_parameter);
}

bool pass_or_not(const double rating)
{
	const double passing_score = 45;
	if (rating >= passing_score)
		return true;
	else return false;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода сообщений на кириллице
	cout << "**********Программа проверяет, проходит ли бакалавр в магистратуру.**********" << endl << endl;
	while (true)
	{
		const double average_score_by_diploma = get_average_score();
		const double expirience = get_expirience();
		const double rating = rating_calculation(average_score_by_diploma, get_expirience_koefficient(expirience));
		cout << "Рейтинг бакалавра: " << rating;
		if (pass_or_not(rating))
			cout << " Данный бакалавр может быть зачислен в магистратуру!" << endl << endl;
		else 
			cout << " Увы, такой бакалавр не может быть принят в магистратуру!" << endl << endl;
	}
}