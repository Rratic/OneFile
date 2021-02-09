//C++11
//utf-8
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;
ifstream fin;
ofstream fout;
string te;
void movfile(string filepath,bool detect=false){
	fin.open(filepath,ios::in);
	if(!fin.is_open()){
		cout<<filepath<<" NOT FOUND:("<<endl;
		return;
	}
	while(getline(fin,te)){
		if(detect&&te.find("#include \"")!=te.npos)fout<<"//";
		fout<<te<<endl;
	}
	fin.close();
}
void movfileset(string filename,bool detect=true){
	movfile(filename+".h",detect);
	movfile(filename+".cpp",detect);
}
int main(){
	fout.open("output.txt",ios::out);//目标文件
	movfileset("test/123");//文件路径，P.S.小技巧：[../]跳到上层相对路径
	movfile("test/main.cpp");
	fout.close();
    return 0;
}
