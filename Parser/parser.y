%{
#include<bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;

int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE* fp;
SymbolTable *st = new SymbolTable(7);
int line_count=1;
int error=0;
void IncLine(){
	line_count++;}
int getline()
	{return line_count;}
void IncErr(){
	error++;}
int getErr()
	{return error;}

void yyerror(char *s)
{
	//write your code
	cout<<"Syntax Error"<<endl;
}


%}
%union {
int ival;
SymbolInfo* siv;
vector<SymbolInfo*>* vecv;
}
%token <siv> IF ELSE FOR WHILE DEFAULT VOID CHAR INT DOUBLE MAIN RETURN FLOAT PRINTLN DO
%token <siv> ADDOP INCOP DECOP MULOP ASSIGNOP RELOP LOGICOP NOT 
%token <siv> LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA SEMICOLON
%token <siv> ID CONST_INT CONST_CHAR CONST_FLOAT
%type <vecv> func_declaration
%type <vecv> func_declaration

%%

start : program
	{
		$$=new vector<SymbolInfo*>();
		for (SymbolInfo* x : $1)
			$$->push_back(x);
		cout<<"At line no :"<<getline()<<"start : program"<<endl;
		for (SymbolInfo* x : $$)
			cout<<x->get_name()<<endl;
		cout<<endl;
	}
	;

program : program unit 	{
					$$=new vector<SymbolInfo*>();
					for (SymbolInfo* x : $1)
						$$->push_back(x);
					for (SymbolInfo* x : $2)
						$$->push_back(x);
					cout<<"At line no :"<<getline()<<"program : unit"<<endl;
					for (SymbolInfo* x : $$)
						cout<<x->get_name()<<endl;
					cout<<endl;
				}
	| unit			{
					$$=new vector<SymbolInfo*>();
					for (SymbolInfo* x : $1)
						$$->push_back(x);
					cout<<"At line no :"<<getline()<<"program : unit"<<endl;
					for (SymbolInfo* x : $$)
						cout<<x->get_name()<<endl;
					cout<<endl;
				}
	;
	
unit : var_declaration		{
					$$=new vector<SymbolInfo*>();
					for (SymbolInfo* x : $1)
						$$->push_back(x);
					cout<<"At line no :"<<getline()<<"unit : var_declaration"<<endl;
					for (SymbolInfo* x : $$)
						cout<<x->get_name()<<endl;
					cout<<endl;
				}
     | func_declaration	{
     					$$=new vector<SymbolInfo*>();
					for (SymbolInfo* x : $1)
						$$->push_back(x);
					cout<<"At line no :"<<getline()<<"unit : func_declaration"<<endl;
					for (SymbolInfo* x : $$)
						cout<<x->get_name()<<endl;
					cout<<endl;
     				}
     | func_definition		{
     					$$=new vector<SymbolInfo*>();
					for (SymbolInfo* x : $1)
						$$->push_back(x);
					cout<<"At line no :"<<getline()<<"unit : func_definition"<<endl;
					for (SymbolInfo* x : $$)
						cout<<x->get_name()<<endl;
					cout<<endl;
     				}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{
											cout<<"At line no :"<<getline()<<"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back($2);
											for (SymbolInfo* x : $4)
											{
      											  $$->push_back(x);
      											 }
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											for (SymbolInfo* x : $$)
											{
      											  cout<<x->get_name();
      											}
      											cout<<endl;
											
		
										}
		| type_specifier ID LPAREN RPAREN SEMICOLON			{
											cout<<"At line no :"<<getline()<<"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											for (SymbolInfo* x : $$)
											{
      											  cout<<x->get_name();
      											}
      											cout<<endl;
											
		
										}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement	{
												cout<<"At line no :"<<getline()<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											for (SymbolInfo* x : $4)
											{
      											  $$->push_back(x);
      											 }
											$$->push_back(new SymbolInfo(")","RPAREN"));
											for (SymbolInfo* x : $6)
											{
      											  $$->push_back(x);
      											 }
											for (SymbolInfo* x : $$)
											{
      											  cout<<x->get_name();
      											}
      											cout<<endl;
											}
		| type_specifier ID LPAREN RPAREN compound_statement			{
											cout<<"At line no :"<<getline()<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											for (SymbolInfo* x : $5)
											{
      											  $$->push_back(x);
      											 }
											for (SymbolInfo* x : $$)
											{
      											  cout<<x->get_name();
      											}
      											cout<<endl;
											}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID	{
									cout<<"At line no :"<<getline()<<"parameter_list  : parameter_list COMMA type_specifier ID"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									$$->push_back($4);
									for (SymbolInfo* x : $$)
									{
      										cout<<x->get_name();
      									}
      									cout<<endl;	
								}
		| parameter_list COMMA type_specifier		{
									cout<<"At line no :"<<getline()<<"parameter_list  : parameter_list COMMA type_specifier"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		| type_specifier ID				{
									cout<<"At line no :"<<getline()<<"parameter_list  : type_specifier ID"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									$$->push_back($2);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
		| type_specifier				{
									cout<<"At line no :"<<getline()<<"parameter_list  : type_specifier"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		;

 		
compound_statement : LCURL statements RCURL			{
									cout<<"At line no :"<<getline()<<"compound_statement : LCURL statements RCURL"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("{","LCURL"));
									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo("}","RCURL"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		    | LCURL RCURL				{
									cout<<"At line no :"<<getline()<<"compound_statement : LCURL  RCURL"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("{","LCURL"));
      									$$->push_back(new SymbolInfo("}","RCURL"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON	{
									cout<<"At line no :"<<getline()<<"var_declaration : type_specifier declaration_list SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		 ;
 		 
type_specifier	: INT		{
					cout<<"At line no :"<<getline()<<"type_specifier : INT"<<endl;
					$$->push_back(new SymbolInfo("int","INT"));
					cout<<$$->get_name()<<endl;
				}
 		| FLOAT	{
					cout<<"At line no :"<<getline()<<"type_specifier : FLOAT"<<endl;
					$$->push_back(new SymbolInfo("void","FLOAT"));
					cout<<$$->get_name()<<endl;
				}
 		| VOID		{
					cout<<"At line no :"<<getline()<<"type_specifier : VOID"<<endl;
					$$->push_back(new SymbolInfo("void","VOID"));
					cout<<$$->get_name()<<endl;
				}
 		;
 		
declaration_list : declaration_list COMMA ID			{
									cout<<"At line no :"<<getline()<<"declaration_list : declaration_list COMMA ID"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(",","COMMA"));
      									$$->push_back($3);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
										
								}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD	{
										cout<<"At line no :"<<getline()<<"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
										$$=new vector<SymbolInfo*>();
										for (SymbolInfo* x : $1)
										{
      										$$->push_back(x);
      										}
      										$$->push_back(new SymbolInfo(",","COMMA"));
      										$$->push_back($3);
      										$$->push_back(new SymbolInfo("[","LTHIRD"));
      										$$->push_back($5);
      										$$->push_back(new SymbolInfo("]","RTHIRD"));
										for (SymbolInfo* x : $$)
										{
      										cout<<x->get_name();
      										}
      										cout<<endl;
										
										}
 		  | ID						{
 		  							cout<<"At line no :"<<getline()<<"declaration_list : ID"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
 		  | ID LTHIRD CONST_INT RTHIRD		{
 		  							cout<<"At line no :"<<getline()<<"declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									$$->push_back($3);
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
 		  ;
 		  
statements : statement						{
 		  							cout<<"At line no :"<<getline()<<"statements : statement"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}		
	   | statements statement				{
 		  							cout<<"At line no :"<<getline()<<"statements : statements statement"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	   ;
	   
statement : var_declaration					{
 		  							cout<<"At line no :"<<getline()<<"statement : var_declaration"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | expression_statement				{
 		  							cout<<"At line no :"<<getline()<<"statement : expression_statement"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | compound_statement					{
 		  							cout<<"At line no :"<<getline()<<"statement : compound_statement"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
	  													cout<<"At line no :"<<getline()<<"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
														$$=new vector<SymbolInfo*>();
														$$->push_back(new SymbolInfo("for","FOR"));
														$$->push_back(new SymbolInfo("(","LPAREN"));
														for (SymbolInfo* x : $3)
														{
      														$$->push_back(x);
      														}
      														for (SymbolInfo* x : $4)
														{
      														$$->push_back(x);
      														}
      														$$->push_back(new SymbolInfo(")","RPAREN"));
      														for (SymbolInfo* x : $6)
														{
      														$$->push_back(x);
      														}
														for (SymbolInfo* x : $$)
														{
      														cout<<x->get_name();
      														}
      														cout<<endl;	
	  												}
	  | IF LPAREN expression RPAREN statement		{
 		  							cout<<"At line no :"<<getline()<<"statement : IF LPAREN expression RPAREN statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									for (SymbolInfo* x : $5)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | IF LPAREN expression RPAREN statement ELSE statement	{
 		  							cout<<"At line no :"<<getline()<<"statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									for (SymbolInfo* x : $5)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo("else","ELSE"));
      									for (SymbolInfo* x : $7)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  							}
	  | WHILE LPAREN expression RPAREN statement		{
 		  							cout<<"At line no :"<<getline()<<"statement : WHILE LPAREN expression RPAREN statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("while","WHILE"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									for (SymbolInfo* x : $5)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON		{
 		  							cout<<"At line no :"<<getline()<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("print","PRINTLN"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									$$->push_back($3);
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  | RETURN expression SEMICOLON			{
 		  							cout<<"At line no :"<<getline()<<"statement : RETURN expression SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("return","RETURN"));
									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	  ;
	  
expression_statement 	: SEMICOLON				{
 		  							cout<<"At line no :"<<getline()<<"expression_statement 	: SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
			| expression SEMICOLON 		{
 		  							cout<<"At line no :"<<getline()<<"expression_statement 	: expression SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
			;
	  
variable : ID 							{
 		  							cout<<"At line no :"<<getline()<<"variable : ID"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	 | ID LTHIRD expression RTHIRD 			{
 		  							cout<<"At line no :"<<getline()<<"variable : ID"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	 ;
	 
 expression : logic_expression				{
 		  							cout<<"At line no :"<<getline()<<"expression : logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	   | variable ASSIGNOP logic_expression 		{
 		  							cout<<"At line no :"<<getline()<<"expression : variable ASSIGNOP logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	   ;
			
logic_expression : rel_expression 				{
 		  							cout<<"At line no :"<<getline()<<"logic_expression : rel_expression "<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		 | rel_expression LOGICOP rel_expression 	{
 		  							cout<<"At line no :"<<getline()<<"logic_expression : rel_expression "<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		 ;
			
rel_expression	: simple_expression 				{
 		  							cout<<"At line no :"<<getline()<<"rel_expression	: simple_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		| simple_expression RELOP simple_expression	{
 		  							cout<<"At line no :"<<getline()<<"rel_expression	: simple_expression RELOP simple_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		;
				
simple_expression : term 					{
 		  							cout<<"At line no :"<<getline()<<"simple_expression : term "<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		  | simple_expression ADDOP term 		{
 		  							cout<<"At line no :"<<getline()<<"simple_expression : simple_expression ADDOP term "<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		  ;
					
term :	unary_expression					{
 		  							cout<<"At line no :"<<getline()<<"term :	unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
     |  term MULOP unary_expression				{
 		  							cout<<"At line no :"<<getline()<<"term : term MULOP unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
     ;

unary_expression : ADDOP unary_expression  			{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : ADDOP unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		 | NOT unary_expression 			{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : NOT unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("!","NOT"));
      									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		 | factor 					{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : NOT unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		 ;
	
factor	: variable 						{
 		  							cout<<"At line no :"<<getline()<<"factor : variable "<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| ID LPAREN argument_list RPAREN			{
 		  							cout<<"At line no :"<<getline()<<"factor : ID LPAREN argument_list RPAREN"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| LPAREN expression RPAREN				{
 		  							cout<<"At line no :"<<getline()<<"factor : LPAREN expression RPAREN"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									for (SymbolInfo* x : $2)
									{
      										$$->push_back(x);
      									}
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| CONST_INT 						{
 		  							cout<<"At line no :"<<getline()<<"factor : CONST_INT"<<endl;
									$$=new vector<SymbolInfo*>(
      									$$->push_back($1);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| CONST_FLOAT						{
 		  							cout<<"At line no :"<<getline()<<"factor : CONST_FLOAT "<<endl;
									$$=new vector<SymbolInfo*>(
      									$$->push_back($1);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| variable INCOP 					{
 		  							cout<<"At line no :"<<getline()<<"factor : variable INCOP"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	| variable DECOP					{
 		  							cout<<"At line no :"<<getline()<<"factor : variable DECOP"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back($2);
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	;
	
argument_list : arguments					{
 		  							cout<<"At line no :"<<getline()<<"argument_list : arguments"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
		|						{
 		  							cout<<"At line no :"<<getline()<<"argument_list : "<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("","EMPTY"));
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
			  ;
	
arguments : arguments COMMA logic_expression			{
 		  							cout<<"At line no :"<<getline()<<"arguments : arguments COMMA logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
      									$$->push_back(new SymbolInfo(",","COMMA"));
      									for (SymbolInfo* x : $3)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	      | logic_expression				{
 		  							cout<<"At line no :"<<getline()<<"arguments : logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									for (SymbolInfo* x : $1)
									{
      										$$->push_back(x);
      									}
									for (SymbolInfo* x : $$)
									{
      									cout<<x->get_name();
      									}
      									cout<<endl;
 		  						}
	      ;
 

%%
int main(int argc,char *argv[])
{

	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}


	yyin=fp;
	yyparse();
	

	
	return 0;
}

