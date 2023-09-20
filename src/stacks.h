void fexit();
void fclear();
void fhelp();
void fnew();
void fshow();
void fadd();
void fmulti();
void ftrace();
void fversion();
void ftranspose();


#ifndef STACKS_H
#define STACKS_H

int intArr[4] = {0,0,0,0};			
struct {
	char name[4] = {'A','B','C','D'};
	int mat[4][20][20];
	int index[4][2];
} structStack;

struct {
	const char* names[10] = {"exit",
							"clear",
							"help",
							"new",
							"show",
							"addition",
							"multiplication",
							"transpose",
							"trace",
							"version"};
	void (*functions [10])() = {fexit,
								fclear,
								fhelp,
								fnew,
								fshow,
								fadd,
								fmulti,
								ftranspose,
								ftrace,
								fversion};
} cliStack;


#endif