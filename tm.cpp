#include<iostream>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<graphics.h>

using namespace std;

void case_(char a[]);

int main(){
	
	int index;
	char *arr;
	arr= new char[1005];
	srand(time(NULL));		

	printf("1.-Ingresar cadena\n2.-Generar cadena aleatoriamente\n");
	scanf("%d",&index);
	switch(index){
		case 1:
			scanf("%s",arr);
			case_(arr);
		break;
		case 2:
			/*rnd(arr);
			case_(arr);*/
		break;
		default:
			printf("\nOpcion no valida.");
		break;
	}
	
	return 0;
}

void case_(char a[]){
	
	char *b;
	bool flag=true;
	string state ="Sx0";
	
	b = new char[1005];	

	b[0]='B';
	b[1]='B';	
	char *d=&b[2];
	
	for(char *p=a;*p!=0;++p){
		*d=*p;
		d++;	
	}
	*d='B';
	d++;
	*d='B';
	d++;
	*d='\0';
	
	char *ptr=&b[2];
	
	while(1){
		//printfile(s+"\n","tape.txt");
		
		if(state=="Sx0"){
			if(*ptr=='0'){
				state="Sx0";
				*ptr='0';
				ptr++;	
			}else if(*ptr=='1'){
				state="S01";
				*ptr='1';
				ptr++;	
			}else if(*ptr=='B'){
				state="SB";
				*ptr='0';
				ptr--;
				s+="B\0";
			}
		}else if(state=="S01"){
			if(*ptr=='0'){
				state="Sx0";
				*ptr='1';
				ptr++;	
			}else if(*ptr=='1'){
				state="S11";
				*ptr='1';
				ptr++;	
			}else if(*ptr=='B'){
				exit(0);
			}
		}else if(state=="S11"){
			if(*ptr=='0'){
				state="Sx0";
				*ptr='1';
				ptr++;	
			}else if(*ptr=='1'){
				state="S11";
				*ptr='0';
				ptr++;	
			}else if(*ptr=='B'){
				exit(0);
			}
		}else if(state=="SB"){
			if(*ptr=='0'){
				state="SB";
				*ptr='0';
				ptr--;	
			}else if(*ptr=='1'){
				state="SB";
				*ptr='1';
				*ptr--;	
			}else if(*ptr=='B'){
				state="Sx0";
				*ptr='0';
				ptr++;
				s="B"+s;
			}
		} 
	}
	
	


}
