 #include<iostream>
 #include<string>
 #define Max 20
 using namespace std;
 //class Stack 
 class stack
 {
  char stack[Max]; // array of characters
  int top;
  public:
   Stack() // constructor to initialize top
   {
     top = -1;
   }
    int isempty(); // function to check empty condition
    int isfull(); // function to check full condition
    void push(char ch); // to push a character into stack
    char pop(); // function to pop a character from stack
    char getTop(); // function to get the top element of
     stack
 };
 int Stack::isempty()
 {
  if(top == -1)
  return 1;
 else
  return 0;
 }
 int Stack::isfull()
 {
  if(top == Max - 1)
  return 1;
 else
  return 0;
 }
 void Stack::push(char ch)
 {
  if(isfull())
  cout << "\nStack full";
 else
 {
  top++;
  stack[top] = ch;
 }
 }
 char Stack::pop()
 {
 char ch;
 if(isempty())
 cout << "\n stack empty \n";
 else
 {
 ch = stack[top];
 top--;
 }
 return(ch);
 }
 char Stack::getTop()
 {
 char ch;
 if(isempty())
 cout << "\n stack empty \n";
 else
 {
 ch = stack[top];
 }
 return(ch);
 }
 // Function to get in-stack priority 
 char isp(char ch)
 {
 switch(ch)
{
 case ‘+’:
 case ‘-’:return 1;
 case ‘*’:
 case ‘/’:return 2;
 case ‘^’:return 3;
 case ‘(‘:return 0;
 case ‘#’:return -2;
 }
 }
 // Function to get incoming priority 
 char icp(char ch)
 {
 switch(ch)
 {
 case ‘+’:
 case ‘-’:
 return 1;
 case ‘*’:
 case ‘/’:
 return 2;
 case ‘^’:
 return 3;
 case ‘(‘:
 return 4;
 }
 }
 void intopost(char infix[20],char postfix[20])
 {
 int i = 0;
 char ch, x;
 stack s;
 s.push(‘#’);
 while(infi x[i]! = ‘\0’) 
 // extract character till end of expression
 {
 ch = infi x[i];
 i++;
 if(ch >= ‘a’ && ch <= ‘z’) // operand
 {
 cout << ch;
 }
 else // operator
 {
 if(ch == ‘(‘)
 {
 while(s.getTop()! = ‘(‘)
 {
 x = s.pop();
 cout << x;
 }
 x = s.pop();
 }
 else
 {
 while(isp(s.getTop()) >= icp(ch)) 
 {
 x = s.pop();
 cout << x;
 }
 s.push(ch);
 }
 }
 }
 while(!s.isempty())
 {
 x = s.pop();
 if(x != ‘#’)
 cout << x;
 }
 }
 void intopre(char infi x[20],char prefi x[20])
 {
 int i, j;
 char ch, x;
 stack s;
 s.push(‘#’);
 i = strlen(infi x) - 1;
 j = 0;
 while(i! = -1)
 {
 ch = infi x[i];
i--;
 if(ch >= ‘a’ && ch <= ‘z’)
 {
 prefi x[j] = ch;
 j++;
 }
 else
 {
 if(ch == ‘(‘)
 {
 while(s.getTop()! = ‘)’)
 {
 x = s.pop();
 prefi x[j] = x;
 j++;
 }
 x = s.pop();
 }
 else
 {
 while(isp(s.getTop()) > icp(ch))
 {
 x = s.pop();
 prefi x[j] = x;
 j++;
 }
 s.push(ch);
 }
 }
 }
 while(!s.isempty())
 {
 x = s.pop();
 if(x! = ‘#’)
 prefi x[j] = x;
 j++;
 }
 prefi x[j] = ‘\0’;
 strrev(prefi x);
 }
 void main()
 {
 char infix[20], postfix[20], prefix[20];
 int choice;
 do
 {
 cout<< "\nMenu............";
 cout<< "\n1.Infix to postfix conversion";
 cout<< "\n2.Infix to prefix conversion";
 cout<< "\nEnter your choice:";
 cin>> choice;
 switch(choice)
 {
 case 1:
 cout<< "\nEnter the infi x expression:";
 cin>> infix;
 cout<< "\nPostfi x expression is:";
 intopost(infix,postfix);
 break;
 case 2:
 cout << "\nEnter the infi x expression:";
 cin >> infi x;
 intopre(infix,prefix);
 cout << "\nPrefi x expression is:" <<prefi x;
 break;
 }
 }
 while(choice < 3);
 }

