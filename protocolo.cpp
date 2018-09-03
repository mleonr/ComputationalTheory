#include<iostream>
#include<string>
using namespace std;

void Automata(string cadena);

int main(){

	string cadena;
	cin>>cadena;

	Automata(cadena);

	return 0;
}

void Automata(string cadena){

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
		
		if(estados=="p0")cout<<"par";
		else cout<<"no par";

}