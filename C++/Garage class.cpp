/*Create the garage class, which contains the surface. Determine constructors and accessors.
Create the house class, which contains rooms, a kitchen (its surface) and garage.
Define the villa derived class (as an additional parameter – the size of the plot of land). Determine the constructors, destructor, and output stream.*/

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;


class Garage{
	float surface;
public:
	Garage(){
		surface = 0;
	}

	Garage(float sup){
		surface = sup;
	}

	void show_Garage(){
		cout<<"surface Garageului : "<<surface<<endl;
	}

	void set_Garage(float sup){
		surface = sup;
	}

};

class Home{
	int rooms;
	float kitchen_surface;
	Garage Garage;
public:
	Home(){
		rooms = 0;
		kitchen_surface = 0;
	}

	Home(int od, float sup_buc, float sup_gar){
		rooms = od;
		kitchen_surface = sup_buc;
		Garage.set_Garage(sup_gar);
	}

	void show(){
		cout<<"No. of rooms: "<<rooms<<"\nkitchen surface : "<<kitchen_surface<<endl;
		Garage.show_Garage();
	}
};

class Villa:public Home{
	float lot_size;
public:
	Villa(){
		lot_size = 0;
	}

	Villa(int od, float sup_buc, float sup_gar,float l):Home(od, sup_buc, sup_gar){
		lot_size = l;
	}

	void show_Villa(){
		this->show();
		cout<<"The size of the plot of land : "<<lot_size<<endl;
	}
};
int main(){
    cout<<"\nThe parameters of the my_home object : "<<endl;
	Home my_home(3, 25.2, 30.4);
	my_home.show();

	cout<<"\nParameters of the my_vill object"<<endl;
	Villa my_vill(10, 30, 45, 200);
	my_vill.show_Villa();
	return 0;
}
