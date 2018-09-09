#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
int main(){
	
	int cont=0;
	string line;
	vector<string>vec;
	ofstream file;
	
	ifstream file1("cadpares.txt");

	if(file1.is_open())
		while(getline(file1,line))
			vec.push_back(line);

	file1.close();

	
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec.size();j++){
			if(i!=j){
				if(vec[i].compare(vec[j])==0){
					cout<<"coincidencia"<<endl;
					return 0;
				}
			}
		}
	}



	return 0;
}
