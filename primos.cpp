#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<string>


using namespace std;

void Lectura(ofstream &file2,ofstream &file3);
void Convertidor(string cad,ofstream &file2,ofstream &file3);
int main(){

	unsigned long long int i,r,aux=0,paso,cont=0;
	bool ban=true;
	vector<unsigned long long int>vec;
	
	ofstream file1,file2,file3;
	file1.open("nprimos.txt");
	file2.open("binario.txt");
	file3.open("frecprim.txt");
	
	cout<<"Rango que deseas conocer:"<<endl;
	cin>>r;
	
	for(i=2;i<=r;i++) 
		vec.push_back(i);
	
	while(ban){	
	
		for(i=0;i<vec.size();i++){
			if(vec[i]!=0){ 
				file1<<vec[i]<<endl;
				aux=i;
				paso=vec[i];
				break;
			}
			if(i==(vec.size()-1))
				ban=false;
		}
		
		for(i=aux;i<vec.size();i+=paso)
			vec[i]=0;
		
	}	
	
	file1.close();
	
	Lectura(file2,file3);

	file2.close();

return 0;
}

void Lectura(ofstream &file2,ofstream &file3){
	
	string line;
	
	ifstream file1("nprimos.txt");
  
	if(file1.is_open()){
    while(getline(file1,line))
		Convertidor(line,file2,file3);
	}
    file1.close();
 
}

void Convertidor(string cadena,ofstream &file2,ofstream &file3){
	
	unsigned long long int dividendo,i,num,cont=0;
	vector<unsigned long long int >arr;

	
	num=dividendo = stoi(cadena);
	
	while(dividendo>=2){
		arr.push_back(dividendo%2);
		dividendo/=2;
	}
	arr.push_back(1);
	file2<<num<<"       ";
	for(i=(arr.size()-1);i<-1;i--){
		file2<<arr[i];
		if(arr[i]==1)cont++;
	}
	file2<<endl;
	file3<<cont<<endl;
	
}

