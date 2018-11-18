#include<iostream>
#include<ctime>
#include<fstream>

using namespace std;

void case_(char a[]);
void printfile(string s);
void rnd(char a[]);
int main(){
		
	int index;
	char arr[1005];
	srand(time(NULL));	

	printf("1.-Ingresar cadena\n2.-Generar cadena aleatoriamente\n");
	scanf("%d",&index);
	switch(index){
		case 1:
			scanf("%s",arr);
			case_(arr);
		break;
		case 2:
			rnd(arr);
			case_(arr);
		break;
		default:
			printf("\nOpcion no valida.");
		break;
		
	}
}
void case_(char a[]){

	if(remove("derivations.txt"))1;

	string s="B",ot="",r1="(RB",r2="eps",r3=")",r4="(RR",final="";
	bool ban1 = true,ban2=false;
	
	printfile(s+"\n");

	for(char *p=a;*p!=0;++p){
		if(*p=='('){
			int i=-1;
			ban1=true;
			ot="";
			while(s[++i]!='\0'){
				if(s[i]=='B' && ban1==true){
					ot+=r1;
					printfile("B->"+r1);
					ban1=false;
				}else if(s[i]=='R' && ban1==true){
					ot+=r4;	
					printfile("R->"+r4);
					ban1=false;
				}else{
					ot+=s[i];
				}
			}
		}else{
			int i=-1;
			ban1=true;
			ot="";
			while(s[++i]!='\0'){
				if(s[i]=='B' &&	ban1==true){
					ot+=r2;
					printfile("B->"+r2);
					ban1=false;
				}else if(s[i]=='R' && ban1){
					ot+=r3;	
					printfile("R->"+r3);
					ban1=false;
				}else{
					ot+=s[i];
				}
			}
		}
		s=ot;
		printfile(s+"\n");
	}

	int i=-1;
	while(s[++i]!='\0'){
		
		if(s[i]=='R'){
			ban2=false;
			break;
		}else if(s[i]=='B'){
			printfile("B->eps");
			ban2=true;
		}else{
			final+=s[i];	
		}
	}

	printfile(final);

	if(ban2)cout<<"Cadena balanceada"<<endl;
	else cout<<"Cadena no balanceada"<<endl;

}

void printfile(string s){
	ofstream file;
	file.open("derivations.txt",ios_base::app);
  	file <<s<<endl; 
	file.close();
}

void rnd(char a[]){

	int rnd1=0,rnd2=0;
	rnd1=rand()%1000+1;
	for(int i=0;i<rnd1;i++){
		rnd2=rand()%2+1;
		if(rnd2==1){
			a[i]='(';
		}else{
			a[i]=')';
		}
	}
	a[rnd1]='\0';
	printf("%s\n",a);
}
