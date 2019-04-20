#include "Headeris.h"
#include "Duomenys.h"

bool nuskaitytifaila()
{
    ifstream is("klasiokai.txt");
    string lin, vard, pav;
    int nd1,nd2,nd3,nd4,nd5,egz;

    Sduomenys Sd_temp1;

    if (is.fail())
    {
         cout<<"Neatidare failo klasiokai.txt"<<endl;
         return false;
    }

    while (getline(is,lin))
    {
        is>>vard>>pav>>nd1>>nd2>>nd3>>nd4>>nd5>>egz;
        Sd_temp1.autpildymas(vard,pav,nd1,nd2,nd3,nd4,nd5,egz);
        lentele.push_back(Sd_temp1);
    }
    is.close();
    return true;
}
void pasirinkimas()
{
    char k;
    Sduomenys Sd_temp;  char kr;
    cout<<"Pildysim ranka ar nuskaitysim failus? r-ranka; is failo-betkuris kitas"<<endl;
	cin>>k;
	switch (k)
	{
    case ('R','r'):

	do {
		Sd_temp.pildymas();
		lentele.push_back(Sd_temp);

		cout << "Kitas irasas? t/n: "<<endl;
		cin >> kr;
	} while (kr == 't' || kr == 'T');
	isvedimas();
        break;
    default:
        nuskaitytifaila();
        aisvedimas();
        break;
	}
}

int main()
{
    pasirinkimas();
    system("pause");
}
