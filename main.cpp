#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
#include<cstdio>
#include<stdio.h>
#include<graphics.h>

using namespace std;

typedef vector<string> VecS;

void f(string s,int num);
string mov_rndom(int n);
void pieza(string s, int num);
void limpiar_archivos();
void seleccion_archivos();

void Ini_doc(string s);
int tam_archivo(string archivo);
void agregar_archivo(string line, string archivo);
void eliminar_contenido(string archivo, int tam);

void obtener_cadenasG(VecS &p1, VecS &p2);
string enArchivoRnd(string archivo,int tam);
void N_animaciones(VecS &p1, VecS &p2);
void comparador(string p1,string p2);
string buscarenArchivo(string cadena,string archivo);

void graficos(string p1,string p2);
void cuadrado(int x0,int y0,int x1,int y1,int x2,int y2, char c);
void tablero();
void titulo(int x0,int y0,int x1,int y1,int x2,int y2,char c,string titulo);

int scont;

int main() {
	
	int opc,rnd;
	string c1,c2,s_rnd;

	VecS p1,p2;

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

			while(true){
				cout<<"Camino pieza 1: "<<endl;
				cin>>c1;
				cout<<"Camino pieza 2: "<<endl;
				cin>>c2;
				if(c1.size()==c2.size()) break;
				else cout<<"Ambas cadenas deben tener la misma longitud"<<endl;
			}
			f(c1,1);
			f(c2,2);

		break;
		default:
			cout<<"Opcion no valida"<<endl;
		break;
	}

	seleccion_archivos();
	obtener_cadenasG(p1,p2);
	cout<<endl;
	for(int i=0;i<p1.size();i++) cout<<p1[i]<<endl;
	cout<<".."<<endl;	
	for(int i=0;i<p2.size();i++) cout<<p2[i]<<endl;

	N_animaciones(p1,p2);	



	

	/*for()

	cout<<p1[1]<<endl;
	cout<<p2[1]<<endl;

	graficos(p1[1],p2[1]);*/
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

	char * archivo1 = new char [archivo.length()+1];
	strcpy (archivo1, archivo.c_str());
	
	file.open(archivo1);

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
	
	char * archivo1 = new char [archivo.length()+1];
	strcpy (archivo1, archivo.c_str());

	file.open(archivo1,ios_base::app);
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
	
	char * archivo_lec1 = new char [archivo_lec.length()+1];
	strcpy (archivo_lec1, archivo_lec.c_str());

	if_file.open(archivo_lec1);

	while(getline(if_file,line)){

		if(line[line.length()-1]=='1'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="2";
					else line_aux+="4";
					
					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+="5";
				agregar_archivo(line_aux,archivo_esc);
			}
		}else if(line[line.length()-1]=='2'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="4";
					else line_aux+="6";
					
					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+="1";
					else if(j==1) line_aux+="3";
					else if(j==2) line_aux+="5";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line[line.length()-1]=='3'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="2";
					else line_aux+="6";

					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+="5";

				agregar_archivo(line_aux,archivo_esc);
			}
		}else if(line[line.length()-1]=='4'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="2";
					else if(j==1) line_aux+="8";

					agregar_archivo(line_aux,archivo_esc);		
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+="1";
					else if(j==1) line_aux+="5";
					else if(j==2) line_aux+="7";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line[line.length()-1]=='5'){
			if(s.compare("r")==0){
				for(int j=0;j<4;j++){
					line_aux=line;
					if(j==0) line_aux+="2";
					else if(j==1) line_aux+="4";
					else if(j==2) line_aux+="6";
					else if(j==3) line_aux+="8";

					agregar_archivo(line_aux,archivo_esc);
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<4;j++){
					line_aux=line;
					if(j==0) line_aux+="1";
					else if(j==1) line_aux+="3";
					else if(j==2) line_aux+="7";
					else if(j==3) line_aux+="9";

					agregar_archivo(line_aux,archivo_esc);
				}
			}
		}else if(line[line.length()-1]=='6'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="2";
					else line_aux+="8";
					
					agregar_archivo(line_aux,archivo_esc);	
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+="3";
					else if(j==1) line_aux+="5";
					else if(j==2) line_aux+="9";

					agregar_archivo(line_aux,archivo_esc);	
				}
			}
		}else if(line[line.length()-1]=='7'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="4";
					else line_aux+="8";

					agregar_archivo(line_aux,archivo_esc);		
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+="5";
				
				agregar_archivo(line_aux,archivo_esc);					
			}
		}else if(line[line.length()-1]=='8'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="4";
					else line_aux+="6";
						
					agregar_archivo(line_aux,archivo_esc);	
				}
			}else if(s.compare("b")==0){
				for(int j=0;j<3;j++){
					line_aux=line;
					if(j==0) line_aux+="5";
					else if(j==1) line_aux+="7";
					else if(j==2) line_aux+="9";

					agregar_archivo(line_aux,archivo_esc);	
				}
			}
		}else if(line[line.length()-1]=='9'){
			if(s.compare("r")==0){
				for(int j=0;j<2;j++){
					line_aux=line;
					if(j==0) line_aux+="6";
					else line_aux+="8";

					agregar_archivo(line_aux,archivo_esc);			
				}
			}else if(s.compare("b")==0){
				line_aux=line;
				line_aux+="5";

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

	
	char * archivof1 = new char [final1.length()+1];
	strcpy (archivof1, final1.c_str());
	

	if_file.open(archivof1);
	of_file.open("jganadorasP1.txt");
	while(getline(if_file,line)){
		if(line[line.length()-1]=='9' && line[1]!='2')
			of_file<<line<<endl;
	}
	of_file.close();
	if_file.close();
	
		
	char * archivof2 = new char [final2.length()+1];
	strcpy (archivof2, final2.c_str());
	

	if_file.open(archivof2);
	of_file.open("jganadorasP2.txt");
	while(getline(if_file,line)){
		if(line[line.length()-1]=='8')
			of_file<<line<<endl;
		
	}
	of_file.close();
	if_file.close();
}

void obtener_cadenasG(VecS &p1, VecS &p2){

	int tamp1,tamp2;
	string aux;

	tamp1=tam_archivo("jganadorasP1.txt");
	tamp2=tam_archivo("jganadorasP2.txt");

	if((tamp1==0) && (tamp2==0)){
		cout<<"Ninguna de las dos piezas tiene jugadas ganadoras"<<endl;
		exit(0);
	}else if(tamp1==0){
		cout<<"La pieza 1 no tiene jugadas ganadoras"<<endl;
		exit(0);
	}else if(tamp2==0){
		cout<<"La pieza 2 no tiene jugadas ganadoras"<<endl;
		exit(0);
	}else{
		int cont1=0,cont2=0;
		//Para la pieza 1
		for(int i=0;i<tamp1;i++){
			aux = enArchivoRnd("jganadorasP1.txt",tamp1);
			p1.push_back(aux);
			cont1++;
			if(i==2)break;
		}
		if(cont1==1)cout<<"\nLa pieza1 junto 1 jugada random"<<endl;
		else cout<<"\nLa pieza1 junto "<<cont1<<" jugadas random"<<endl;
		//Para la pieza 2
		for(int j=0;j<tamp2;j++){
			aux = enArchivoRnd("jganadorasP2.txt",tamp2);
			p2.push_back(aux);
			cont2++;
			if(j==2)break;
		}
		if(cont2==1)cout<<"\nLa pieza2 junto 1 jugada random"<<endl;
		else cout<<"\nLa pieza2 junto "<<cont2<<" jugadas random"<<endl;
	}
}

string enArchivoRnd(string archivo,int tam){

	int rnd=0;
	string line="";
	ifstream file;
	
	rnd = rand()%tam+1;

	char * a = new char [archivo.length()+1];
	strcpy (a,archivo.c_str());

	file.open(a);
	
	while(getline(file,line)){
		rnd--;
		if(rnd==0) break;
	}

	return line;
}

void N_animaciones(VecS &p1, VecS &p2){
	int j_1,j_2;

	j_1=p1.size();
	j_2=p2.size();

	if(j_1<j_2){
		for(int i=0;i<j_1;i++){
			comparador(p1[i],p2[i]);
		}
	}else if(j_2<j_1){
		for(int i=0;i<j_2;i++){
			comparador(p1[i],p2[i]);
		}
	}else{
		for(int i=0;i<j_1;i++){
			comparador(p1[i],p2[i]);
		}
	}
}


void comparador(string p1,string p2){

	int i=-1;
	bool ban=true;
	string aux;
	while(p1[++i]){
		if(p1[i]==p2[i]){
			ban=false;
			break;
		}else if(i>0){
			if(p1[i]==p2[i-1]){
				ban=false;
				break;
			}
		}
	}

	cout<<"\nANIMACION: "<<++scont<<endl;
	if(ban){ 
		cout<<"Cadenas animadas:"<<endl;
		cout<<"P1: "<<p1<<endl;
		cout<<"P2: "<<p2<<endl;
		graficos(p1,p2);	
		
	}else{
		aux=buscarenArchivo(p2,"jganadorasP1.txt");
		if(aux.empty()) cout<<"Todas las cadenas de la pieza 1 chocan con la de la pieza 2"<<endl;
		else {
			cout<<"Cadenas animadas:"<<endl;
			cout<<"Cadena alterna P1: "<<aux<<endl;
			cout<<"P2: "<<p2<<endl;
			graficos(aux,p2); 
		
		}
	}  
	

}


string buscarenArchivo(string cadena,string archivo){
	string line="";
	ifstream file;

	char * a = new char [archivo.length()+1];
	strcpy (a,archivo.c_str());

	file.open(a);
	
	while(getline(file,line)){
		bool ban=true;
		int i=-1;
		while(line[++i]){
			if(line[i]==cadena[i]){
				ban=false;
				break;
			}else if(i>0){
				if(line[i]==cadena[i-1]){
					ban=false;
					break;
				}
			}
		}
		if(ban) return line;
	}

	return line;
}

//630,466
void graficos(string g,string p){
	
	int gd= DETECT,gm,c1=1,c2=1;
	int h1x,h1y,h2x,h2y;
	string aux;

	string text = "CADENA GANADORA: "+g;
	
	initgraph(&gd,&gm,"");

	h1x=195;
	h1y=50;
	h2x=315;
	h2y=50;	
	
	tablero();
	//Piezas iniciales
	setcolor(GREEN);
	circle(h1x,h1y,40);		
	setcolor(BLUE);
	circle(h2x,h2y,40);
	
	titulo(135,390,495,420,400,420,'W',text);
	
	delay(1000);
	cleardevice();

	for(int i=0;i<((g.size()+p.size())-3);i++){
			
		tablero();
		titulo(135,390,495,420,400,420,'W',text);
	
		if((i%2)==0){
			if(g[c1]=='1'){
				setcolor(GREEN);
				circle(195,50,40);
				h1x=195;
				h1y=50;	
			}else if(g[c1]=='2'){
				setcolor(GREEN);
				circle(315,50,40);		
				h1x=315;
				h1y=50;
			}else if(g[c1]=='3'){
				setcolor(GREEN);
				circle(435,50,40);
				h1x=435;
				h1y=50;	
			}else if(g[c1]=='4'){
				setcolor(GREEN);
				circle(195,180,40);
				h1x=195;
				h1y=180;	
			}else if(g[c1]=='5'){
				setcolor(GREEN);
				circle(315,180,40);
				h1x=315;
				h1y=180;	
			}else if(g[c1]=='6'){
				setcolor(GREEN);
				circle(435,180,40);
				h1x=435;
				h1y=180;	
			}else if(g[c1]=='7'){
				setcolor(GREEN);
				circle(195,295,40);
				h1x=195;
				h1y=295;	
			}else if(g[c1]=='8'){
				setcolor(GREEN);
				circle(315,295,40);
				h1x=315;
				h1y=295;	
			}else if(g[c1]=='9'){
				setcolor(GREEN);
				circle(435,295,40);
				h1x=435;
				h1y=295;	
			}
			c1++;
			
			setcolor(BLUE);
			circle(h2x,h2y,40);
		
		}else{
			if(p[c2]=='1'){
				setcolor(BLUE);
				circle(195,50,40);
				h2x=195;
				h2y=50;		
			}else if(p[c2]=='2'){
				setcolor(BLUE);
				circle(315,50,40);		
				h2x=315;
				h2y=50;	
			}else if(p[c2]=='3'){
				setcolor(BLUE);
				circle(435,50,40);
				h2x=435;
				h2y=50;		
			}else if(p[c2]=='4'){
				setcolor(BLUE);
				circle(195,180,40);
				h2x=195;
				h2y=180;		
			}else if(p[c2]=='5'){
				setcolor(BLUE);
				circle(315,180,40);
				h2x=315;
				h2y=180;		
			}else if(p[c2]=='6'){
				setcolor(BLUE);
				circle(435,180,40);	
				h2x=435;
				h2y=180;
			}else if(p[c2]=='7'){
				setcolor(BLUE);
				circle(195,295,40);	
				h2x=195;
				h2y=295;
			}else if(p[c2]=='8'){
				setcolor(BLUE);
				circle(315,295,40);	
				h2x=315;
				h2y=295;
			}else if(p[c2]=='9'){
				setcolor(BLUE);
				circle(435,295,40);	
				h2x=435;
				h2y=295;
			}
			c2++;
			
			setcolor(GREEN);
			circle(h1x,h1y,40);
		}		
		if(i==((g.size()+p.size())-3)-1)delay(8000);
		else delay(1000);
		cleardevice();
	}
	closegraph();
}

void cuadrado(int x0,int y0,int x1,int y1,int x2,int y2,char c){
	if(c=='R'){
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		rectangle(x0,y0,x1,y1);
		floodfill(x2,y2,RED);
	}else if(c=='W'){
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
		rectangle(x0,y0,x1,y1);
		floodfill(x2,y2,WHITE);
	}
}

void tablero(){
	setcolor(RED);
	rectangle(135,0,495,360);
	//2
	cuadrado(255,0,375,120,350,20,'R');
	//4
	cuadrado(135,120,254,240,160,200,'R');
	//6
	cuadrado(376,120,495,240,490,200,'R');
	//8
	cuadrado(255,240,375,360,350,320,'R');
}

void titulo(int x0,int y0,int x1,int y1,int x2,int y2,char c,string titulo){
	
	char * aux = new char [titulo.length()+1];
	strcpy (aux, titulo.c_str());
	
	cuadrado(x0,y0,x1,y1,x2,y2,c);
	
	outtextxy(x2/2,y2-20,aux);		
}
