#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>

using namespace std;

void filtro(string line);
void automata(string str);

int main(){

	string name_doc,line;
	map<string,int> result; 

	cout<<"Ingresa el nombre del archivo"<<endl;
	cin>>name_doc;
	name_doc+=".txt";

	ifstream file1(name_doc);
  
	if(file1.is_open())
   		while(getline(file1,line))
    		filtro(line);
	
    file1.close();
	
	return 0;
}



void filtro(string line){
	string str="";
	transform(line.begin(), line.end(), line.begin(), ::tolower);
	for(int i=0;i<line.size();i++){
		if(line[i]!=' '){
			if(line[i]!='.' && line[i]!=',' && line[i]!=';' && line[i]!=':'){
				str+=line[i];
				if(i==(line.size()-1))
					automata(str);
			}else if(i==(line.size()-1)){
				automata(str);
			}
		}else{
			automata(str);
			str="";
		}
	}
	
}

void automata(string str){

	string c_s = "a";

	for(int i=0;i<str.size();i++){
			
		if(c_s=="a"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="b"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s="h";
			else if(str[i]==('b'||'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s="f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="c"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='b') c_s="i";
			else if(str[i]==('y'||'p'||'g'|'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="k";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="d"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="e"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='n') c_s="m";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="f"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="n";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="g"){
			if(str[i]=='w') c_s="o";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="h"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='b') c_s ="p";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="i"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="q";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="j"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='s') c_s="r";
			else if(str[i]=='c') c_s="s";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="k"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="t";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="l"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="u";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="m"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='s') c_s="v";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="n"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'s'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='c') c_s="w";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="o"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="h";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="x";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="p"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='p') c_s="y";
			else if(str[i]=='a') c_s="q";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="q"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' ||'p'||'g'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='y') c_s="z";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="r"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' ||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='y') c_s="aa";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="s"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='h') c_s="bb";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="t"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="cc";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="u"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'l'||'s'||'c'||'h'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='z') c_s="dd";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="v"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="ee";
		}else if(c_s=="w"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="ff";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="x"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'k'||'r')) c_s="a";
			else if(str[i]=='n') c_s="m";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="gg";
		}else if(c_s=="y"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="hh";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}else if(c_s=="z"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]==('b' || 'y'||'p'||'g'||'m'||'l'||'s'||'c'||'h'||'z'||'o'||'n'||'k'||'r')) c_s="a";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
		}
	}
}

		


	
	
		
