#include<iostream>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<graphics.h>

using namespace std;

typedef unsigned long long int Lng;

struct pointer{
	string state;
	char *ptr;
};

char* ini(char *a);
void startTM(char *a);
char* addBlank(char *a,char pos);
char* getnewPointer(char *a);
void printTape(char *a);
void rnd(char *a);
void printID(char *a,pointer head);

void iniPlot(char *a, pointer head);
void drawTape(char *a, pointer head);
void eye(int x,int y,int u,int v,string state);
void stateList();

Lng arrSize(char *a);

int main(){
	
	int index;
	char *arr1,*arr2;
	
	srand(time(NULL));

	arr1= new char[1001];

	printf("1.-Ingresar cadena\n2.-Generar cadena aleatoriamente\n");
	scanf("%d",&index);
	switch(index){
		case 1:
			scanf("%s",arr1);
			arr2=ini(arr1);
			startTM(arr2);
		break;
		case 2:
			rnd(arr1);
			printf("%s\n",arr1);
			arr2=ini(arr1);
			startTM(arr2);
		break;
		default:
			printf("\nOpcion no valida.");
		break;
	}
	
	return 0;
}

char* ini(char *a){

	char *b,*c,*d;
	b = new char[arrSize(a)+10];
	c=b;
	*c='B';
	*(++c)='B';

	for(d=a;*d!=0;++d){
		++c;
		*c=*d;
	}

	*(++c)='B';
	*(++c)='B';
	*(++c)='\0';

	delete []a;
	c=NULL;
	d=NULL;

	return b;
}

void startTM(char *a){

	if(remove("tape.txt"))1;
	if(remove("insDesc.txt"))1;

	char *b;
	bool ban1=true,ban2=true;
	pointer head;
	
	head.state="Sx0";
	head.ptr=a+2;
	
	if(arrSize(a)>20){
		ban2=false;
		printf("La cadena es muy grande y por lo tanto no se animara\n");
	}else{
		iniPlot(a,head);
	}
	
	while(1){
		
		printTape(a);
		printID(a,head);
		if(!ban1 && ban2){
			drawTape(a,head);	
		}
		ban1=false;
		
		if(head.state=="Sx0"){
			if(*(head.ptr)=='0'){
				++(head.ptr);
			}else if(*(head.ptr)=='1'){
				head.state="S01";
				++(head.ptr);
			}else if(*(head.ptr)=='B'){		
				head.state="SB";
				*(head.ptr)='-';
				b=addBlank(a,'B');				
				delete []a;
				a=NULL;
				a=b;
				head.ptr=getnewPointer(a);
				--head.ptr;					
			}
		}else if(head.state=="S01"){
			if(*(head.ptr)=='0'){
				head.state="Sx0";
				*(head.ptr)='1';
				++(head.ptr);
			}else if(*(head.ptr)=='1'){
				head.state="S11";
				++(head.ptr);
			}else if(*(head.ptr)=='B'){
				exit(0);
			}
		}else if(head.state=="S11"){
			if(*(head.ptr)=='0'){
				head.state="Sx0";
				*(head.ptr)='1';
				++(head.ptr);
			}else if(*(head.ptr)=='1'){
				*(head.ptr)='0';
				++(head.ptr);
			}else if(*(head.ptr)=='B'){
				exit(0);
			}
		}else if(head.state=="SB"){
			if(*(head.ptr)=='0'){
				--(head.ptr);
			}else if(*(head.ptr)=='1'){
				--(head.ptr);
			}else if(*(head.ptr)=='B'){
				head.state="Sx0";
				*(head.ptr)='-';
				b=addBlank(a,'F');				
				delete []a;
				a=NULL;
				a=b;
				head.ptr=getnewPointer(a);
				++head.ptr;								
			}
		}	
	}


}

char* addBlank(char *a,char pos){
	char *b,*c,*d;
	b=new char[arrSize(a)+10];
	c=b;
	
	if(pos=='B'){
		for(d=a;*d!=0;++d){
			*c=*d;
			++c;
		}
		*c='B';
		*(++c)='\0';
	}else if(pos=='F'){	
		*c='B';
		++c;
		for(d=a;*d!=0;++d){
			*c=*d;
			++c;
		}
		*c='\0';
	}
	return b;
}

char* getnewPointer(char *a){
	char *b;
	for(b=a;*b!=0;++b){
		if((*b)=='-'){
			(*b)='0';
			return b;
		}
	}
	
}

Lng arrSize(char *a){

	Lng size=0;
	char *f;
	f=a;
	while(*f!=0){
		size++;
		f++;
	}
	return size;
}

void rnd(char *a){

	int rnd1=0,rnd2=0;
	rnd1=rand()%1000+1;
	
	for(int i=0;i<rnd1;i++){
		rnd2=rand()%2+1;
		if(rnd2==1){
			a[i]='0';
		}else{
			a[i]='1';
		}
	}
	a[rnd1]='\0';
}

void printTape(char *a){
	string s(a);
	ofstream file;
	file.open("tape.txt",ios_base::app);
	file<<s<<endl;
	file.close();
}

void printID(char *a,pointer head){
	char*b;
	string insd="";
	
	for(b=a;*b!=0;++b){
		
		if(head.ptr==b){
			insd+="("+head.state+")";
			if(*b!='B'){
				insd+=(*b);	
			}
		}else{
			if(*b!='B'){
				insd+=(*b);	
			}
		}	
	}
	insd+="->";
	
	ofstream file;
	file.open("insDesc.txt",ios_base::app);
	file<<insd;
	file.close();	
}

void iniPlot(char *a,pointer head){
		
	int gd= DETECT,gm;
	initgraph(&gd,&gm,"");

	drawTape(a,head);
}

void drawTape(char *a,pointer head){
	
	int l=0,t=260,r=30,b=290;
	int tx=15,ty=265;
	
	char *sz,*c;
	
	stateList();
	for(sz=a;*sz!=0;++sz){
		
		rectangle(l,t,r,b);
		
		if(head.ptr==sz){	
			eye(l,t,r,b,head.state);
		}
		
		c = new char[1];
		*c=*sz;
		outtextxy(tx,ty,c);	
		delete[]c;
		
		l+=30;
		r+=30;
		tx+=30;
	}
	
	delay(1000);
	cleardevice();	
}

void stateList(){
	
	rectangle(10,10,130,130);
	
	settextstyle(3,0,1);

	outtextxy(15,15,"Estados");

	outtextxy(15,35,"SX0 = 1");
	outtextxy(15,55,"S01 = 2");
	outtextxy(15,75,"S11 = 3");
	outtextxy(15,95,"SB  = 4");
}

void eye(int x,int y,int u,int v,string state){
	rectangle(x,y-80,u,v-80);
	
	if(state=="Sx0"){
		outtextxy(x+15,y-75,"1");	
	}else if(state=="S01"){
		outtextxy(x+15,y-75,"2");
	}else if(state=="S11"){
		outtextxy(x+15,y-75,"3");
	}else if(state=="SB"){
		outtextxy(x+15,y-75,"4");
	}
	line(x+15,y-50, x+15,v-30);
}

