
%{
 
 #include <iostream> 

 using namespace std;
 void yyerror(const char* error);
 
 #include <string.h>
 #include <map>
 #include <stack> 
 #include <vector>
 #include <stdio.h>
 #include <stdlib.h>
 
 extern FILE* yyin;
 extern int yylex();
 
 map<string,int> defs;

 FILE* f1;
 bool defShow=1;

 extern long long PC; 
 

 int yyparse();
 void ReplaceStringInPlace(string& subject, const string& search,
                          const string& replace) {
	//cout<<"I must look for"<<search<<"replace with"<<replace<<"in "<<subject<<endl;
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}
 void writeOutput(char * input,bool enter=0)
 {
	string ready=string(input);
	for(map<string,int>::iterator it = defs.begin();it != defs.end();it++)
	{ 
		string search=it->first;
		string replace=to_string(it->second);
		ReplaceStringInPlace(ready,search,replace);	
	}

	if(enter)
	fprintf(f1,"%s\n",ready.c_str());
	else
	fprintf(f1,"%s\n",ready.c_str());
 }
 void def(string name,int val)
 {
	 defs[name]=val;
	 printf("declared %s as %d\n",name.c_str(),val);
 }
 void file(string path)
 {
	char path_tmp[100];
	strcpy(path_tmp,path.c_str());
	char real_path[100],sec_path[100];
	sscanf(path_tmp,"#include \"%s\"",real_path);
	real_path[strlen(real_path)-1]=0;
	//sprintf(real_path,"#include \"%s\"",);
	printf("path:%s\n",real_path);
	char tmp[1000];
	char temp[100];
	int val;
	FILE* f_tmp=fopen(real_path,"r");
	if(file==NULL)
	{
		printf("file %s not Found!\n",real_path);
		exit(-404);
	}
	fclose(f_tmp);
	sprintf(sec_path,"pre_%s",real_path);
	sprintf(tmp,"./pre %s %s",real_path,sec_path);
	system(tmp);
	//////////////////////////////////path=path+"_pre";
	f_tmp=fopen(sec_path,"r");
	if(file==NULL)
	{
		printf("pre processed file %s not Found!\n",real_path);
		exit(-405);
	}
	while(fgets(tmp, 1000, f_tmp))
	{
		int i;
		for (i=0;tmp[i]==' ' || tmp[i]==' ' ;i++);
		if (tmp[i] =='#')
		{
			if(sscanf(&tmp[i],"#define %s %d",temp,&val))
			{
				
				if(defShow)
					writeOutput(tmp,1);
				def(temp,val);
			}
			continue;
		}else{
			writeOutput(tmp);
		}
		
	}
	fprintf(f1,"\n");
	
	fclose(f_tmp);
 }
 
 void copy(char * tx)
 {
	 char temp[100];
	 int val;
	 while(*tx==' ' || *tx==' ' )
	 	tx++;
	 if (*tx =='#')
	 {
		if(sscanf(tx,"#define %s %d",temp,&val))
		{
			
			if(defShow)
				writeOutput(tx,1);
			def(temp,val);
		}
		return;
		 
	 }
	 writeOutput(tx,1);
 }

%}

%union{
	char T[1000];
	char name[500];
	int iVal;
}
%token <T> TEXT
%token <name> ID
%token <iVal> NUM

%token <name> SHARP
%token <name> NEXTLINE
%token <name> defKeyWord
%token <name> includeKeyWord

%type <name> NEXTLINES

%type <T> ST

%%


PROGRAM:
	 PG
;
PG:
 ST {copy($1);} PG
 |ST {copy($1);}
 | NEXTLINES includeKeyWord {file($2);} PG 
 | NEXTLINES defKeyWord   {copy($2);} PG 
 ;
 ST:
	NEXTLINES TEXT  {strcpy($$,$2);}
;
NEXTLINES:
 NEXTLINE NEXTLINES   |{}
%%


void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	if(argc>=4)
	{
		if(strcmp(argv[3],"NoDef")==0)
			defShow=0;
	}
	if(argc>=3)
		f1=fopen(argv[2],"w");
	else if(argc>=2)
		f1=fopen("output_pre.c","w");

    if(!yyparse())
		printf("\npre process complete\n");
	else
	{
		printf("\nfailed!!\n");
		exit(-1);
	}
    fprintf(f1,"\n");
	fclose(yyin);
	fclose(f1);
	
    return 0;
}
