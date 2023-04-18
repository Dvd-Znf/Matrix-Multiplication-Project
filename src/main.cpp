#include<iostream>
#include<fstream>
#include<string.h>

#include"functions.h"
#include"stacks.h"

using namespace std;



static char helpstr[] = "\n"
			"Usage: mmp <command>\n"
			"\n"
			"CLI program that can be used to manipulate matrices\n"
			"You can use the inner help function within mmp for more details\n"
			"\n"
			"Posible command options:\n"
			"		-h | --help : Display this message\n"
			"\n"
			"Examples:\n"
			"	mmp			Launch the mmp program\n"
			"\n";

// static char inhelpstr[] = "\n"
// 			"Showing help:\n"
// 			"CLI inspired by python\n"
// 		  	"This is list of all posible command options:\n"
// 			"exit clear help new show addition multiplication trace\n"
// 			"\n";	  


int main(int argc, char* argv[])
{

	for(int i=1;i<argc;++i){
		if(string(argv[i]) == "-h" || string(argv[i]) == "--help"){
				cout<<helpstr;
				return 0;
		} else {
			cout<<argv[i]<<" unknown command\n";
			return 0;
		}
	}

	system("echo 'Matrix_ Multiplication_ Project_' | figlet | lolcat");
	system("echo 'By Dvd-Znf' | lolcat");
	char sh[255];

	while(true){
	cout<<">>> ";
	cin.getline(sh,255);

	for(int i=0;i<8;i++){
		if(string(cliStack.names[i]) == string(sh)){
			(*cliStack.functions[i])();
			sh[0]='\0';
			cin.ignore(255,'\n');
		}
	}
	if(sh[0]!='\0') {
		cout<<sh<<" is not a recognized as a internal or external command\n" 
				<<"Please use (help) for a list of available commands\n";
	}
}
}
