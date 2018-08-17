#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){

	long cont=0,entrada,aux;
	string aux1="0",aux2="1";
	vector<string>vec;

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
			cout<<vec[vec.size()-1]<<",";
		}

		for(int j=0;j<aux;j++){
			vec.push_back(vec[j]+aux2);
			
			if(m==entrada-2 && j==aux-1)cout<<vec[vec.size()-1]<<"}";
			else cout<<vec[vec.size()-1]<<",";
			
		}

		vec.erase(vec.begin(),vec.begin()+cont);
	}

	cout<<endl;
	return 0;
}
