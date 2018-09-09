#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<windows.h>
using namespace std;

void GenCadenas(string arr[100]);
void Clasificador(string arr[100],ofstream &file);
string Automata(string cadena);
void Insertdoc(string cadena,ofstream &file);

int main(){

	string arr[100];
	ofstream file;

	int rnd,cont=0;

	srand(time(NULL));

	while(true){
		rnd=rand()%2;
		if(rnd){
			cout<<"Estado: Activo "<<++cont<<endl;
			GenCadenas(arr);
			Clasificador(arr,file);
		}else{
			cout<<"Apagado."<<endl;
			break;
		}
	}
	return 0;
}

void GenCadenas(string arr[100]){
	
	int rnd;
	char c;
	string aux;
	
	for(int i=0;i<100;i++){
		
		aux="";

		for(int j=0;j<100000;j++){
			rnd=rand()%2 +48;
			c=(char)rnd;
			aux+=c;
		}
		arr[i]=aux;
	}
}

void Clasificador(string arr[100],ofstream &file){
	string ans="";
	for(int i=0;i<100;i++){
		ans= Automata(arr[i]);
		if(ans=="p0"){
			Insertdoc(arr[i],file);
		}
	}

	Sleep(2000);
}

string Automata(string cadena){

		string estados="p0";

		for(int i=0;i<cadena.size();i++){
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
return estados;
}

void Insertdoc(string cadena,ofstream &file){

	file.open("cadpares.txt",ios_base::app);
  	file << cadena<<endl; 
	file.close();
}