/*Create the furniture class, which contains information about price, style and field of use (office, kitchen and other furniture).
Dynamic memory should be used for setting text fields.
Define the derived classes table and chair. Define the constructors, destructor, assignment operators and other necessary functions.*/

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class Furniture{
	float price;
	char* style;
	char* du;//field of use
public:
	Furniture(){
		price = 0;
		style = new char[6];
		strcpy(style, "Empty");
		du = new char[6];
		strcpy(du, "Empty");
	}

	Furniture (float p, char* st, char* d){
		price = p;
		style = new char[strlen(st)+1];
		strcpy(style, st);
		du = new char[strlen(d)+1];
		strcpy(du, d);
	}

	~Furniture(){
		if (style)
			delete[]style;
		if (du)
			delete[]du;
	}

	void show(){
		cout<<"\n price : "<<price<<",\n style : "<<style<<",\n field of use : "<< du <<endl;
	}

//	void assign(const Furniture &right){
	void operator = (const Furniture &right){
		price = right.price;
		if(style)
			delete[]style;
		style = new char[strlen(right.style)+1];
		strcpy(style, right.style);
		if(du)
			delete[]du;
		du = new char[strlen(right.du)+1];
		strcpy(du, right.du);
	}
};

class Table:public Furniture{
	char* color;
public:
	Table():Furniture(){
		color = new char[6];
		strcpy(color, "Empty");
	}

	Table(float p, char* st, char* d, char* col):Furniture(p, st, d){
		color = new char[strlen(col)+1];
		strcpy(color, col);
	}

	~Table(){
		if(color)
			delete[]color;
	}

	void show_Table(){
		cout<<"\n Table has color: "<<color<<", ";
		show();
	}

	void operator=(const Table & right){
		//Furniture m = right;
		//*this = (Table)m;
		if(color)
			delete[]color;
		color = new char[strlen(right.color)+1];
		strcpy(color, right.color);
		//*this = right;
		Furniture::operator=(right);
	}
};

class Chair:public Furniture{
	char* confort;
public:
	Chair():Furniture(){
		confort = new char[6];
		strcpy(confort, "Empty");
	}

	Chair(float p, char* st, char* d, char* con):Furniture(p, st, d){
		confort = new char[strlen(con)+1];
		strcpy(confort, con);
	}

	~Chair(){
		if(confort)
			delete[]confort;
	}

	void show_Chair(){
		cout<<"\n Chair with confort : "<<confort<<", ";
		this->show();
	}

	void operator=(const Chair & right){
		//Furniture m= right;
		//(Furniture)(*this) (Furniture) = right;

		if(confort)
			delete[]confort;
		confort = new char[strlen(right.confort)+1];
		strcpy(confort, right.confort);
		//this->atribuire(right);
		Furniture::operator= (right);
	}
};

//-----------------------------------------------------------------------------------------

int main(){
	Table obj_Table(23.1, "square", "kitchen", "black");
	Chair obj_Chair(12, "gamer", "room", "maxim");
	obj_Table.show_Table();
	obj_Chair.show_Chair();
	Table obj_Table2(11, "ww", "ww", "ww");
	obj_Table2 = obj_Table;
	obj_Table2.show_Table();
	Chair obj_Chair2(1, "w", "w", "w");
	obj_Chair2 = obj_Chair;
	obj_Chair2.show_Chair();
	return 0;
}
