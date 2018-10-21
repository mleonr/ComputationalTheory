#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdio>

using namespace std;

void f(string s,int num);
string mov_rndom(int n);
void pieza(string s, int num);
void limpiar_archivos();
void seleccion_archivos();

void Ini_doc(string s);
int tam_archivo(string archivo);
void agregar_archivo(string line, string archivo);
void eliminar_contenido(string archivo, int tam);


int main(){

	int opc,rnd;
	string c1,c2,s_rnd;

	srand(time(NULL));

	limpiar_archivos();

	Ini_doc("1");
	Ini_doc("2");


	cout<<"1)Generar cadenas aleatoriamente"<<endl;
	cout<<"2)Generar cadenas manualmente"<<endl;
	cin>>opc;

	switch(opc){
		case 1:		
			rnd = rand() % 1000 + 1; 
			c1 = mov_rndom(rnd);
			cout<<"Cadena generada 1:"<<c1<<endl;
			f(c1,1);
			
			c2 = mov_rndom(rnd);
			cout<<"Cadena generada 2:"<<c2<<endl;
			f(c2,2);
			
		break;
		case 2:
			cout<<"Camino pieza 1: "<<endl;
			cin>>c1;
			f(c1,1);


			cout<<"Camino pieza 2: "<<endl;
			cin>>c2;
			f(c2,2);
		break;
		default:
			cout<<"Opcion no valida"<<endl;
		break;
	}

	seleccion_archivos();

	return 0;
	
}

void Ini_doc(string s){

	ofstream file1;

	if(s.compare("1")==0) file1.open("pieza1_a.txt");
	else file1.open("pieza2_a.txt");
	
	file1<<s<<endl;
	
	file1.close();
}

void limpiar_archivos(){
	int n;
	n=remove("pieza1_a.txt");
	n=remove("pieza1_b.txt");
	n=remove("pieza2_a.txt");
	n=remove("pieza2_b.txt");
}

string mov_rndom(int n){
	
	int rnd;
	string cad="";

	for(int i=0;i<n;i++){
		rnd=rand()%2;
		if(rnd) cad+="r";
		else cad+="b";
	}
	return cad;
}

void f(string s, int num){

	string aux;
 
	for(int i=0;i<s.size();i++){
		aux=s[i];
		pieza(aux,num);
	}
}

int tam_archivo(string archivo){
	
	int cont=0;
	string line ="", ans="";

	ifstream file;
	file.open(archivo);

	if(file.is_open()){
		while(getline(file,line)){
			cont++;
		}
	}else{
		return 0;
	}

	file.close();

	return cont;
}

void agregar_archivo(string line, string archivo){

	ofstream file;

	file.open(archivo,ios_base::app);
  	file<<line<<endl; 
	file.close();
}


void pieza(string s, int num){

	int tam,n;
	string line,line_aux,archivo_lec,archivo_esc;
	ifstream if_file;


	if(num==1){
		if(tam_archivo("pieza1_b.txt")==0) {
			archivo_lec = "pieza1_a.txt";
			archivo_esc = "pieza1_b.txt";
		}else{
			archivo_lec= "pieza1_b.txt";	
			archivo_esc ="pieza1_a.txt";
		} 
	}else if(num==2){
		if(tam_archivo("pieza2_b.txt")==0) {
			archivo_lec = "pieza2_a.txt";
			archivo_esc = "pieza2_b.txt";
		}else{
			archivo_lec= "pieza2_b.txt";	
			archivo_esc ="pieza2_a.txt";
		} 
	}

	if_file.open(archivo_lec);

	while(getline(if_file,line)){

		if(line.back()=='1'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 2";
					else line_aux+=" 4";
					
					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+=" 5";
				agregar_archivo(line_aux,archivo_esc);
			}
		}else if(line.back()=='2'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 4";
					else line_aux+=" 6";
					
					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+=" 1";
					else if(j==1) line_aux+=" 3";
					else if(j==2) line_aux+=" 5";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line.back()=='3'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 2";
					else line_aux+=" 6";

					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+=" 5";

				agregar_archivo(line_aux,archivo_esc);
			}
		}else if(line.back()=='4'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 2";
					else if(j==1) line_aux+=" 8";

					agregar_archivo(line_aux,archivo_esc);		
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+=" 1";
					else if(j==1) line_aux+=" 5";
					else if(j==2) line_aux+=" 7";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line.back()=='5'){
			if(s.compare("r")==0){
				for(int j=0;j<4;j++){
					line_aux=line;
					if(j==0) line_aux+=" 2";
					else if(j==1) line_aux+=" 4";
					else if(j==2) line_aux+=" 6";
					else if(j==3) line_aux+=" 8";

					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<4;j++){
					line_aux=line;
					if(j==0) line_aux+=" 1";
					else if(j==1) line_aux+=" 3";
					else if(j==2) line_aux+=" 7";
					else if(j==3) line_aux+=" 9";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line.back()=='6'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 2";
					else line_aux+=" 8";
					
					agregar_archivo(line_aux,archivo_esc);	
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+=" 3";
					else if(j==1) line_aux+=" 5";
					else if(j==2) line_aux+=" 9";

					agregar_archivo(line_aux,archivo_esc);	
				}
			}
		}else if(line.back()=='7'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 4";
					else line_aux+=" 8";

					agregar_archivo(line_aux,archivo_esc);		
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+=" 5";
				
				agregar_archivo(line_aux,archivo_esc);					
			}
		}else if(line.back()=='8'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 4";
					else line_aux+=" 6";
						
					agregar_archivo(line_aux,archivo_esc);	
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+=" 5";
					else if(j==1) line_aux+=" 7";
					else if(j==2) line_aux+=" 9";

					agregar_archivo(line_aux,archivo_esc);	
				}
			}
		}else if(line.back()=='9'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+=" 6";
					else line_aux+=" 8";

					agregar_archivo(line_aux,archivo_esc);			
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+=" 5";

				agregar_archivo(line_aux,archivo_esc);		
			}	
		}
		
	}
	
	if_file.close();
	
	 
	if(archivo_lec=="pieza1_a.txt") n = remove("pieza1_a.txt");
	else if(archivo_lec=="pieza1_b.txt") n = remove("pieza1_b.txt");
	else if(archivo_lec=="pieza2_a.txt") n =remove("pieza2_a.txt");
	else if(archivo_lec=="pieza2_b.txt") n = remove("pieza2_b.txt");
    
}

void seleccion_archivos(){
	
	string final1, final2,line;
	ifstream if_file;
	ofstream of_file;

	if(tam_archivo("pieza1_a.txt")==0) final1="pieza1_b.txt";
	else final1="pieza1_a.txt";

	if(tam_archivo("pieza2_a.txt")==0) final2="pieza2_b.txt";
	else final2="pieza2_a.txt";


	if_file.open(final1);
	of_file.open("jganadorasP1.txt");
	while(getline(if_file,line)){
		if(line.back()=='9' && line[2]!='2')
			of_file<<line<<endl;
		
	}
	of_file.close();
	if_file.close();

	if_file.open(final2);
	of_file.open("jganadorasP2.txt");
	while(getline(if_file,line)){
		if(line.back()=='8' && line[2]!='1')
			of_file<<line<<endl;
		
	}
	of_file.close();
	if_file.close();
}








