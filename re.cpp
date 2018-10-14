#include<iostream>
#include<ctime>
#include<string>
#include<stdlib.h>
#include<fstream> 

using namespace std;

void Insertdoc(string cadena,ofstream &file,string fnom);
int main(){
	
	int rnd,rnd1,rnd2;
	char c;
	string s="";

	ofstream file1,file2,file3;

	srand(time(NULL));

	cout<<"Presiona enter para iniciar";
	c=getchar();
	
	for(int i=0;i<10;i++){

		Insertdoc("\nInicio cadena ",file2,"historial.txt");

		s+="1";

		Insertdoc("Se agrega un 1",file2,"historial.txt");

		rnd=rand()%2;
	
		if(rnd){

			Insertdoc("Se entra a la cerradura (0+1)*",file2,"historial.txt");	
			
			rnd1=rand() % 1000 + 1;

			if(rnd1==1)Insertdoc("Se repite 1 vez la cerradura (0+1)*",file2,"historial.txt");	
			else Insertdoc("Se repite "+to_string(rnd1)+" veces la cerradura (0+1)*",file2,"historial.txt");	
			
			for(int i=0;i<rnd1;i++){
				
				rnd=rand()%2;
				if(rnd){
					s+="0";
					Insertdoc("Se selecciona un 0 de la cerradura (0+1)*",file2,"historial.txt");	

				}else{
					Insertdoc("Se selecciona un 1 de la cerradura (0+1)*",file2,"historial.txt");	
					s+="1";
				}
				
			}
		}else{
			Insertdoc("No se entra a la cerradura (0+1)*",file2,"historial.txt");	
			s+="";
		}

		
		rnd=rand()%2;

		if(rnd){
			Insertdoc("Se entra a la cerradura [((0*1)+1)*(e+(0+1))]*",file2,"historial.txt");	

			rnd=rand()%2;
			if(rnd){
				Insertdoc("Se entra a la cerradura ((0*1)+1)*",file2,"historial.txt");	
				
				rnd1=rand() % 1000 + 1;

				if(rnd1==1)Insertdoc("Se repite 1 vez la cerradura ((0*1)+1)*",file2,"historial.txt");	
				else Insertdoc("Se repite "+to_string(rnd1)+" veces la cerradura ((0*1)+1)*",file2,"historial.txt");	

				for(int i=0;i<rnd1;i++){
				
					rnd=rand()%2;	
					if(rnd){
						Insertdoc("Se selecciona (0*1) de la cerradura ((0*1)+1)*",file2,"historial.txt");	
						rnd=rand()%2;
						if(rnd){

							Insertdoc("Se entra a la cerradura 0*",file2,"historial.txt");
							rnd2=rand() % 1000 + 1;

							if(rnd2==1)Insertdoc("Se repite 1 vez la cerradura 0*",file2,"historial.txt");	
							else Insertdoc("Se repite "+to_string(rnd2)+" veces la cerradura 0*",file2,"historial.txt");	

							for(int i=0;i<rnd2;i++){
								s+="0";
							}
						}else{
							Insertdoc("No se entra a la cerradura 0*",file2,"historial.txt");
							s+="";
						}
						s+="1";
						Insertdoc("Se agrega un 1",file2,"historial.txt");

					}else{
						Insertdoc("Se selecciona 1 de la cerradura ((0*1)+1)*",file2,"historial.txt");	
						s+="1";
					}
				}

			}else{
				Insertdoc("No entra a la cerradura ((0*1)+1)*",file2,"historial.txt");	
				s+="";
			}

			rnd=rand()%2;
			if(rnd){
				Insertdoc("Se selecciona (0+1) de (e+(0+1))",file2,"historial.txt");	
				rnd=rand()%2;
				if(rnd){
					s+="0";
					Insertdoc("Se selecciona 0 de (0+1)",file2,"historial.txt");	
				} 
				else{
					s+="1";
					Insertdoc("Se selecciona 1 de (0+1)",file2,"historial.txt");	
				} 
			}else{
				Insertdoc("Se selecciona e de (e+(0+1))",file2,"historial.txt");
				s+="";
			}

		}else{
			Insertdoc("No se entra a la cerradura [((0*1)+1)*(e+(0+1))]*",file2,"historial.txt");	
			s+="";
		}

		Insertdoc(s,file1,"cadenas_re.txt");
		s="";

		Insertdoc("Fin cadena ",file2,"historial.txt");

	}
	return 0;
}

void Insertdoc(string cadena,ofstream &file,string fnom){

	file.open(fnom,ios_base::app);
  	file << cadena<<endl; 
	file.close();
}
