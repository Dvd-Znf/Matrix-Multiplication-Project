#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int a=0,b=0,c=0,d=0;			//These are the int's

int ma[20][20],
    mb[20][20],				//Thses are the 'multi dimensional' array's
    mc[20][20],				//Feel free to change the max dimension
    md[20][20];				//But if you do 
		        		//be carefull with memory utilisation
				        //These can hold up to 1600 variables!!!

int sia=0,sja=0,
    sib=0,sjb=0,			//These are global indexes for the matrices		
    sic=0,sjc=0,			//Their value is extremely important
    sid=0,sjd=0;			//I wouldn't recommend changing the default

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
			if(countm==0){
				cout<<"Value for ("<<ii<<","<<jj<<") : ";
				cin>>ma[ii][jj];
			} else if(countm==1){
				cout<<"Value for ("<<ii<<","<<jj<<") : ";
				cin>>mb[ii][jj];
			} else if(countm==2){
				cout<<"Value for ("<<ii<<","<<jj<<") : ";
				cin>>mc[ii][jj];
			} else if(countm==3){
				cout<<"Value for ("<<ii<<","<<jj<<") : ";
				cin>>md[ii][jj];
			} 
		}
	}

	if(countm==0){
		cout<<"You asigned new values to the 'A' matrix\n";
		sia=i;
		sja=j;
	} else if(countm==1){
		cout<<"You asigned new values to the 'B' matrix\n";
		sib=i;
		sjb=j;
	} else if(countm==2){
		cout<<"You asigned new values to the 'C' matrix\n";
		sic=i;
		sjc=j;
	} else if(countm==3){
		cout<<"You asigned new values to the 'D' matrix\n";
		sid=i;
		sjd=j;
	} 


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
	if(resp=='A' && sia!=0 && sja!=0 ){
		for(int i=1;i<=sia;i++){
			for(int j=1;j<=sja;j++){
				cout<<" "<<ma[i][j];
			}
			cout<<"\n";
		}
		return;
	} else if(resp=='B' && sib!=0 && sjb!=0 ){
		for(int i=1;i<=sib;i++){
			for(int j=1;j<=sjb;j++){
				cout<<" "<<mb[i][j];
			}
			cout<<"\n";
		}
		return;
	} else if(resp=='C' && sic!=0 && sjc!=0 ){
		for(int i=1;i<=sic;i++){
			for(int j=1;j<=sjc;j++){
				cout<<" "<<mc[i][j];
			}
			cout<<"\n";
		}
		return;
	} else if(resp=='D' && sid!=0 && sjd!=0 ){
		for(int i=1;i<=sid;i++){
			for(int j=1;j<=sjd;j++){
				cout<<" "<<md[i][j];
			}
			cout<<"\n";
		}
		return;
	} else {
		cout<<"WARNING: Illegal response;\n";
		return;
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

	if(resp1=='A'){						//I will fix this mess up later
		if(resp2=='A'){					//With 2 for loops
			addmatrix(ma,ma,sia,sja,sia,sja);	//And a matrix than holds indexes
		} else if(resp2=='B'){
			addmatrix(ma,mb,sia,sja,sib,sjb);
		} else if(resp2=='C'){
			addmatrix(ma,mc,sia,sja,sic,sjc);
		} else if(resp2=='D'){
			addmatrix(ma,md,sia,sja,sib,sjb);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='B'){
		if(resp2=='A'){
			addmatrix(mb,ma,sib,sjb,sia,sja);
		} else if(resp2=='B'){
			addmatrix(mb,mb,sib,sjb,sib,sjb);
		} else if(resp2=='C'){
			addmatrix(mb,mc,sib,sjb,sic,sjc);
		} else if(resp2=='D'){
			addmatrix(mb,md,sib,sjb,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='C'){
		if(resp2=='A'){
			addmatrix(mc,ma,sic,sjc,sia,sja);
		} else if(resp2=='B'){
			addmatrix(mc,mb,sic,sjc,sib,sjb);
		} else if(resp2=='C'){
			addmatrix(mc,mc,sic,sjc,sic,sjc);
		} else if(resp2=='D'){
			addmatrix(mc,md,sic,sjc,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='D'){
		if(resp2=='A'){
			addmatrix(md,ma,sid,sjd,sia,sja);
		} else if(resp2=='B'){
			addmatrix(md,mb,sid,sjd,sib,sjb);
		} else if(resp2=='C'){
			addmatrix(md,mc,sid,sjd,sic,sjc);
		} else if(resp2=='D'){
			addmatrix(md,md,sid,sjd,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else {
		cout<<"WARNING: Illegal response;\n";
		return;
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
	
	if(resp=='A'){
		tracematrix(ma,sia,sja);
	} else if(resp=='B'){
		tracematrix(mb,sib,sjb);
	} else if(resp=='C'){
		tracematrix(mc,sic,sjc);
	} else if(resp=='D'){
		tracematrix(md,sid,sjd);
	} else {
		cout<<"WARNING: Illegal response;\n";
		return;
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

	if(resp1=='a'){				//This mess will be cleaned up later
		if(resp2=='A'){
			intmulti(a,ma,sia,sja);
			return;
		} else if(resp2=='B'){
			intmulti(a,mb,sib,sjb);
			return;
		} else if(resp2=='C'){
			intmulti(a,mc,sic,sjc);
			return;
		} else if(resp2=='D'){
			intmulti(a,md,sid,sjd);
			return;
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='b'){
		if(resp2=='A'){
			intmulti(b,ma,sia,sja);
			return;
		} else if(resp2=='B'){
			intmulti(b,mb,sib,sjb);
			return;
		} else if(resp2=='C'){
			intmulti(b,mc,sic,sjc);
			return;
		} else if(resp2=='D'){
			intmulti(b,md,sid,sjd);
			return;
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='c'){
		if(resp2=='A'){
			intmulti(c,ma,sia,sja);
			return;
		} else if(resp2=='B'){
			intmulti(c,mb,sib,sjb);
			return;
		} else if(resp2=='C'){
			intmulti(c,mc,sic,sjc);
			return;
		} else if(resp2=='D'){
			intmulti(c,md,sid,sjd);
			return;
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='d'){
		if(resp2=='A'){
			intmulti(d,ma,sia,sja);
			return;
		} else if(resp2=='B'){
			intmulti(d,mb,sib,sjb);
			return;
		} else if(resp2=='C'){
			intmulti(d,mc,sic,sjc);
			return;
		} else if(resp2=='D'){
			intmulti(d,md,sid,sjd);
			return;
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else {
		cout<<"WARNING: Illegal response;\n";
	}

}

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

	if(resp1=='A'){						//I will fix this mess up later
		if(resp2=='A'){					//With 2 for loops
			matrixmulti(ma,ma,sia,sja,sia,sja);	//And a matrix than holds indexes
		} else if(resp2=='B'){
			matrixmulti(ma,mb,sia,sja,sib,sjb);
		} else if(resp2=='C'){
			matrixmulti(ma,mc,sia,sja,sic,sjc);
		} else if(resp2=='D'){
			matrixmulti(ma,md,sia,sja,sib,sjb);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='B'){
		if(resp2=='A'){
			matrixmulti(mb,ma,sib,sjb,sia,sja);
		} else if(resp2=='B'){
			matrixmulti(mb,mb,sib,sjb,sib,sjb);
		} else if(resp2=='C'){
			matrixmulti(mb,mc,sib,sjb,sic,sjc);
		} else if(resp2=='D'){
			matrixmulti(mb,md,sib,sjb,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='C'){
		if(resp2=='A'){
			matrixmulti(mc,ma,sic,sjc,sia,sja);
		} else if(resp2=='B'){
			matrixmulti(mc,mb,sic,sjc,sib,sjb);
		} else if(resp2=='C'){
			matrixmulti(mc,mc,sic,sjc,sic,sjc);
		} else if(resp2=='D'){
			matrixmulti(mc,md,sic,sjc,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else if(resp1=='D'){
		if(resp2=='A'){
			matrixmulti(md,ma,sid,sjd,sia,sja);
		} else if(resp2=='B'){
			matrixmulti(md,mb,sid,sjd,sib,sjb);
		} else if(resp2=='C'){
			matrixmulti(md,mc,sid,sjd,sic,sjc);
		} else if(resp2=='D'){
			matrixmulti(md,md,sid,sjd,sid,sjd);
		} else {
			cout<<"WARNING: Illegal response;\n";
		}
	} else {
		cout<<"WARNING: Illegal response;\n";
		return;
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
			"Concatenate standard input to standard output.\n"
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

	if(string(sh)=="exit"){
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
