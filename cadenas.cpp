#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void CrearDoc(ofstream &file);
void CerrarDoc(ofstream &file);
void Frecuencia1(string cad,ofstream &file);

int main(){

	long cont,entrada,aux;
	string aux1="0",aux2="1",res;
	vector<string>vec;
	
	ofstream file;
	
	CrearDoc(file);
	
	cout<<"Potencia: ";
	cin>>entrada;

	if(entrada==0){
		cout<<"E={e}"<<endl;
		return 0;
	}

	vec.push_back(aux1);
	vec.push_back(aux2);

	cout<<"E={e,0,1,";
	
	for(int m=0;m<entrada-1;m++){
		aux=cont=vec.size();

		for(int i=0;i<aux;i++){
			vec.push_back(vec[i]+aux1);
			Frecuencia1(vec[vec.size()-1],file);
			cout<<vec[vec.size()-1]<<",";
		}

		for(int j=0;j<aux;j++){
			vec.push_back(vec[j]+aux2);
			Frecuencia1(vec[vec.size()-1],file);
			if(m==entrada-2 && j==aux-1)cout<<vec[vec.size()-1]<<"}";
			else cout<<vec[vec.size()-1]<<",";
			
		}

		vec.erase(vec.begin(),vec.begin()+cont);

	}

	CerrarDoc(file);
	cout<<endl;
	return 0;
}

void CrearDoc(ofstream &file){
	file.open("frecuencia.txt");
	
	//file<<"# de uno's por cadena"<<endl;
	file<<"0"<<endl;
	file<<"1"<<endl;
	
	return;
}

void CerrarDoc(ofstream &file){
	file.close();
	return;
}	

void Frecuencia1(string cad,ofstream &file){
	int cont=0;
	
	for(int i=0;i<cad.size();i++)
		if(cad[i]=='1')cont++;
	
	file<<cont<<endl;
	return;
}


