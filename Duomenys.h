#ifndef DUOMENYS_H_INCLUDED
#define DUOMENYS_H_INCLUDED

struct Sduomenys {
	string vardas, pavarde;
	vector <int> pazymiai;
	double vidurkis, mediana, galutinis;
	int egzaminas;
	void pildymas();
	void autpildymas(string v,string p,int nd1,int nd2,int nd3,int nd4,int nd5,int egz);
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
	cout<<"Generuoti atsitiktinai pazymius? t?";
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

void Sduomenys::autpildymas(string v,string p,int nd1,int nd2,int nd3,int nd4,int nd5,int egz)
{
    pazymiai.clear();
    vardas=v;
    pavarde=p;
    pazymiai.push_back(nd1);
    pazymiai.push_back(nd2);
    pazymiai.push_back(nd3);
    pazymiai.push_back(nd4);
    pazymiai.push_back(nd5);
    egzaminas=egz;

    vidurkis = 0;
	vidurkis = double(nd1+nd2+nd3+nd4+nd5) / 5;
	galutinis=double(vidurkis*0.4+egzaminas*0.6);
}
void isvedimas()
{
    char vm='l';
    bool _med=false;

    cout<<"Pasirink vidukri/mediana  v/m:"<<endl;
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

bool pagalpavarde(const Sduomenys &p, const Sduomenys &pa)
{
    return p.pavarde<pa.pavarde;
}

bool pagalgalutini(const Sduomenys &p, const Sduomenys &pa)
{
    return p.galutinis<pa.galutinis;
}

void aisvedimas()
{
    sort(lentele.begin(),lentele.end(), pagalpavarde); //isrikiuojam pagal pavarde

    cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<right<<setw(20)<<"Galutinis(Vid.)"<<right<<setw(20)<<"Galutinis(vid+egz)"<<endl;
    cout<<"-"<<setfill('-')<<setw(69)<<"-"<<endl;
    cout<<setfill(' ');
    for (Sduomenys i : lentele) {
		cout <<left<<setw(15)<< i.vardas<<left<<setw(15)<<i.pavarde<<right<<setw(19)<< fixed<<setprecision(2)<<i.vidurkis<<right<<setw(20)<<fixed<< setprecision(2)
		<<i.galutinis<< endl;
	}
	cout<<"-"<<setfill('-')<<setw(69)<<"-"<<endl;
	cout<<setfill(' ');
}


#endif // DUOMENYS_H_INCLUDED
