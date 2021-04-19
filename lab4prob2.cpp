#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


class Garaj{
	float suprafata;
public:
	Garaj(){
		suprafata = 0;
	}

	Garaj(float sup){
		suprafata = sup;
	}

	void show_garaj(){
		cout<<"Suprafata garajului : "<<suprafata<<endl;
	}

	void set_garaj(float sup){
		suprafata = sup;
	}

};

class Casa{
	int odai;
	float suprafata_bucatariei;
	Garaj garaj;
public:
	Casa(){
		odai = 0;
		suprafata_bucatariei = 0;
	}

	Casa(int od, float sup_buc, float sup_gar){
		odai = od;
		suprafata_bucatariei = sup_buc;
		garaj.set_garaj(sup_gar);
	}

	void show(){
		cout<<"Nr de odai : "<<odai<<"\nSuprafata bucatariei : "<<suprafata_bucatariei<<endl;
		garaj.show_garaj();
	}
};

class Vila:public Casa{
	float marimea_lotului;
public:
	Vila(){
		marimea_lotului = 0;
	}

	Vila(int od, float sup_buc, float sup_gar,float l):Casa(od, sup_buc, sup_gar){
		marimea_lotului = l;
	}

	void show_vila(){
		this->show();
		cout<<"Marimea lotului de pamant : "<<marimea_lotului<<endl;
	}
};
int main(){
    cout<<"\nParametrii obiectului my_home : "<<endl;
	Casa my_home(3, 25.2, 30.4);
	my_home.show();

	cout<<"\nParametrii obiectului my_vill"<<endl;
	Vila my_vill(10, 30, 45, 200);
	my_vill.show_vila();
	return 0;
}
