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
    tmp.address=getFree();
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
    return true;
}
void functionCall(string name,int numOfArgs,string ID1="",string ID2="",string ID3="",string ID4="")
{
    string IDS[4]={ID1,ID2,ID3,ID4};
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
        sprintf(tmp,"push %llu",symbolTable[IDS[i]].address);
        pb.push_back(tmp);
      }
	  sprintf(tmp,"cal %llu",symbolTable[name].address);
      pb.push_back(tmp);
	  
}
//end
#endif