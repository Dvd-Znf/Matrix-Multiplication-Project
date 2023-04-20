#include<iostream>
#include<fstream>
#include<string.h>
#include <readline/readline.h>
#include <readline/history.h>

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

	rl_bind_key('\t', rl_complete);
	using_history();

	while(true){
	char* input = readline("mmp>>> ");

	if (!input){
		break;
	} 
	if (string(input)!="\0"){
		add_history(input);
	}

	for(int i=0;i<8;i++){
		if(string(cliStack.names[i]) == string(input)){
			(*cliStack.functions[i])();
			input[0]='\0';
		}
	}
	if(input[0]!='\0') {
		cout<<input<<" is not a recognized as a internal or external command\n" 
				<<"Please use (help) for a list of available commands\n";
	}
	free(input);
}
	return 0;
}
