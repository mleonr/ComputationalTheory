#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<windows.h>
using namespace std;

void GenCadenas(ofstream &file);
void Clasificador(ofstream &file);
string Automata(string cadena);
void Insertdoc(string cadena,ofstream &file);

int main(){

	ofstream file1,file2;

	int rnd,cont=0;

	srand(time(NULL));

	while(true){
		rnd=rand()%2;
		if(rnd){
			cout<<"Estado: Activo "<<++cont<<endl;
			GenCadenas(file1);
			Clasificador(file2);
		}else{
			cout<<"Apagado."<<endl;
			break;
		}
	}
	return 0;
}

void GenCadenas(ofstream &file){
	
	int rnd;
	char c;
		
	file.open("cad_aleatorias.txt");

	for(int i=0;i<100;i++){
		
		for(int j=0;j<100;j++){
			rnd=rand()%2 +48;
			c=(char)rnd;
			file<<c;
		}
		file<<endl;
	}
	file.close();
}

void Clasificador(ofstream &file){
	
	string line ="", ans="";
	
	ifstream file1("cad_aleatorias.txt");

	if(file1.is_open()){
		while(getline(file1,line)){
			ans= Automata(line);
			if(ans=="p0"){
				Insertdoc(line,file);
			}
		}
	}

	file1.close();
	remove( "cad_aleatorias.txt" );
	Sleep(2000);
}

string Automata(string cadena){

		string estados="p0";
		cout<<"Estado del Automata"<<endl;
		for(int i=0;i<cadena.size();i++){
			cout<<estados<<"-";
			if(estados=="p0"){
				if(cadena[i]=='0') estados="p1";
				else estados="p3";
			}else if(estados=="p1"){
				if(cadena[i]=='0') estados="p0";
				else estados="p2";
			}else if(estados=="p2"){
				if(cadena[i]=='0') estados="p3";
				else estados="p1";
			}else if(estados=="p3"){
				if(cadena[i]=='0') estados="p2";
				else estados="p0";
			}
		}
		cout<<endl;
return estados;
}

void Insertdoc(string cadena,ofstream &file){

	file.open("cadpares.txt",ios_base::app);
  	file << cadena<<endl; 
	file.close();
}
