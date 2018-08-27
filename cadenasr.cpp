#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;


int main(){

	long cont,dig=1,frec,entrada,aux;
	string aux1="0",aux2="1",res;
	vector<string>vec;

	ofstream file;
	file.open("data.txt");

	cout<<"Potencia: ";
	cin>>entrada;

	if(entrada==0){
		cout<<"E={e}"<<endl;
		return 0;
	}

	vec.push_back(aux1);
	vec.push_back(aux2);

	cout<<"E={e,0,1,";

	file<<"Digitos #uno's"<<endl;
	file<<"1       1"<<endl;

	for(int m=0;m<entrada-1;m++){
		frec=0;
		aux=cont=vec.size();

		for(int i=0;i<aux;i++){
			vec.push_back(vec[i]+aux1);
			cout<<vec[vec.size()-1]<<",";
		}

		for(int j=0;j<aux;j++){
			vec.push_back(vec[j]+aux2);

			if(m==entrada-2 && j==aux-1)cout<<vec[vec.size()-1]<<"}";
			else cout<<vec[vec.size()-1]<<",";
			frec++;
		}

		vec.erase(vec.begin(),vec.begin()+cont);

		dig=(dig*2)+frec;
		file<<m+2<<"       "<<dig<<endl;
	}

	file.close();
	cout<<endl;
	return 0;
}


