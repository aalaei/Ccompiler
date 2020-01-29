#ifndef MYDEF
#define MYDEF
 //start
 
 stack<int> semantic_stack; 
 int i=0;
 vector<string> pb;
 
 long long getFree()
 {
     return Cur_Mem_tmp++;
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

//end
#endif