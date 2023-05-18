#include"stacks.h"
using namespace std;
static char inhelpstr[] = "\n"
			"Showing help:\n"
			"CLI is using readline!\n"
		  	"This is list of all posible command options:\n"
			"exit clear help new show addition multiplication trace\n"
			"\n";	

#ifndef FUNCTIONS_H
#define FUNCTIONS_H


void newmatrix()
{
	int i,j;
	static int countm=0;	//Counter will count the matrices used
			        //0 is ma
			        //1 is mb
			        //etc...

	if(countm==4) {
		cout<<"\e[91mWARNING:\e[0m All available matrices already hold value;\n";
		return;
	}

	cout<<"You are about to asign new values for a new matrix\n";
	cout<<"Please specify the dimesions of the matrix (STARTING INDEX 1!!!)\n";
	cout<<"Vertical: ";
	cin>>i;
	cout<<"Horizontal: ";
	cin>>j;

	if(i>19 || j>19){
		cout<<"\e[91mWARNING:\e[0m Illegal dimensions;\n";
		return;
	}
	
	for(int ii=1;ii<=i;ii++)
	{
		for(int jj=1;jj<=j;jj++)
		{
			cout<<"Value for ("<<ii<<","<<jj<<") : ";
			cin>>structStack.mat[countm][ii][jj];
		}
	}

		cout<<"You asigned new values to the '"<<structStack.name[countm]<<"' matrix\n";
		structStack.index[countm][0]=i;
		structStack.index[countm][1]=j;

	countm++;
}

void newint()
{
	cout<<"You are about to asign a new value for a new integer\n";
	cout<<"Please asign a value: ";

	for(int i=0;i<4;i++){
		if(intArr[i] == 0){
			cin>>intArr[i];
			cout<<"You asigned the value "
				<<intArr[i]
				<<" to the '"
				<<char(structStack.name[i]+32)
				<<"' variable\n";
				return;
		}
	}
	cout<<"\e[91mWARNING:\e[0m All available int's already hold value;\n";
	return;
}

void fnew() 
{
	cout<<"New integer(1) or New matrix(2) ?\nSelect option(1/2): ";
	int resp;
	cin>>resp;
	if(resp==1){
		newint();
	} else if(resp==2) {
		newmatrix();
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
	}
	
}

void showint()
{
    cout<<"Which one?(a,b,c,d)";
    char resp=' ';
    cin>>resp;

	if(resp>='a' && resp<='d'){
		for(int i=0;i<4;i++){
			if(structStack.name[i]+32 == resp){
				cout<<char(structStack.name[i]+32)
					<<"="
					<<intArr[i]
					<<";\n";
					return;
			}
		}
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
		return;
	}
	
}

void showmatrix()
{
	cout<<"Which one?(A,B,C,D)";
	char resp=' ';
	cin>>resp;
	

	if(resp>='A' && resp<='D'){
		for(int chi=0;chi<4;chi++){
			if(resp==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				for(int i=1;i<=structStack.index[chi][0];i++){
					for(int j=1;j<=structStack.index[chi][1];j++){
						cout<<" "<<structStack.mat[chi][i][j];
					}
					cout<<"\n";
				}
			}
		}return;
		} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
	}
	
}


void fshow()
{
    cout<<"Would you like to show an integer(1) or matrix(2)\nSelect option(1/2): ";
    int resp;
    cin>>resp;
    if(resp==1){
        showint();
    } else if(resp==2) {
        showmatrix();
    } else {
        cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
    }


}

void addmatrix(int mn[20][20],int mm[20][20],int sin,int sjn,int sim,int sjm)
{
	if(sin!=sim || sjn!=sjm){
		cout<<"\e[91mWARNING:\e[0m Illegal action;\n";
		return;
	} else {
		for(int i=1;i<=sin;i++){
			for(int j=1;j<=sjn;j++){
				cout<<" "<<mn[i][j]+mm[i][j];
			}
			cout<<"\n";
		}
		return;
	}

}


void fadd()
{
	cout<<"Please enter two matrices to add togheter:\n";
	char resp1=' ',resp2=' ';

	cout<<"First one:";
	cin>>resp1;
	cout<<"Second one:";
	cin>>resp2;
	
	if(resp1>='A' && resp1<='D' && resp2>='A' && resp2<='D'){
		for(int chi=0;chi<4;chi++){
			if(resp1==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				for(int chj=0;chj<4;chj++){
					if(resp2==structStack.name[chj] && structStack.index[chj][0]!=0 && structStack.index[chj][1]!=0){
						addmatrix(structStack.mat[chi],structStack.mat[chj],
							structStack.index[chi][0],structStack.index[chi][1],
							structStack.index[chj][0],structStack.index[chj][1]);
				}
			}

	}} return;
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
	}

}

void tracematrix(int mn[20][20],int sin,int sjn)
{
	int s=0;
	for(int i=1;i<=sin;i++){
		for(int j=1;j<=sjn;j++){
			if(i==j)
				s=s+mn[i][j];
		}
	}
	cout<<"Trace result: "<<s<<"\n";
	return;
	
}

void ftrace()
{
	cout<<"What matrix would you like to trace?(A/B/C/D)";
	
	char resp=' ';
	cin>>resp;

	if(resp>='A' && resp<='D'){
		for(int chi=0;chi<4;chi++){
			if(resp==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				
				tracematrix(structStack.mat[chi],structStack.index[chi][0],structStack.index[chi][1]);

			} 
		}return;
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
	}
	

	

}

void intmulti(int n,int mn[20][20],int sin,int sjn)
{
	for(int i=1;i<=sin;i++){
		for(int j=1;j<=sjn;j++){
			cout<<" "<<n*mn[i][j];
		}
		cout<<"\n";
	}
	return;

}

void multiint()
{
	char resp1=' ',resp2=' ';
	cout<<"Which integer to use?\n(a/b/c/d): ";
	cin>>resp1;
	cout<<"Which matrix to use?\n(A/B/C/D): ";
	cin>>resp2;


	if(resp1>='a' && resp1<='d'){
		for(int i=0;i<4;i++){
			if(structStack.name[i]+32 == resp1){
				for(int chi=0;chi<4;chi++){
				if(resp2==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
					intmulti(intArr[i],structStack.mat[chi],
						structStack.index[chi][0],structStack.index[chi][1]);
					return;
				} else if(chi==3) {
					cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
					return;
				}
				}
			}		
		}
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
		return;
	}

}

void matrixmulti(int mn[20][20],int mm[20][20],int sin,int sjn,int sim,int sjm)
{
	if(sin!=sjm){
		cout<<"\e[91mWARNING:\e[0m Illegal action;\n";
		return;
	}

	int tmp=0;

	for(int i=1;i<=sin;i++){
		for(int ji=1;ji<=sim;ji++){
			for(int j=1;j<=sjn;j++){
				tmp=tmp+mn[i][j]*mm[j][ji];
			}
			cout<<" "<<tmp;
			tmp=0;
		}
		cout<<"\n";
	}
}

void multimatrix()
{
	cout<<"Please enter two matrices to multiply togheter:\n";
	char resp1=' ',resp2=' ';

	cout<<"First one:";
	cin>>resp1;
	cout<<"Second one:";
	cin>>resp2;
	if(resp1>='A' && resp1<='D' && resp2>='A' && resp2<='D'){
		for(int chi=0;chi<4;chi++){
			if(resp1==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				for(int chj;chj<4;chj++){
					if(resp2==structStack.name[chj] && structStack.index[chj][0]!=0 && structStack.index[chj][1]!=0){
						matrixmulti(structStack.mat[chi],structStack.mat[chj],
							structStack.index[chi][0],structStack.index[chi][1],
							structStack.index[chj][0],structStack.index[chj][1]);
					}
				}
		}} return;
		} else {
			cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
		}
	
}

void fmulti()
{
	cout<<"Would you like to multiply a matrix by a integer(1) or a matrix by a matrix(2)?\nSelect option(1/2): ";
	int resp=0;
	cin>>resp;
	if(resp==1){
		multiint();
	} else if(resp==2) {
		multimatrix();
	} else {
		cout<<"\e[91mWARNING:\e[0m Illegal response;\n";
	}

}

void fexit() {
	cout<<"Recieved exit command\n";
	exit(EXIT_SUCCESS);
}

void fclear() {
	system("clear");
}

void fhelp() {
	cout<<inhelpstr;
}

#endif