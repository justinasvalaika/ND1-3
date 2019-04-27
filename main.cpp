#include "Headeris.h"
#include "Duomenys.h"
#include <chrono>

string fpav[7]= {"desimt.txt","simtas.txt","stuka.txt","10k.txt","100k.txt","Tinginiai.txt","Grauzikai.txt"};

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
void nfaila()
{
    ifstream is;
    string lin, vard, pav;
    int nd1,nd2,nd3,nd4,nd5,egz;

    Sduomenys Sd_temp1;

    for (int i=0; i<5; i++)
    {
        is.open(fpav[i]);
        while (getline(is,lin))
    {
        is>>vard>>pav>>nd1>>nd2>>nd3>>nd4>>nd5>>egz;
        Sd_temp1.autpildymas(vard,pav,nd1,nd2,nd3,nd4,nd5,egz);
        lentele.push_back(Sd_temp1);
    }
    is.close();
    }


}

////////////overload???

void irasas(int sar,int nr, ofstream& failas)
{
    failas <<sar<<"vardas"<<nr<<setw(15)<<sar<<"Pav"<<nr<<setw(10)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<setw(5)<<rand()%10+1<<endl;
}


void gfailus()
{

    ofstream ps,pp;
    int kiek[5] {10,100,1000,10000,100000};
    cout<<"Generuojami studentu sarasai: "<<endl;
    double glaikas[7] {0,0,0,0,0,0,0};

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

    auto tp= chrono::steady_clock::now();
    nfaila();
    auto tf= chrono::steady_clock::now();
    auto ls= tf-tp;
    glaikas[5]=chrono::duration<double, milli> (ls).count();
    cout<<"Laikas kol nuskaite visus failus: "<<glaikas[5]<<" ms"<<endl;


    sort(lentele.begin(),lentele.end(), pagalgalutini); // isruosiuoja nuo maziausio iki didziausio

    auto tpp= chrono::steady_clock::now();

    ps.open(fpav[5]);
    pp.open(fpav[6]);
    for (Sduomenys i : lentele)
    {
        if (i.galutinis<5)
        {
            ps <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.pazymiai[0]<<setw(5)<<i.pazymiai[1]<<setw(5)<<i.pazymiai[2]<<setw(5)<<i.pazymiai[3]<<setw(5)<<i.pazymiai[4]<<setw(5)<<i.egzaminas<<setw(5)<<i.galutinis<<endl;
        }
        else
        {
            pp <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.pazymiai[0]<<setw(5)<<i.pazymiai[1]<<setw(5)<<i.pazymiai[2]<<setw(5)<<i.pazymiai[3]<<setw(5)<<i.pazymiai[4]<<setw(5)<<i.egzaminas<<setw(5)<<i.galutinis<<endl;
        }

	}
	ps.close();
	pp.close();

    auto tfp= chrono::steady_clock::now();
    auto lsp= tfp-tpp;
    glaikas[6]=chrono::duration<double, milli> (lsp).count();
    cout<<"Laikas kol suegeneravo tinginiu ir grauziku failus: "<<glaikas[6]<<" ms"<<endl;

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
