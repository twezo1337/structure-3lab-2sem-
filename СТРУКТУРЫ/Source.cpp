#include <fstream>
#include <iostream>
using namespace std;

struct Date {
	short day;
	short mounth;
	short year;
};

struct Owner {
	char sur[25];
	char name[25];
	char otch[25];
};

struct Fuel {
	short mark;
	double kolLit;
	Date date;
	Owner owner;
};

Fuel *fuel;
Fuel dataInput(int n) {
	fuel = new Fuel[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ����� �������: ";
		cin >> fuel[i].mark;

		cout << "������� ���-�� ������: ";
		cin >> fuel[i].kolLit;

		cout << "������� ����: ";
		cin >> fuel[i].date.day;

		cout << "������� �����: ";
		cin >> fuel[i].date.mounth;

		cout << "������� ���: ";
		cin >> fuel[i].date.year;	
	}
	
	return (*fuel);
}

int main(void) {

	setlocale(LC_ALL, "russian");

	int N;
	cout << "������� ����� N: ";
	cin >> N;

	dataInput(N);

	int d = 0, m = 0, y = 0;
	int marka;
	cout << "������� ���� ��� �������� (��.��.��): ";
	cin >> d;
	cin >> m;
	cin >> y;
	cout << "������� ����� �������: ";
	cin >> marka;

	int sumFuel = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (((fuel[i].date.day == d) == (fuel[j].date.day == d)) && ((fuel[i].date.mounth == m) == (fuel[j].date.mounth == m)) &&
				((fuel[i].date.year == y) == (fuel[j].date.year == y)) && ((fuel[i].mark == marka) == (fuel[j].mark == marka))) {

				sumFuel = sumFuel + fuel[i].kolLit + fuel[j].kolLit;
				
			}
		}	
	}

	cout << sumFuel;

}






