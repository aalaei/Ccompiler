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

stack<long long> goodSpace;

stack<int> instJump; 

extern string lastScope;
extern string lastScope_BLOCK;
extern int localCount;

enum SemanticType{
    NONE
    ,SEM_TYPE_VARIABLE_INT
    ,SEM_TYPE_VARIABLE_ARRAY_INT
    ,SEM_TYPE_FUNCTION_INT
    ,SEM_TYPE_FUNCTION_VOID
};
class Node{
private:
    string tp()
    {
        if(TYPE==NONE)
            return "None TYPE";
        else if (TYPE==SEM_TYPE_VARIABLE_INT)
            return "int_variable";
        else if (TYPE==SEM_TYPE_FUNCTION_INT)
            return "int_function";
        else if (TYPE==SEM_TYPE_FUNCTION_VOID)
            return "void_function";
        else if(TYPE==SEM_TYPE_VARIABLE_ARRAY_INT)
            return "int_arrayVar";
    }
public:

    Node(){address=0;output=0;TYPE=NONE;scope=-1;numOfArguments=-1;name="";size=1;};
    SemanticType TYPE;
    long long address;
    int scope;
    int numOfArguments;
    bool output;
    string name;
    int size;
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
/*
void makeFree(long long ad,int size=1)
{
    for(int i=0;i<size;i++)
    {
        goodSpace.push(ad+4*i);
    }
}
*/
long long getFree(int size=1,bool array=0)
{
    long long res=Cur_Mem_tmp;
    if(array)
    {
        res=ARRAY_CNT;
        Cur_Mem_tmp += size*4;
        return res;

    }
    //if(goodSpace.size()<size)
        Cur_Mem_tmp += size*4;
    /*else{
        int max=0;
        res=goodSpace.top();
        vector<int> ar;
        for(int i=0;i<size;i++)
        {
            if(goodSpace.top()<res)
                res=goodSpace.top();
            if(goodSpace.top()>max)
                max=goodSpace.top();
            ar.push_back(goodSpace.top());
            goodSpace.pop();  
        }
        bool ok=1;
        for(int i=res;i<=max;i+=4)
        {
            bool contains=0;
            for(int j=0;j<size;j++)
            {
                if(ar[j]==i)
                {
                    contains=1;
                    break;
                }
            }
            if(!contains)
                ok=0;
        }
        if(!ok)
        {
            for(int i=0;i<ar.size();i++)
                goodSpace.push(ar[i]);
            Cur_Mem_tmp += size*4;
        }
        
    }*/
    return res;
}
/*
void pushNewFreeAddress()
{
    pb.push_back("lw $s0, 100($gp)");
    pb.push_back("addi $sp,$sp,-4");
    pb.push_back("sw $s0, 0($sp)");
    pb.push_back("addi $s0,$s0,4");
    pb.push_back("sw $s0, 100($gp)");

}
*/
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
    if(symbolTable[name].TYPE==SEM_TYPE_VARIABLE_INT)
    {
        myerror("int variable already declered!!!",88);
        return false ;
    }
    if(local)
    {
        symbolTable[lastScope].size+=4;
        if(symbolTable[name].address!=0)
        {
            symbolTable[name].name=name;
            my_stack.push(symbolTable[name]);
        }
        tmp.scope=2;
    }else if(lastScope_BLOCK=="BLK")
    {
       tmp.scope=localCount;
       
    }else
        tmp.scope=1;
    tmp.address=getFree();
    tmp.numOfArguments=-1;
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
    tmp.scope=-1;
    lastScope=name;
    if(name=="print" || name=="scan" )
    {
        myerror("reserved Function!!",8);
        
    }
    if(symbolTable[name].TYPE>=SEM_TYPE_FUNCTION_INT)
    {
        myerror("function already declered!!!",88);
        return false;
    }
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
    tmp.size=12+numOfArguments*4;
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
    if(name=="print"&& numOfArgs==1)
    {
        pb.push_back("li $v0,1");
	    pb.push_back("lw $a0,0($sp)");
        pb.push_back("addi $sp,$sp,4");
	    pb.push_back("syscall");
        pb.push_back("li $v0,4");
	    pb.push_back("la $a0,nextline_string");
	    pb.push_back("syscall");
        

        pb.push_back("li $v0,0");
        pb.push_back("addi $sp,$sp,-4");
        pb.push_back("sw $v0,0($sp)");

        return -10;
    }else if (name=="scan"&& numOfArgs==0)
    {
        pb.push_back("li $v0,5");
	    pb.push_back("syscall");
        pb.push_back("addi $sp,$sp,-4");
        pb.push_back("sw $v0,0($sp)");
        return -10;
    }//else if(name=="main")
    //{
        
    else{
        pb.push_back("lw $s0,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
        pb.push_back("addi $s0,$s0, "+to_string(symbolTable[name].size));
        pb.push_back("sw $s0,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
    }

    char tmp[500];
    
	  if(symbolTable[name].TYPE<3)
	  {
		  if(symbolTable[name].TYPE==0)
            sprintf(tmp,"error in function call!!\n\tundeclared function!!\n");
          else
		    sprintf(tmp,"error in function call!!\n\texpected symbol type: 3 or 4 but type is %d\n",symbolTable[name].TYPE);
          myerror(tmp,2);
	  }
	  if (symbolTable[name].numOfArguments!=numOfArgs)
	  {
		  sprintf(tmp,"error in function call!!\n\texpected numberOfArguments: %d but it is %d\n",symbolTable[name].numOfArguments,numOfArgs);
		  myerror(tmp,3);
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
      return -10;
      //pb.push_back("push res");
	  
}
void assignto(string ID)
{
    char tmp[500];
    Node var=symbolTable[ID];
    if(var.TYPE != SEM_TYPE_VARIABLE_INT)
    {
        sprintf(tmp,"variable \"%s\" has not been declared properly!",ID.c_str());
        myerror(tmp,11);
        
    }
    pb.push_back("lw $s0, 0($sp)"); 
    pb.push_back("addi $sp,$sp,4");

    if(var.scope==0)
    {
        pb.push_back("li $s1, 0"); 
    }else
        pb.push_back("lw $s1, "+to_string(DYNAMIC_OFFSET_LOC)+"($gp)"); 
    pb.push_back("addi $s3, $s1, "+to_string(var.address)); 
    pb.push_back("add $s3, $s3, $gp"); 
    pb.push_back("sw $s0, 0($s3)"); 
/*
    sprintf(tmp,"sw $s0, %llu($gp)",var.address);
    pb.push_back(tmp); 
*/
}
void assigntoar(string ID)
{
    char tmp[500];
    Node var=symbolTable[ID];
    if(var.TYPE != SEM_TYPE_VARIABLE_ARRAY_INT)
    {
        sprintf(tmp,"array \"%s\" has not been declared properly!",ID.c_str());
        myerror(tmp,10);
        
    }
    pb.push_back("lw $s0, 0($sp)"); // value 
    pb.push_back("addi $sp,$sp,4");

    pb.push_back("lw $s1, 0($sp)");  //index
    pb.push_back("addi $sp,$sp,4");

    pb.push_back("li $s4, 4"); // 4
    pb.push_back("mul $s1, $s1, $s4"); // *4

    
    pb.push_back("addi $s3, $s1, "+to_string(var.address)); 
    pb.push_back("add $s3, $s3, $gp"); 
    pb.push_back("sw $s0, 0($s3)"); 
/*
    sprintf(tmp,"sw $s0, %llu($gp)",var.address);
    pb.push_back(tmp); 
*/
}
void makeGolobal()
{
    map<string,Node>::iterator it = symbolTable.begin();
    
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
    
    push(pb.size());
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
    pb.push_back("");
	
}
void plusPlus(string ID,int sum,bool stayInStack=0)
{
    char temp[500];
    if(symbolTable[ID].scope==0)
        pb.push_back("li $s1, 0");    
    else
        pb.push_back("lw $s1,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
    pb.push_back("add $s1,$s1,$gp");
    if(symbolTable[ID].TYPE != SEM_TYPE_VARIABLE_INT)
    {
        myerror("variable is not declared yet!!",14);
        
    }
    pb.push_back("addi $s2,$s1, "+to_string(symbolTable[ID].address));
    pb.push_back("lw $s0, 0($s2)");
    //sprintf(temp,"lw $s0,%llu($gp)",symbolTable[ID].address);
    //pb.push_back(temp);
    //pb.push_back("li $s1, "+to_string(sum));
    pb.push_back("addi $s2,$s0, "+to_string(sum));
    if(stayInStack)
    {
        pb.push_back("addi $sp, $sp,-4"); 
        pb.push_back("sw $s0,0($sp)");
    }
    pb.push_back("addi $sp, $sp,-4"); 
    pb.push_back("sw $s2,0($sp)");
    
    assignto(ID);
}
void plusPlusar(string ID,int sum,bool stayInStack=0)
{
    pb.push_back("lw $s2,0($sp)"); // index to s2
    pb.push_back("addi $sp, $sp,4"); 

    pb.push_back("li $s1, 4"); 

    pb.push_back("mul $s1,$s2,$s1");
    if(symbolTable[ID].TYPE != SEM_TYPE_VARIABLE_ARRAY_INT)
    {
        myerror("array is not declared yet!!",14);
        
    }
    pb.push_back("add $s1,$s1,$gp");
    pb.push_back("addi $s2,$s1, "+to_string(symbolTable[ID].address));
    pb.push_back("lw $s0, 0($s2)");
    //sprintf(temp,"lw $s0,%llu($gp)",symbolTable[ID].address);
    //pb.push_back(temp);
    //pb.push_back("li $s1, "+to_string(sum));
    pb.push_back("addi $s2,$s0, "+to_string(sum));
    if(stayInStack)
    {
        pb.push_back("addi $sp, $sp,-4"); 
        pb.push_back("sw $s0,0($sp)");
    }
    pb.push_back("addi $sp, $sp,-4"); 
    pb.push_back("sw $s2,0($sp)");
    
    assigntoar(ID);
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
void removeLocal()
{
    if(localCount<=2)
        return;
    
    for(map<string,Node>::iterator it = symbolTable.begin();it != symbolTable.end();it++)
    { 
        
		if(it->second.scope==localCount)
        {
            
            cout<<"local variable \""<<it->first<<"\" block finished:"<<endl;
            cout<<"\t";
            it->second.print(1);
            cout<<endl;
            symbolTable.erase(it);
        }
    }
}
void voidReturn(string name)
{

    pb.push_back("lw $s0,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
    pb.push_back("addi $s0,$s0, "+to_string(-(symbolTable[name].size)));
    pb.push_back("sw $s0,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");

    pb.push_back("lw $ra, 0($sp)");  // pop to $ra
    pb.push_back("addi $sp, $sp,4"); 

    pb.push_back("addi $sp, $sp,-4");  // push from $v0
    pb.push_back("sw $v0, 0($sp)"); 
    pb.push_back("jr $ra");
}
void returnHandle(string name)
{
    symbolTable[lastScope].output=1;

    if(symbolTable[lastScope].TYPE==SEM_TYPE_FUNCTION_VOID)
    {
        warning("warning void function can't return any value!");
        
    }else{
    pb.push_back("lw $v0, 0($sp)");    // pop to $v0
    }
    pb.push_back("addi $sp, $sp,4");
    voidReturn(name);
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
        //makeFree(cur.address,cur.size);
        removeItemFromSymbolTable(cur.name);
    }
    while(!my_stack.empty())
    {
        Node tmp=my_stack.top();
        symbolTable[tmp.name]=tmp;
        my_stack.pop();
        //pb.push_back("sw $s0,"+to_string(symbolTable[tmp.name].address)+"($gp)");
    }
    if(symbolTable[ID].TYPE==SEM_TYPE_FUNCTION_INT)
    {
        
        if(!symbolTable[ID].output)
        {

            warning("warning return is missing (0 is considerd!)");
            pb.push_back("li $v0,0");
            
        }
       
            
        /*
        pb.push_back("lw $v0, 0($sp)"); 
        pb.push_back("addi $sp, $sp,4");   // pop to $v0
*/      

    }
    /*
    pb.push_back("lw $ra, 0($sp)");  // pop to $ra
    pb.push_back("addi $sp, $sp,4"); 

    pb.push_back("addi $sp, $sp,-4");  // push from $v0
    pb.push_back("sw $v0, 0($sp)"); 
    pb.push_back("jr $ra");*/
    
    voidReturn(ID);
}

void save()
{
    pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
    push(pb.size());
    pb.push_back("");
}
void whileJump()
{
    instJump.push(pb.size()+2);
    pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+2);
    int a=pop()+1;
    instJump.push(a);
    pb.push_back("j a"+to_string(a));
    //  pb.push_back("j "+to_string(pop()+1));              ??//
    //cout<<"EEE"<<pop()<<endl;
}
void forJump()
{
    int a=pop();
    //pb.push_back("j "+ to_string(a+3));               ??//
    pb.push_back("j a"+ to_string(a+3));
    instJump.push(a+3);
    pb[a]="beq $s0,$zero, a"+to_string(pb.size()+1);
    instJump.push(pb.size()+1);
}
void jump()
{
    //pb[pop()]="j "+ to_string(pb.size()+1);         ??//
    pb[pop()]="j a"+ to_string(pb.size()+1);   
    instJump.push(pb.size()+1); 
}
void saveJump()
{
    int top=pop();
    //int top_1=pop();
    
    pb[top]="beq $s0,$zero, a"+to_string(pb.size()+2);
    instJump.push(pb.size()+2);
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
void declare_IntArray(string name,int ss)
{
    Node tmp=Node();
    if(symbolTable[name].TYPE==SEM_TYPE_VARIABLE_ARRAY_INT)
    {
        myerror("array already declered!!!",88);
        return ;
    }
    tmp.name=name;
    tmp.size=ss;
    tmp.scope=0;
    tmp.address=getFree(ss,1);
    tmp.numOfArguments=-1;
    tmp.TYPE=SEM_TYPE_VARIABLE_ARRAY_INT;
    symbolTable[name]=tmp;
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