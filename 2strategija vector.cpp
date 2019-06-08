////////Modifikacija////////////

///////Tik Automatinis generavimas automatiskai, be inputs//////////
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <list>
#include <deque>

using namespace std;

string fpav[7]= {"desimt.txt","simtas.txt","stuka.txt","10k.txt","100k.txt","Tinginiai.txt","Grauzikai.txt"};


struct Sduomenys {
	string vardas, pavarde;
	vector <int> pazymiai;
	double vidurkis, mediana, galutinis;
	int egzaminas;
	void autpildymas(string v,string p,int nd1,int nd2,int nd3,int nd4,int nd5,int egz);
};

vector <Sduomenys> lentele;
vector <Sduomenys> tinginiai;
vector <Sduomenys> grauzikai;

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

bool pagalgalutini(const Sduomenys &p, const Sduomenys &pa) // vektoriui ir deque
{
    return p.galutinis<pa.galutinis;
}



////////////////overloadinti? arba apsitvarkyti
void nfaila()
{
    ifstream is;
    string lin, vard, pav;
    int nd1,nd2,nd3,nd4,nd5,egz;

    Sduomenys Sd_temp1;

    for (int i=0; i<5; i++) //100k nekeliam
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

void nfailus()
{
    ofstream ps,pp;
    double glaikas[7] {0,0,0,0,0,0,0};

//nuskaitymas//
    auto tp= chrono::steady_clock::now();
    nfaila();
    auto tf= chrono::steady_clock::now();
    auto ls= tf-tp;
    glaikas[5]=chrono::duration<double, milli> (ls).count();
    cout<<"Laikas kol nuskaite visus failus: "<<glaikas[5]<<" ms"<<endl;
//rusiavimas eiles seka
    auto ttp= chrono::steady_clock::now();
    sort(lentele.begin(),lentele.end(), pagalgalutini); // isruosiuoja nuo maziausio iki didziausio
    auto ttf= chrono::steady_clock::now();
    auto lls= ttf-ttp;
    glaikas[1]=chrono::duration<double, milli> (lls).count();
    cout<<"Laikas kol surusiavo duomenis pagal galutini pazymi didejanciai: "<<glaikas[1]<<" ms"<<endl;
//skaidymas i tinginius ir grauzikus
    cout<<"2 strategija"<< endl;
    auto tpp= chrono::steady_clock::now();
//int z=0;
    for (int i=0; i<lentele.size(); i++)
    {
        if (lentele[i].galutinis<5)//(i.galutinis<5)
        {
           tinginiai.push_back(lentele[i]);
           lentele.erase(lentele.begin()+i);
          // cout<<"Trina "<<z<<endl;
        }
       // z++;
	}

    auto tfp= chrono::steady_clock::now();
    auto lsp= tfp-tpp;
    glaikas[6]=chrono::duration<double, milli> (lsp).count();
    cout<<"Laikas skaidant i tinginius ir grauzikus: "<<glaikas[6]<<" ms"<<endl;
//isvedimas i tinginiu ir grauziku failus
auto btpp= chrono::steady_clock::now();
ps.open(fpav[5]);
pp.open(fpav[6]);
for (Sduomenys i : tinginiai)
{
     ps <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.pazymiai[0]<<setw(5)<<i.pazymiai[1]<<setw(5)<<i.pazymiai[2]<<setw(5)<<i.pazymiai[3]<<setw(5)<<i.pazymiai[4]<<setw(5)<<i.egzaminas<<setw(5)<<i.galutinis<<endl;
}
for (Sduomenys i : lentele)
{
     pp <<i.vardas<<setw(15)<<i.pavarde<<setw(10)<<i.pazymiai[0]<<setw(5)<<i.pazymiai[1]<<setw(5)<<i.pazymiai[2]<<setw(5)<<i.pazymiai[3]<<setw(5)<<i.pazymiai[4]<<setw(5)<<i.egzaminas<<setw(5)<<i.galutinis<<endl;
}
ps.close();
pp.close();
auto btfp= chrono::steady_clock::now();
auto blsp= btfp-btpp;
glaikas[3]=chrono::duration<double, milli> (blsp).count();
cout<<"Laikas isvedinejant i tinginiu ir grauziku failus: "<<glaikas[3]<<" ms"<<endl;

}

int main()
{
    cout<<"------------VEKTORIAI---------"<<endl;
    nfailus();

    system("pause");
}
