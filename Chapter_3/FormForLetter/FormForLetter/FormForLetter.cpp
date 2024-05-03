#include <iostream>
#include "..\Include\std_lib_facilities.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string name;
	string friend_name;
	char friend_sex;
	int age;

	cout << "Добро пожаловать в форму для письма! Ввдите пожалуйста своё имя: " << endl;
	cin >> name;

	cout << "\nДорогой " << name << endl;
	cout << "Как дела?\n" << "Всё хорошо! Скучаю по тебе!\n" << "Не могу прожить и дня!" << endl;

	cout << "\nНе хотите ввести имя друга: " << endl;
	cin >> friend_name;

	cout << "Давно ли ты встречал " << friend_name << "? " << endl;

	cout << "\nА какого твой друг пола: m или f?" << endl;
	cout << "Пол друга: ";
	cin >> friend_sex;


	if (friend_sex == 'm')
	{
		cout << "Если ты увидишь " << friend_name << " то попроси его перезвонить мне" << endl;
	}
	if (friend_sex == 'f')
	{
		cout << "Если ты увидишь " << friend_name << " то попроси её перезвонить мне" << endl;
	}

	cout << "\nА какого возраста твой друг?" << endl;
	cout << "Возраст друга: ";
	cin >> age;
	if (age <= 0 || age >= 110)
	{
		simple_error("Ты должно быть шутишь!");
	}
	cout << "\nЯ слышал, что ты только что отметил день рождения и тебе исполнилось " << age << " лет" << endl;

	if (age < 12)
	{
		cout << "В следующем году, тебе исполнится " << age + 1 << " лет" << endl;
	}
	if (age == 17)
	{
		cout << "В следующем году ты сможешь голосовать!" << endl;
	}
	if (age > 70)
	{
		cout << "Надеюсь, что ты не скучаешь на пенсии!" << endl;
	}

	cout << "Искрене твой, \n\n" << "Ярослав!" << endl;
}