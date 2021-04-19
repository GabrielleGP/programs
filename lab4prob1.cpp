/*Să se creeze clasa mobilă, care conţine informaţie despre preţ, stil şi domeniul de utilizare (oficiu, bucătărie şi altă mobilă). 
Pentru setarea câmpurilor textuale să se folosească memoria dinamică. 
Definiţi clasele derivate masa şi scaun. Definiţi constructorii, destructorul, operatorii de atribuire şi alte funcţii necesare.*/

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Mobila{
	float pret;
	char* stil;
	char* du;//domeniul de utilizare
public:
	Mobila(){
		pret = 0;
		stil = new char[6];
		strcpy(stil, "Empty");
		du = new char[6];
		strcpy(du, "Empty");
	}

	Mobila (float p, char* st, char* d){
		pret = p;
		stil = new char[strlen(st)+1];
		strcpy(stil, st);
		du = new char[strlen(d)+1];
		strcpy(du, d);
	}

	~Mobila(){
		if (stil)
			delete[]stil;
		if (du)
			delete[]du;
	}

	void show(){
		cout<<"\n pretul : "<<pret<<",\n stil : "<<stil<<",\n domeniul de utilizare : "<< du <<endl;
	}

//	void atribuire(const Mobila &right){
	void operator = (const Mobila &right){
		pret = right.pret;
		if(stil)
			delete[]stil;
		stil = new char[strlen(right.stil)+1];
		strcpy(stil, right.stil);
		if(du)
			delete[]du;
		du = new char[strlen(right.du)+1];
		strcpy(du, right.du);
	}
};

class Masa:public Mobila{
	char* culoare;
public:
	Masa():Mobila(){
		culoare = new char[6];
		strcpy(culoare, "Empty");
	}

	Masa(float p, char* st, char* d, char* col):Mobila(p, st, d){
		culoare = new char[strlen(col)+1];
		strcpy(culoare, col);
	}

	~Masa(){
		if(culoare)
			delete[]culoare;
	}

	void show_masa(){
		cout<<"\n Masa are culoarea: "<<culoare<<", ";
		show();
	}

	void operator=(const Masa & right){
		//Mobila m = right;
		//*this = (Masa)m;
		if(culoare)
			delete[]culoare;
		culoare = new char[strlen(right.culoare)+1];
		strcpy(culoare, right.culoare);
		//*this = right;
		Mobila::operator=(right);
	}
};

class Scaun:public Mobila{
	char* confort;
public:
	Scaun():Mobila(){
		confort = new char[6];
		strcpy(confort, "Empty");
	}

	Scaun(float p, char* st, char* d, char* con):Mobila(p, st, d){
		confort = new char[strlen(con)+1];
		strcpy(confort, con);
	}

	~Scaun(){
		if(confort)
			delete[]confort;
	}

	void show_scaun(){
		cout<<"\n Scaunul cu confortul : "<<confort<<", ";
		this->show();
	}

	void operator=(const Scaun & right){
		//Mobila m= right;
		//(Mobila)(*this) (Mobila) = right;

		if(confort)
			delete[]confort;
		confort = new char[strlen(right.confort)+1];
		strcpy(confort, right.confort);
		//this->atribuire(right);
		Mobila::operator= (right);
	}
};

//-----------------------------------------------------------------------------------------

int main(){
	Masa obj_masa(23.1, "patrate", "bucatarie", "negru");
	Scaun obj_scaun(12, "gamer", "Camera", "maxim");
	obj_masa.show_masa();
	obj_scaun.show_scaun();
	Masa obj_masa2(11, "ww", "ww", "ww");
	obj_masa2 = obj_masa;
	obj_masa2.show_masa();
	Scaun obj_scaun2(1, "w", "w", "w");
	obj_scaun2 = obj_scaun;
	obj_scaun2.show_scaun();
	return 0;
}
