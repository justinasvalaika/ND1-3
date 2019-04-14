
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define debugas false;
using namespace std;

#define RANKINISIVEDIMAS jo;

struct Sduomenys {
	string vardas, pavarde;
	vector <int> pazymiai;
	double vidurkis, mediana, galutinis;
	void pildymas();
};

vector<Sduomenys> lentele;

void Sduomenys::pildymas()
{
	int itemp, j=1,kk, o, lol;
	char k;
	cout << "Vardas: ";
	cin >> vardas;
	cout << "Pavarde: ";
	cin >> pavarde;
	pazymiai.clear();
	cout<<"Generuoti atsitiktinai pazymius? T?";
	cin>>k;
	switch (k)
	{
    case ('T','t'):
        cout<<"kelis pazymius? ";
        cin>>kk;
        for (o=0;o<kk; o++)
            {
                pazymiai.push_back(rand()%10);
            }
        break;
    default:
        do {
		cout << j<<" -as ND: ";
		cin >> itemp;
		if (itemp > 0 && itemp <= 10)
			{
			    pazymiai.push_back(itemp);
			    j++;
			}
	} while (itemp != 0);
        break;
	}

	vidurkis = 0;
	for (int i : pazymiai)
		vidurkis += i;
	vidurkis = double(vidurkis) / pazymiai.size();
	sort(pazymiai.begin(), pazymiai.end());
	mediana = (pazymiai.size() % 2 == 1) ? pazymiai[pazymiai.size() / 2] : double(pazymiai[pazymiai.size() / 2] + pazymiai[pazymiai.size() / 2 - 1]) / 2;
}

void isvedimas()
{
    char vm='l';
    bool _med=false;


       cout<<"Pasirink viduri/mediana  V/M:"<<endl;
       cin>>vm;

    cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<right<<setw(15)<<"Galutinis ";


    switch (vm)
    {
        case ('V','v'):
            cout<<"(vid.)"<<endl;
            break;
        case ('M','m'):
            _med=true;
            cout<<"(med.)"<<endl;
            break;
    }

    cout<<"-"<<setfill('-')<<setw(50)<<"-"<<endl;
    cout<<setfill(' ');
    for (Sduomenys i : lentele) {
		cout <<left<<setw(15)<< i.vardas<<left<<setw(15)<<i.pavarde<<right<<setw(21);

		_med==false? cout << fixed<<setprecision(2)<<i.vidurkis<<endl: cout<<fixed<< setprecision(2)<<i.mediana<< endl;
	}
	cout<<"-"<<setfill('-')<<setw(50)<<"-"<<endl;
	cout<<setfill(' ');
}

int main()
{
	Sduomenys Sd_temp;  char kr;
	do {
		Sd_temp.pildymas();
		lentele.push_back(Sd_temp);

		cout << "Kitas irasas? T/n: "<<endl;;
		cin >> kr;
	} while (kr == 't' || kr == 'T');


	isvedimas();

}
