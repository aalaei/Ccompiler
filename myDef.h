#ifndef MYDEF
#define MYDEF
 //start
 #include <string.h>
 #include <map>
 #include <stack> 
 #include <vector>
 #include <stdio.h>
 #include <stdlib.h>

long long PC; 
stack<int> semantic_stack; 

enum SemanticType{
    NONE,
    SEM_TYPE_VARIABLE_INT
    ,SEM_TYPE_FUNCTION_INT
    ,SEM_TYPE_FUNCTION_VOID
};
class Node{
public:
    Node(){};
    SemanticType TYPE;
    long long address;
    int scope;
    int numOfArguments;
    void print()
    {
        cout <<TYPE<<"\t"<< address <<"\t" <<scope <<"\t"<< numOfArguments;
    }
};
map<string,Node> symbolTable;
int i=0;
vector<string> pb;

long long getFree(int size=1)
{
    long long res=Cur_Mem_tmp;
    Cur_Mem_tmp += size*4;
    return res;
}
void push(int in)
{
    semantic_stack.push(in);
}

int pop()
{
    int res=semantic_stack.top();
    semantic_stack.pop();
    return res;
}
bool declare_IntVariable(string name)
{
    Node tmp=Node();
    tmp.address=getFree();
    tmp.scope=1;
    tmp.TYPE=SEM_TYPE_VARIABLE_INT;
    symbolTable[name]=tmp;
    return true;
}
bool declare_Function(string name,int numOfArguments,string type)
{
    
    Node tmp=Node();
    //tmp.address=getFree();
    tmp.address=pb.size()+1;
    tmp.scope=1;
    if(name=="main")
    {
        PC=tmp.address;
    }
    if(type=="int")
        tmp.TYPE=SEM_TYPE_FUNCTION_INT;
    else if(type=="void")
        tmp.TYPE=SEM_TYPE_FUNCTION_VOID;
    else return false;
    tmp.numOfArguments=numOfArguments;
    symbolTable[name]=tmp;
    pb.push_back(name+": push %ebp");
    pb.push_back("mov %esp,%ebp");
    return true;
}
int functionCall(string name,int numOfArgs,int  arg0=0,int  arg1=0,int  arg2=0,int  arg3=0)
{
    int args[4]={arg0,arg1,arg2,arg3};
    char tmp[500];
    
	  if(symbolTable[name].TYPE<2)
	  {
		  printf("error in function call!!\n");
		  printf("expected symbol type: 2 or 3 but type is %d\n",symbolTable[name].TYPE);
		  exit(-2);
	  }
	  if (symbolTable[name].numOfArguments!=numOfArgs)
	  {
		  printf("error in function call!!\n");
		  printf("expected numberOfArguments: %d but it is %d\n",symbolTable[name].numOfArguments,numOfArgs);
		  exit(-3);
	  }
      for(int i=0;i<numOfArgs;i++)
      {
        sprintf(tmp,"lw $t0, 0(%d)",args[i]);
        
        pb.push_back(tmp);
        sprintf(tmp,"movl $t0,$a%d",i);
        pb.push_back(tmp);
      }
	  //sprintf(tmp,"jalr %llu",symbolTable[name].address);
      pb.push_back("jal "+name);
      pb.push_back("push res");
	  
}
void assignto(string ID)
{
    char tmp[500];
    Node var=symbolTable[ID];
    if(var.TYPE != SEM_TYPE_VARIABLE_INT)
    {
        printf("variable has not been declared properly!\n");
        exit(-10);
    }
    pb.push_back("lw $s0, 0($sp)"); 

    sprintf(tmp,"sw $s0, 0($%llu)",var.address);
    pb.push_back(tmp); 

}
void makeGolobal()
{
    map<string,Node>::iterator it = symbolTable.begin();
	while(it != symbolTable.end())
    { 
		if(it->second.TYPE == SEM_TYPE_VARIABLE_INT)
            it->second.scope=0;
        it++;
    }
	
}
void functionFinished()
{
    pb.push_back("mov %ebp, %esp");
    pb.push_back("pop %ebp");
    pb.push_back("ret");
}
//end
#endif