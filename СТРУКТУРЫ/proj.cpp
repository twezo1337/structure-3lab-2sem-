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


Fuel dataInput(Fuel * arr, int n) {

	for (int i = 0; i < n; i++) {
		cout << "������� ����� �������: ";
		cin >> arr[i].mark;

		cout << "������� ���-�� ������: ";
		cin >> arr[i].kolLit;

		cout << "������� ����: ";
		cin >> arr[i].date.day;

		cout << "������� �����: ";
		cin >> arr[i].date.mounth;

		cout << "������� ���: ";
		cin >> arr[i].date.year;	
	}
	
	return (*arr);
}

Fuel dataOutput(Fuel * arr, int n) {

	for (int i = 0; i < n; i++) {
		
		cout << arr[i].mark << " " << arr[i].kolLit << " " << arr[i].date.day << " " << arr[i].date.mounth << " " << arr[i].date.year << endl;
	}
	
	return (*arr);

}

double checkLit(Fuel * arr, int n) {
	int d = 0, m = 0, y = 0;
	int marka;
	cout << "������� ���� ��� �������� (��.��.��): " << endl;
	cin >> d;
	cin >> m;
	cin >> y;
	cout << "������� ����� �������: ";
	cin >> marka;
	

	double sumFuel = 0;
	for (int i = 0; i < n; i++) 
	{
			if (arr[i].date.day == d && arr[i].date.mounth == m &&
				arr[i].date.year == y && arr[i].mark == marka)
			{

				sumFuel = sumFuel + arr[i].kolLit ;
			}
			
		
	}
	return sumFuel;
}

int main(void) {
	setlocale(LC_ALL, "russian");

	int N;
	cout << "������� ����� N: ";
	cin >> N;

	Fuel *fuel = new Fuel[N];
	dataInput(fuel, N);

	int out;
	cout << "������� 1 ���� ������ ������� ������ ��� 0 ��� ����������: ";
	cin >> out;

	switch (out) {
	case 1:
		dataOutput(fuel, N);
		break;
	case 0:
		return 0;
		break;
	}


	int key;
	cout << "������� 1 ���� ������ ������� �������� ��� 0 ��� ����������: ";
	cin >> key;

	switch (key) {
	case 1:
		{
		double a = checkLit(fuel, N); cout << a;
		break;
		}
	case 0:
		return 0;
		break;
	}

	system("pause");
}
