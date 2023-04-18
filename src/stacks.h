void fexit();
void fclear();
void fhelp();
void fnew();
void fshow();
void fadd();
void fmulti();
void ftrace();


#ifndef STACKS_H
#define STACKS_H

int intArr[4] = {0,0,0,0};			
struct {
	char name[4] = {'A','B','C','D'};
	int mat[4][20][20];
	int index[4][2];
} structStack;

struct {
	const char* names[8] = {"exit",
							"clear",
							"help",
							"new",
							"show",
							"addition",
							"multiplication",
							"trace"};
	void (*functions [8])() = {fexit,
								fclear,
								fhelp,
								fnew,
								fshow,
								fadd,
								fmulti,
								ftrace};
} cliStack;


#endif