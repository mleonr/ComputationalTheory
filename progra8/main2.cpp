#include<iostream>
#include<vector>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include<graphics.h>

using namespace std;

typedef vector<string> Stack;

void push(string c,Stack &s);
void pop(Stack &s);
string top(Stack &s);
bool isEmpty(Stack &s);

string getRandom();
void evaluateStr(string str,Stack &s);
void insDesc(string state, string str, string state_s);
string lastElement();

void graphics(string str);
void templte(string str);

int main() {
	
	int index,r;
	string input,rnd;
	Stack s1;
	push("Z0",s1);
	
	r=remove("Instantdescriptions.txt");
	
	srand(time(NULL));
	
	cout<<"1. Ingresar cadena manualmente"<<endl;
	cout<<"2. Generar cadena aleatoria"<<endl;
	cin>>index;
	
	switch(index){
		case 1:
			cin>>input;
			evaluateStr(input,s1);
			break;
		case 2:	
			
			rnd=getRandom();
			cout<<"Cadena obtenida: "<<rnd<<endl;
			evaluateStr(rnd,s1);
			break;
		default: 
			cout<<"Opcion no valida"<<endl;
			break;
	}
	
	
	
	return 0;
}

string getRandom(){
	int rnd=0,aux;
	string ans="";
	rnd=rand()%1000+1;
	aux=rnd/2;
	cout<<rnd<<endl;
	cout<<aux<<endl;
	for(int i=1;i<=rnd;i++){
		if(i<=aux) ans+="0";
		else ans+="1";
	}
	return ans;
	
}

void evaluateStr(string str,Stack& s){
	
	string state="q", str_a=str, str_s = top(s),ans,aux;
	bool ban=true;
	insDesc(state,str_a,str_s);
	
	int i=-1;
	
	while(str[++i]){
		if(str[i]=='0'&& ban==true){
			push("X",s);
			str_a = str_a.substr(1,str_a.size()-1);
			str_s=top(s)+str_s;
			insDesc("q",str_a,str_s);
		}else if(str[i]=='1'){
			ban=false;
			if(top(s)=="Z0")break;
			pop(s);
			str_a = str_a.substr(1,str_a.size()-1);
			if(str_a.size()==0)str_a="e";
			str_s=str_s.substr(1,str_s.size()-1);
			insDesc("p",str_a,str_s);
		}
	}
	
	ans=lastElement();
	if(ans.compare("(p,e,Z0)")==0){
		cout << "Cadena correcta"<<endl;
		if(str.size()<=20)
			graphics(str);
	}else cout << "Cadena incorrecta"<<endl;
	
}

void insDesc(string state, string cad, string state_s){
	ofstream file;
	file.open("Instantdescriptions.txt",fstream::app);
	file<<"("<<state<<","<<cad<<","<<state_s<<")"<<endl;
	file.close();
}

string lastElement(){
	string line="",final;
	ifstream file;
	file.open("Instantdescriptions.txt");
	if(file.is_open()){
		while(getline(file,line)){
			final=line;
		}
	}
	file.close();
	return final;
}

void push(string c,Stack &s){
	s.push_back(c);
}

void pop(Stack &s){
	if(isEmpty(s)){
		cout<<"Subdesbordamiento de pila"<<endl;
		exit(0);
	}else
		s.erase(s.begin()+s.size());
}

string top(Stack &s){
	if(isEmpty(s)){
		cout<<"Subdesbordamiento de pila"<<endl;
		exit(0);
	}else
		return s.back();
	
}

bool isEmpty(Stack &s){
	if(s.empty()) return true;
	else return false;
}

void graphics(string str){
	
	int gd= DETECT,gm,e=0;
	
	initgraph(&gd,&gm,"");
	
	templte(str);
	delay(3000);
	cleardevice();

	int i=-1;	
	while(str[++i]){
		
		templte(str);
		
		if(str[i]=='0'){
			if(e==0){
				outtextxy(500,530,"push");
				outtextxy(700,530,"X");
				e++;
			}else if(e==1){
				outtextxy(500,480,"push");
				outtextxy(700,480,"X");
				e++;
			}else if(e==2){
				outtextxy(500,430,"push");
				outtextxy(700,430,"X");
				e++;
			}else if(e==3){
				outtextxy(500,380,"push");
				outtextxy(700,380,"X");
				e++;
			}else if(e==4){
				outtextxy(500,330,"push");
				outtextxy(700,330,"X");
				e++;
			}else if(e==5){
				outtextxy(500,280,"push");
				outtextxy(700,280,"X");
				e++;
			}else if(e==6){
				outtextxy(500,230,"push");
				outtextxy(700,230,"X");
				e++;
			}else if(e==7){
				outtextxy(500,180,"push");
				outtextxy(700,180,"X");
				e++;
			}else if(e==8){
				outtextxy(500,130,"push");
				outtextxy(700,130,"X");
				e++;
			}else if(e==9){
				outtextxy(500,80,"push");
				outtextxy(700,80,"X");
				e++;
			}
		}else if(str[i]=='1'){
			if(e==1) {
				outtextxy(500,530,"pop ");
				outtextxy(700,530," ");
				e--;
			}else if(e==2) {
				outtextxy(500,480,"pop ");
				outtextxy(700,480," ");	
				e--;
			}else if(e==3){
				outtextxy(500,430,"pop ");
				outtextxy(700,430," ");
				e--;
			}else if(e==4){
				outtextxy(500,380,"pop ");
				outtextxy(700,380," ");
				e--;
			}else if(e==5){
				outtextxy(500,330,"pop ");
				outtextxy(700,330," ");
				e--;
			}else if(e==6){
				outtextxy(500,280,"pop ");
				outtextxy(700,280," ");
				e--;
			}else if(e==7){
				outtextxy(500,230,"pop ");
				outtextxy(700,230," ");
				e--;
			}else if(e==8) {
				outtextxy(500,180,"pop ");
				outtextxy(700,180," ");
				e--;
			}else if(e==9){
				outtextxy(500,130,"pop ");
				outtextxy(700,130," ");
				e--;
			}else if(e==10){
				outtextxy(500,80,"pop ");
				outtextxy(700,80," ");
				e--;
			}
		}		
		delay(2000);
	}
	
	

	closegraph();
	

	
}	

void templte(string str){
	string title = "CADENA : "+str;
	char * t = new char [title.length()+1];
	strcpy (t, title.c_str());
	
	outtextxy(50,50,t);	

	//Z0
	
	rectangle(600,550,800,600);
	outtextxy(700,570,"Z0");
	
	//X1
	setvisualpage(0);
	rectangle(600,500,800,550);

	//X2
	rectangle(600,450,800,500);

	//X3
	rectangle(600,400,800,450);
	
	//X4
	rectangle(600,350,800,400);
	
	//X5
	rectangle(600,300,800,350);	
	
	//X6
	rectangle(600,250,800,300);
	
	//X7
	rectangle(600,200,800,250);
	
	//X8
	rectangle(600,150,800,200);
	
	//X9
	rectangle(600,100,800,150);
	
	//Stack
	rectangle(600,50,800,600);
	
	outtextxy(700,630,"STACK");	
}



