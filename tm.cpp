#include<iostream>
#include<stdio.h>
#include<ctime>
#include<fstream>
#include<vector>
#include<graphics.h>

using namespace std;

struct pointer{
	string state;
	char *ptr;
};

char* ini(char *a);
void startTM(char *a);
char* addBlank(char *a,char pos);
char* getnewPointer(char *a);
void printTape(char *a);
void printID(char *a,pointer head);


unsigned long long int arrSize(char *a);

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
	pointer head;
	
	head.state="Sx0";
	head.ptr=a+2;
		
	while(1){
		
		printTape(a);
		printID(a,head);
				
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

unsigned long long int arrSize(char *a){

	unsigned long long int size=0;
	char *f;
	f=a;
	while(*f!=0){
		size++;
		f++;
	}
	return size;
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
		
		if((*b)!='B'){
			if(head.ptr==b){
				insd+="("+head.state+")";
				insd+=(*b);
			}else{
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


