#include<iostream>
#include<fstream>
#include<string.h>
#include<readline/readline.h>
#include<readline/history.h>

#include"functions.h"
#include"stacks.h"

using namespace std;

char** character_name_completion(const char *, int, int);
char* character_name_generator(const char *, int);

static char helpstr[] = "\n"
			"Usage: mmp <command>\n"
			"\n"
			"CLI program that can be used to manipulate matrices\n"
			"You can use the inner help function within mmp for more details\n"
			"\n"
			"Posible command options:\n"
			"		-h | --help	   : Display this message\n"
			"		-v | --version : Print version and exit\n"
			"\n"
			"Examples:\n"
			"	mmp			Launch the mmp program\n"
			"\n";

char* function_names[] = {
	"exit",
	"clear",
	"help",
	"new",
	"show",
	"addition",
	"multiplication",
	"trace",
	"version",
	NULL
};

char** character_name_completion(const char *text, int start, int end){
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, character_name_generator);
}


char* character_name_generator(const char *text, int state){
    static int list_index, len;
    char *name;

    if (!state) {
        list_index = 0;
        len = strlen(text);
    }

    while ((name = function_names[list_index++])) {
        if (strncmp(name, text, len) == 0) {
            return strdup(name);
        }
    }

    return NULL;
}


int main(int argc, char* argv[])
{

	for(int i=1;i<argc;++i){
		if(string(argv[i]) == "-h" || string(argv[i]) == "--help"){
				cout<<helpstr;
				return 0;
		} else if(string(argv[i]) == "-v" || string(argv[i]) == "--version") {
            fversion(); 
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
	rl_attempted_completion_function = character_name_completion;
	//rl_completion_suppress_append = 1;

	while(true){
	char* input = readline("mmp>>> ");

	if (!input){
		break;
	} 
	if (string(input)!="\0"){
		add_history(input);
	}

	for(int i=0;i<9;i++){
		//if(string(cliStack.names[i]) == string(input)){
		if(string(input).find(string(cliStack.names[i])) != string::npos){
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
