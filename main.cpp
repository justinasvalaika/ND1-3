#include "Headeris.h"
#include "Duomenys.h"
#include <chrono>

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

////////////////overload????
bool nfaila()
{
    ifstream is("desimt.txt");
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

////////////overload???

void irasas(int sar,int nr, ofstream& failas)
{
    failas <<sar<<"vardas"<<nr<<setw(15)<<sar<<"Pav"<<nr<<setw(10)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<endl;
}

void gfailus()
{
    string fpav[5]= {"desimt.txt","simtas.txt","stuka.txt","10k.txt","100k.txt"};
    ofstream ps;
    int kiek[5] {10,100,1000,10000,100000};
    cout<<"Generuojami studentu sarasai: "<<endl;
    double glaikas[5] {0,0,0,0,0};

for (int l=0; l<5; l++)
{
    ps.open(fpav[l]);
    auto tp= chrono::steady_clock::now(); //pr laikas
    for (int i=0; i<kiek[l]; i++)
    {
        irasas(l,i,ps);
    }
    ps.close();
    auto tf= chrono::steady_clock::now();
    auto ls= tf-tp;
    glaikas[l]=chrono::duration<double, milli> (ls).count();

}
for (int f=0;f<5;f++)
    {
        cout<<"Laikas kol sugeneravo "<<fpav[f]<<" faila: "<<glaikas[f]<<" ms"<< endl;
    }

    nfaila();
    //sugrupuoti pagal galutini tiesiog if else?:
    aisvedimas(); // aisvedimas i faila


}

void pasirinkimas()
{
    char k;
    Sduomenys Sd_temp;  char kr;
    cout<<"Pildysim ranka ar nuskaitysim failus? r-ranka; g-generuoti automatiškai sarasus; is failo-betkuris kitas"<<endl;
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
    case ('G','g'):
        gfailus();
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
