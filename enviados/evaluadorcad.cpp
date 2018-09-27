#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

void filter(string line,map<string,int> &result);
void automaton(string str,map<string,int> &result);
void swcase(string cad,map<string,int> &result);
void prnt(map<string,int>result);

int main(){

	string name_doc,line;
	map<string,int> result;

	cout<<"Ingresa el nombre del archivo"<<endl;
	cin>>name_doc;
	name_doc+=".txt";

	ifstream file1(name_doc);
  
	if(file1.is_open())
   		while(getline(file1,line))
    		filter(line,result);
	
    file1.close();

    prnt(result);

	return 0;
}


void filter(string line,map<string,int>& result){
	string str="";
	transform(line.begin(), line.end(), line.begin(), ::tolower);
	for(int i=0;i<line.size();i++){
		if(line[i]!=' '){
			if(line[i]!='.' && line[i]!=',' && line[i]!=';' && line[i]!=':'){
				str+=line[i];
				if(i==(line.size()-1))
					automaton(str,result);
			}else if(i==(line.size()-1)){
				automaton(str,result);
			}
		}else{
			automaton(str,result);
			str="";
		}
	}	
}

void automaton(string str,map<string,int>& result){

	string c_s = "a";

	for(int i=0;i<str.size();i++){
			
		if(c_s=="a"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="b"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s="h";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s="f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="c"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='b') c_s="i";
			else if(str[i]=='m') c_s="k";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="d"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="e"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='n') c_s="m";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="f"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="n";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="g"){
			if(str[i]=='w') c_s="o";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="h"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='b') c_s ="p";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="i"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="q";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="j"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='s') c_s="r";
			else if(str[i]=='c') c_s="s";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="k"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="t";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else c_s="a";
		}else if(c_s=="l"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="u";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="m"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='s') c_s="v";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="n"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='c') c_s="w";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="o"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="h";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="x";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="p"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='p') c_s="y";
			else if(str[i]=='a') c_s="q";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="q"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='y') c_s="z";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="r"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='y') c_s="aa";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="s"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='h') c_s="bb";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="t"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="cc";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="u"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='z') c_s="dd";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="v"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="ee";
			else c_s="a";
		}else if(c_s=="w"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="ff";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="x"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='n') c_s="m";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="gg";
			else c_s="a";
		}else if(c_s=="y"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="hh";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="z"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="aa"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="bb"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="cc"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='l') c_s="ii";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="dd"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='o') c_s="jj";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="ee"){
			if(str[i]=='w') c_s="o";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="kk";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";	
		}else if(c_s=="ff"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='b') c_s="ll";
			else if(str[i]=='m') c_s="k";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";	
		}else if(c_s=="gg"){
			if(str[i]=='w') c_s="o";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="mm";
			else c_s="a";
		}else if(c_s=="hh"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='g') c_s="nn";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="ii"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="jj"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='n') c_s="oo";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="kk"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='g') c_s="pp";
			else if(str[i]=='m') c_s="l";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="ll"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='o') c_s="qq";
			else if(str[i]=='a') c_s="q";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="mm"){
			if(str[i]=='w') c_s="o";
			else if(str[i]=='e') c_s ="rr";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";	
		}else if(c_s=="nn"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="ss";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="oo"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="pp"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='r') c_s="tt";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="qq"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='o') c_s="uu";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="rr"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='r') c_s="vv";
			else if(str[i]=='m') c_s="k";
			else if(str[i]=='b') c_s="i";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";	
		}else if(c_s=="ss"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='b') c_s="i";
			else if(str[i]=='a') c_s="j";
			else if(str[i]=='m') c_s="k";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="tt"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="ww";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="uu"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='k') c_s="xx";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="vv"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="ww"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='m') c_s="yy";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="xx"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="d";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}else if(c_s=="yy"){
			if(str[i]=='w') c_s="b";
			else if(str[i]=='e') c_s ="c";
			else if(str[i]=='a') c_s="u";
			else if(str[i]=='i') c_s="e";
			else if(str[i]=='f') c_s= "f";
			else if(str[i]=='t') c_s="g";
			else c_s="a";
		}
	
		swcase(c_s,result);
	}	
}

void swcase(string cad,map<string,int> &result){
	string ans="";
	
	if(cad=="p") ans="web";
	else if(cad=="z") ans="ebay";
	else if(cad=="aa") ans="easy";	
	else if(cad=="bb") ans="each";
	else if(cad=="ii") ans="email";
	else if(cad=="oo") ans="amazon";
	else if(cad=="ss") ans="webpage";
	else if(cad=="vv") ans="twitter";
	else if(cad=="xx") ans="facebook";
	else if(cad=="yy") ans="instagram";

	if(ans!="")
		result[ans]++;
}

void prnt(map<string,int>result){

	map<string,int>::const_iterator it; 

	cout<<"\nCadenas-----------------Apariciones"<<endl;
	cout<<"\n";

	for (it = result.begin(); it!= result.end(); it++)
		cout << it->first<<" -------------------"<< it->second<<endl;
}
	
		
