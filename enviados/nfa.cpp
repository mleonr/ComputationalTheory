#include<iostream>
#include<vector>
#include<ctime>
#include<windows.h>

using namespace std;

void automata(string cad);
void rec1(vector<vector<string>>&arr);
void rec2(vector<vector<string>>&arr);
void lim_vec(vector<vector<string>>&arr,vector<string>&vec, string cad);

void opcion1();
void opcion2();

int main(){

	int n;
	string cad;

	srand(time(NULL));

	while(true){
		cout<<"1)Generar cadena"<<endl;
		cout<<"2)Generar cadena aleatoriamente"<<endl;
		cout<<"3)Salir"<<endl;
		cin>>n;
		//system("cls");
		switch(n){
			case 1:
				opcion1();
			break;
			case 2:
				opcion2();
			break;
			case 3:
				return 0;
			break;
			default: 
				cout<<"Opcion no valida"<<endl;
				break;
		}
	}
}


void opcion1(){
	cout<<"Ingresa cadena:"<<endl;
	string cadena;
	cin>>cadena;
	automata(cadena);
}

void opcion2(){
	
	int rnd1,rnd2;
	string cadena="";

	rnd1=rand()% 1000+2;
	
	cout<<"El tamaño de la cadena es: "<<rnd1<<endl;
	for(int j=0;j<rnd1;j++){
		rnd2=rand()%2;
		cadena+=to_string(rnd2);
	}
	cout<<cadena<<endl;
	automata(cadena);

}

void automata(string cad){
	
	string q0= "q0",q1= "q1",q2= "q2";

	vector<vector<string>>arr;
	vector<string>v_aux;

	lim_vec(arr,v_aux,q0);

	for(int i=0;i<cad.size();i++){
		if(cad[i]=='0'){
			rec1(arr);
		}else if(cad[i]=='1'){
			rec2(arr);
		}
	}

	v_aux=arr.back();
	if(v_aux.back()=="q2"){
		cout<<"	La cadena termina en 01"<<endl;
	}else{
		cout<<"La cadena no termina en 01"<<endl;
	}

}

void rec1(vector<vector<string>>&arr){

	string q0= "q0",q1= "q1",q2= "q2";
	vector<string>v_aux;
	
	for(int i=0;i<arr.size();i++){
		v_aux=arr[i];
		if(v_aux.back()==q0){
			v_aux.push_back(q0);
			arr[i]=v_aux;
		}else if(v_aux.back()==q1){
			arr.erase(arr.begin()+i); 
		}else if(v_aux.back()==q2){
			arr.erase(arr.begin()+i); 	
		}
	}
	lim_vec(arr,v_aux,q1);

}

void rec2(vector<vector<string>>&arr){

	string q0= "q0",q1= "q1",q2= "q2";
	vector<string>v_aux;
	
	for(int i=0;i<arr.size();i++){
		v_aux=arr[i];
		if(v_aux.back()==q0){
			v_aux.push_back(q0);
			arr[i]=v_aux;
		}else if(v_aux.back()==q1){
			v_aux.push_back(q2);
			arr[i]=v_aux;
		}else if(v_aux.back()==q2){
			arr.erase(arr.begin()+i); 	
		}
	}


}

void lim_vec(vector<vector<string>>&arr,vector<string>&vec, string cad){
	vec.clear();
	vec.push_back(cad);
	arr.push_back(vec);
	vec.clear();
}

