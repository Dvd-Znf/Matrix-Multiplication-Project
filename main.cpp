#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int a=0,b=0,c=0,d=0;			//These are the int's

//New fix for deleting the 32 if conditions:

struct {
	char name[4] = {'A','B','C','D'};
	int mat[4][20][20];
	int index[4][2];
} structStack;


void newmatrix()
{
	int i,j;
	static int countm=0;	//Counter will count the matrices used
			        //0 is ma
			        //1 is mb
			        //etc...

	if(countm==4) {
		cout<<"WARNING: All available matrices already hold value;";
		return;
	}

	cout<<"You are about to asign new values for a new matrix\n";
	cout<<"Please specify the dimesions of the matrix (STARTING INDEX 1!!!)\n";
	cout<<"Vertical: ";
	cin>>i;
	cout<<"Horizontal: ";
	cin>>j;

	if(i>19 || j>19){
		cout<<"WARNING: Illegal dimensions;";
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
	if(a==0){
		cin>>a;
		cout<<"You asigned the value "<<a<<" to the 'a' variable\n";
	} else if(b==0){
		cin>>b;
		cout<<"You asigned the value "<<b<<" to the 'b' variable\n";
	} else if(c==0){
		cin>>c;
		cout<<"You asigned the value "<<c<<" to the 'c' variable\n";
	} else if(d==0){
		cin>>d;
		cout<<"You asigned the value "<<d<<" to the 'd' variable\n";
	} else {
	       cout<<"WARNING: All available int's already hold value;\n";
           return;
	}	       
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
		cout<<"WARNING: Illegal response;\n";
	}
	
}

void showint()
{
    cout<<"Which one?(a,b,c,d)";
    char resp=' ';
    cin>>resp;
    if(resp=='a'){
        cout<<"a="<<a<<";\n";
        return;
    } else if(resp=='b'){
        cout<<"b="<<b<<";\n";
        return;
    } else if(resp=='c'){
        cout<<"c="<<c<<";\n";
        return;
    } else if(resp=='d'){
        cout<<"d="<<d<<";\n";
        return;
    } else {
        cout<<"WARNING: Illegal response;\n";
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
		cout<<"WARNING: Illegal response;\n";
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
        cout<<"WARNING: Illegal response;\n";
    }


}

void addmatrix(int mn[20][20],int mm[20][20],int sin,int sjn,int sim,int sjm)
{
	if(sin!=sim || sjn!=sjm){
		cout<<"WARNING: Illegal action;\n";
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
	
	for(int chi=0;chi<4;chi++){
		if(resp1==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
			for(int chj;chj<4;chj++){
				if(resp2==structStack.name[chj] && structStack.index[chj][0]!=0 && structStack.index[chj][1]!=0){
					addmatrix(structStack.mat[chi],structStack.mat[chj],
						structStack.index[chi][0],structStack.index[chi][1],
						structStack.index[chj][0],structStack.index[chj][1]);
			}
		}
		} else if(chi==3) {
			cout<<"WARNING: Illegal response;\n";
			return;
		}
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

	for(int chi=0;chi<4;chi++){
		if(resp==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
	
			tracematrix(structStack.mat[chi],structStack.index[chi][0],structStack.index[chi][1]);
	
		} else if(chi==3) {
			cout<<"WARNING: Illegal response;\n";
			return;
		}
	} return;

	

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

	if(resp1=='a'){					//TODO: add an array for int's
		for(int chi=0;chi<4;chi++){
			if(resp2==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				intmulti(a,structStack.mat[chi],
					structStack.index[chi][0],structStack.index[chi][1]);
			} else if(chi==3) {
				cout<<"WARNING: Illegal response;\n";
				return;
	}}} else if(resp1=='b'){					
		for(int chi=0;chi<4;chi++){
			if(resp2==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				intmulti(b,structStack.mat[chi],
					structStack.index[chi][0],structStack.index[chi][1]);
			} else if(chi==3) {
				cout<<"WARNING: Illegal response;\n";
				return;
	}}} else if(resp1=='c'){					
		for(int chi=0;chi<4;chi++){
			if(resp2==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				intmulti(c,structStack.mat[chi],
					structStack.index[chi][0],structStack.index[chi][1]);
			} else if(chi==3) {
				cout<<"WARNING: Illegal response;\n";
				return;
	}}} else if(resp1=='d'){					
		for(int chi=0;chi<4;chi++){
			if(resp2==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
				intmulti(d,structStack.mat[chi],
					structStack.index[chi][0],structStack.index[chi][1]);
			} else if(chi==3) {
				cout<<"WARNING: Illegal response;\n";
				return;
			} else {
		cout<<"WARNING: Illegal response;\n";
	}}

}}

void matrixmulti(int mn[20][20],int mm[20][20],int sin,int sjn,int sim,int sjm)
{
	if(sin!=sjm){
		cout<<"WARNING: Illegal action;";
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
	for(int chi=0;chi<4;chi++){
		if(resp1==structStack.name[chi] && structStack.index[chi][0]!=0 && structStack.index[chi][1]!=0){
			for(int chj;chj<4;chj++){
				if(resp2==structStack.name[chj] && structStack.index[chj][0]!=0 && structStack.index[chj][1]!=0){
					matrixmulti(structStack.mat[chi],structStack.mat[chj],
						structStack.index[chi][0],structStack.index[chi][1],
						structStack.index[chj][0],structStack.index[chj][1]);
			}
		}
		} else if(chi==3) {
			cout<<"WARNING: Illegal response;\n";
			return;
		}
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
		cout<<"WARNING: Illegal response;\n";
	}

}


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

static char inhelpstr[] = "\n"
			  "Showing help:\n"
			  "CLI inspired by python\n"
		  	  "This is list of all posible command options:\n"
			  "exit clear help new show addition multiplication trace\n"
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
	char sh[255];

	while(true){
	cout<<">>> ";
	cin.getline(sh,255);

	if(string(sh)=="exit"){				//TODO: Make struct for possible commands and functions
		cout<<"Recieved exit command\n";
		return 0;
	} else if(string(sh)=="clear"){
		system(sh);
		sh[0]='\0';
	} else if(string(sh)=="help"){
		cout<<inhelpstr;
		sh[0]='\0';
	} else if(string(sh)=="new"){
		fnew();
		sh[0]='\0';
		cin.ignore(255,'\n');
	} else if(string(sh)=="show"){
		fshow();
		sh[0]='\0';
		cin.ignore(255,'\n');
	} else if(string(sh)=="addition"){
		fadd();
		sh[0]='\0';
		cin.ignore(255,'\n');
	} else if(string(sh)=="multiplication"){
		fmulti();
		sh[0]='\0';
		cin.ignore(255,'\n');
	} else if(string(sh)=="trace"){
		ftrace();
		sh[0]='\0';
		cin.ignore(255,'\n');
	} 
	
	if(sh[0]!='\0') {
		cout<<sh<<" is not a recognized as a internal or external command\n Please use (help) for a list of available commands\n";
	}

}
}
