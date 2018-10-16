#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector<vector<string>> Matriz;
typedef vector<string> Vectr;

void agregar_mov(string s,Vectr &v, Matriz &m);
void pieza(string s, Matriz &m);

int main(){

	string cad,aux;

	Matriz m1;
	Vectr v1;

	agregar_mov("2",v1,m1);

	cin>>cad;

	for(int i=0;i<cad.size();i++){
		aux=cad[i];
		pieza(aux,m1);
	}

	for(int i=0;i<m1.size();i++){
		v1=m1[i];
		for(int j=0;j<v1.size();j++){
			cout<<v1[j]<<" ";
		}
		cout<<" "<<endl;
	}

	return 0;	

}

void pieza(string s, Matriz &m){

	int tam;
	Vectr v,v_aux;

	tam=m.size();

	for(int i=0;i<tam;i++){
		
		v=m[i];
		
		if(v.back()=="2"){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					v_aux=v;
					if(j==0) v_aux.push_back("4");
					else if(j==1) v_aux.push_back("6");
					m.push_back(v_aux);
					v_aux.clear();
				}
			}
		}else if(v.back()=="4"||v.back()=="6"){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					v_aux=v;
					if(j==0) v_aux.push_back("2");
					else if(j==1) v_aux.push_back("8");
					m.push_back(v_aux);
					v_aux.clear();
				}
			}
		}else if(v.back()=="6"){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					v_aux=v;
					if(j==0) v_aux.push_back("2");
					else if(j==1) v_aux.push_back("8");
					m.push_back(v_aux);
					v_aux.clear();
				}
			}
		}else if(v.back()=="8"){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					v_aux=v;
					if(j==0) v_aux.push_back("4");
					else if(j==1) v_aux.push_back("6");
					m.push_back(v_aux);
					v_aux.clear();
				}
			}
		}

	}

	m.erase(m.begin(),m.begin()+tam);

}



void agregar_mov(string s, Vectr &v, Matriz &m){
	v.clear();
	v.push_back(s);
	m.push_back(v);
	v.clear();
}

