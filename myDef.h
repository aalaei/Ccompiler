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

extern string lastScope;
enum SemanticType{
    NONE,
    SEM_TYPE_VARIABLE_INT
    ,SEM_TYPE_FUNCTION_INT
    ,SEM_TYPE_FUNCTION_VOID
};
class Node{
private:
    string tp()
    {
        if(TYPE==NONE)
            return "None";
        else if (TYPE==SEM_TYPE_VARIABLE_INT)
            return "int_variable";
        else if (TYPE==SEM_TYPE_FUNCTION_INT)
            return "int_function";
        else if (TYPE==SEM_TYPE_FUNCTION_VOID)
            return "void_function";
    }
public:

    Node(){address=0;output=0;};
    SemanticType TYPE;
    long long address;
    int scope;
    int numOfArguments;
    bool output;
    string name;
    void print(bool show=0)
    {
        if(show)
            cout <<  name <<"\t"<< this->tp()<<"\t"<< address <<"\t" <<scope <<"\t"<< numOfArguments;
        else
            cout << this->tp()<<"\t"<< address <<"\t" <<scope <<"\t"<< numOfArguments;
    }
};
stack<Node> my_stack; 
stack<Node> my_redundant_stack; 
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
bool declare_IntVariable(string name,bool local=0)
{
    Node tmp=Node();
    tmp.name=name;
    if(local)
    {
        if(symbolTable[name].address!=0)
        {
            symbolTable[name].name=name;
            my_stack.push(symbolTable[name]);
        }
        tmp.scope=2;
    }else
    {
        tmp.scope=1;
    }
    tmp.address=getFree();
    tmp.numOfArguments=0;
    tmp.TYPE=SEM_TYPE_VARIABLE_INT;
    symbolTable[name]=tmp;
    
    if(local)
        my_redundant_stack.push(symbolTable[name]);
    return true;
}
bool declare_Function(string name,int numOfArguments,string type)
{
    
    Node tmp=Node();
    //tmp.address=getFree();
    tmp.address=pb.size()+1;
    tmp.scope=1;
    lastScope=name;
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



    char temp[500];

    for (int i=0;i<numOfArguments;i++)
    {
        if(i==0)
            sprintf(temp,"%s: lw $a%d,0($sp)",name.c_str(),numOfArguments-1-i);
        else
            sprintf(temp,"lw $a%d,0($sp)",numOfArguments-1-i);
	    pb.push_back(temp); 
        pb.push_back("addi $sp, $sp,4"); 
    }
    if(numOfArguments==0)
        pb.push_back(name+": addi $sp, $sp,-4"); 
    else
        pb.push_back("addi $sp, $sp,-4"); 
    
	pb.push_back("sw $ra,0($sp)"); 

    //pb.push_back("movl %esp,%ebp");
    return true;
}
int functionCall(string name,int numOfArgs,int  arg0=0,int  arg1=0,int  arg2=0,int  arg3=0)
{
    int args[4]={arg0,arg1,arg2,arg3};
    char tmp[500];
    
	  if(symbolTable[name].TYPE<2)
	  {
		  
		  sprintf(tmp,"error in function call!!\n\texpected symbol type: 2 or 3 but type is %d\n",symbolTable[name].TYPE);
          error(tmp);
		  exit(-2);
	  }
	  if (symbolTable[name].numOfArguments!=numOfArgs)
	  {
		  sprintf(tmp,"error in function call!!\n\texpected numberOfArguments: %d but it is %d\n",symbolTable[name].numOfArguments,numOfArgs);
		  error(tmp);
		  exit(-3);
	  }
      /*
      for(int i=0;i<numOfArgs;i++)
      {
        //sprintf(tmp,"lw $a%d, 0($sp)",i);
        //pb.push_back(tmp);
        //pb.push_back("addi $sp,$sp,4");
      }
      */
	  //sprintf(tmp,"jalr %llu",symbolTable[name].address);
      pb.push_back("jal "+name);
      //pb.push_back("push res");
	  
}
void assignto(string ID)
{
    char tmp[500];
    Node var=symbolTable[ID];
    if(var.TYPE != SEM_TYPE_VARIABLE_INT)
    {
        error("variable has not been declared properly!");
        exit(-10);
    }
    pb.push_back("lw $s0, 0($sp)"); 
    pb.push_back("addi $sp,$sp,4");

    sprintf(tmp,"sw $s0, %llu($gp)",var.address);
    pb.push_back(tmp); 

}
void makeGolobal()
{
    map<string,Node>::iterator it = symbolTable.begin();
    pb.push_back(".data:");
	while(it != symbolTable.end())
    { 
		if(it->second.TYPE == SEM_TYPE_VARIABLE_INT)
            {
                it->second.scope=0;
                //pb.push_back("\t"+it->first +": .word");
            }
        it++;
        //if (it->first!="")
            
    }
    pb.push_back("err_string: .asciiz \"\\ndivide by zero error!\\n\"");
    pb.push_back(".text:");
    push(pb.size());
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
	
}
void removeItemFromSymbolTable(string cur)
{
    
    for(map<string,Node>::iterator it = symbolTable.begin();it != symbolTable.end();it++)
    { 
		if(it->first==cur)
        {
            symbolTable.erase(it);
        }
    }
}
void returnHandle()
{
    symbolTable[lastScope].output=1;

    if(symbolTable[lastScope].TYPE==SEM_TYPE_FUNCTION_VOID)
    {
        printf("warning void function can't return any value!(line #:%d)\n",yylineNum);
        
    }else{
    pb.push_back("lw $v0, 0($sp)");    // pop to $v0
    }
    pb.push_back("addi $sp, $sp,4");
}
void functionFinished(int numberOfArguments,string ID)
{
    //pb.push_back("movl %ebp, %esp");
    //pb.push_back("pop %ebp");
    printf("scope finished semantic in %s:\n",ID.c_str());
    for(int i=0;i<numberOfArguments;i++)
    {
        Node cur=my_redundant_stack.top();
        cur.print(1);
        printf("\n");
        my_redundant_stack.pop();
        removeItemFromSymbolTable(cur.name);
    }
    while(!my_stack.empty())
    {
        Node tmp=my_stack.top();
        symbolTable[tmp.name]=tmp;
        my_stack.pop();
    }
    if(symbolTable[ID].TYPE==SEM_TYPE_FUNCTION_INT)
    {
        
        if(!symbolTable[ID].output)
        {
            printf("warning return is missing (0 is considerd!)!(line #:%d)\n",yylineNum);
            pb.push_back("li $v0,0");
            
        }
        pb.push_back("lw $ra, 0($sp)");  // pop to $ra
	    pb.push_back("addi $sp, $sp,4"); 
            
        /*
        pb.push_back("lw $v0, 0($sp)"); 
        pb.push_back("addi $sp, $sp,4");   // pop to $v0
*/
        
	    pb.push_back("addi $sp, $sp,-4");  // push from $v0
        pb.push_back("sw $v0, 0($sp)"); 

    }else{
        
        pb.push_back("lw $ra, 0($sp)"); 
	    pb.push_back("addi $sp, $sp,4"); 
    }
    
    pb.push_back("jr $ra");
}

void save(){
    pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
    push(pb.size());
    pb.push_back("");
}
void jump()
{
    pb[pop()]="j "+ to_string(pb.size()+1);    
}
void saveJump()
{
    int top=pop();
    //int top_1=pop();
    
    pb[top]="be $s0,$zero, "+to_string(pb.size()+2);
    push(pb.size());
    pb.push_back("");

}
void fun_var(string name,int i)
{
    char temp[500];
    declare_IntVariable(name,1);
	pb.push_back("addi $sp, $sp,-4"); 
    sprintf(temp,"sw $a%d, 0($sp)",i-1);
    pb.push_back(temp); 
    assignto(name);
    
}
void symbolTableShow()
{
    cout<<"symbol table:"<<endl;
    map<string,Node>::iterator it = symbolTable.begin();
    cout<<"name\tType\t\taddress\tscope\t#"<<endl;
	while(it != symbolTable.end())
    { 
		cout<<it->first<<"\t";
		it->second.print();
		cout<<endl;
        it++;
    }
}
//end
#endif