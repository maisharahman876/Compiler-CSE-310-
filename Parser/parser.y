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
%type <vecv> start program unit var_declaration func_declaration func_definition parameter_list term rel_expression
%type <vecv> compound_statement declaration_list statements statement expression_statement variable expression logic_expression
%type <vecv> unary_expression factor argument_list arguments simple_expression
%type <siv> type_specifier
%nonassoc nothing
%nonassoc ELSE
%%

start : program
	{
		$$=new vector<SymbolInfo*>();
		vector<SymbolInfo*>::iterator i;
		for (i = $1->begin(); i != $1->end(); ++i) 
		$$->push_back((*i));
		cout<<"At line no :"<<getline()<<"start : program"<<endl;
		for (i = $$->begin(); i != $$->end(); ++i) 
			cout<<(*i)->get_name()<<endl;
		cout<<endl;
	}
	;

program : program unit 	{
					vector<SymbolInfo*>::iterator i;
					$$=new vector<SymbolInfo*>();
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					for (i = $2->begin(); i != $2->end(); ++i) 
						$$->push_back(*i);
					cout<<"At line no :"<<getline()<<"program : unit"<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
				}
	| unit			{
					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"At line no :"<<getline()<<"program : unit"<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
				}
	;
	
unit : var_declaration		{
					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"At line no :"<<getline()<<"unit : var_declaration"<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
				}
     | func_declaration	{
     					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"At line no :"<<getline()<<"unit : func_declaration"<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
     				}
     | func_definition		{
     					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"At line no :"<<getline()<<"unit : func_definition"<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
     				}
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON	{
											cout<<"At line no :"<<getline()<<"func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back($2);
											vector<SymbolInfo*>::iterator i;
											for (i = $4->begin(); i != $4->end(); ++i) 
												$$->push_back((*i));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
											
		
										}
		| type_specifier ID LPAREN RPAREN SEMICOLON			{
											cout<<"At line no :"<<getline()<<"func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
											vector<SymbolInfo*>::iterator i;
					
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											for (i = $$->begin(); i != $$->end(); ++i) 
											cout<<(*i)->get_name();
      											cout<<endl;
											
		
										}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement	{
												cout<<"At line no :"<<getline()<<"func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = $4->begin(); i != $4->end(); ++i) 
												$$->push_back((*i));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											for (i = $6->begin(); i != $6->end(); ++i) 
												$$->push_back((*i));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
											}
		| type_specifier ID LPAREN RPAREN compound_statement			{
											cout<<"At line no :"<<getline()<<"func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
											
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = $5->begin(); i != $5->end(); ++i) 
												$$->push_back((*i));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
											}
 		;				


parameter_list  : parameter_list COMMA type_specifier ID	{
									cout<<"At line no :"<<getline()<<"parameter_list  : parameter_list COMMA type_specifier ID"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									$$->push_back($4);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;	
								}
		| parameter_list COMMA type_specifier		{
									cout<<"At line no :"<<getline()<<"parameter_list  : parameter_list COMMA type_specifier"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		| type_specifier ID				{
									cout<<"At line no :"<<getline()<<"parameter_list  : type_specifier ID"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									$$->push_back($1);
									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
		| type_specifier				{
									cout<<"At line no :"<<getline()<<"parameter_list  : type_specifier"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		;

 		
compound_statement : LCURL statements RCURL			{
									cout<<"At line no :"<<getline()<<"compound_statement : LCURL statements RCURL"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("{","LCURL"));
									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo("}","RCURL"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		    | LCURL RCURL				{
									cout<<"At line no :"<<getline()<<"compound_statement : LCURL  RCURL"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;

									$$->push_back(new SymbolInfo("{","LCURL"));
      									$$->push_back(new SymbolInfo("}","RCURL"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON	{
									cout<<"At line no :"<<getline()<<"var_declaration : type_specifier declaration_list SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		 ;
 		 
type_specifier	: INT		{
					cout<<"At line no :"<<getline()<<"type_specifier : INT"<<endl;
					$$=new SymbolInfo("int","INT");
					cout<<$$->get_name()<<endl;
				}
 		| FLOAT	{
					cout<<"At line no :"<<getline()<<"type_specifier : FLOAT"<<endl;
					$$=new SymbolInfo("void","FLOAT");
					cout<<$$->get_name()<<endl;
				}
 		| VOID		{
					cout<<"At line no :"<<getline()<<"type_specifier : VOID"<<endl;
					$$=new SymbolInfo("void","VOID");
					cout<<$$->get_name()<<endl;
				}
 		;
 		
declaration_list : declaration_list COMMA ID			{
									cout<<"At line no :"<<getline()<<"declaration_list : declaration_list COMMA ID"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(",","COMMA"));
      									$$->push_back($3);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD	{
										cout<<"At line no :"<<getline()<<"declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
										$$=new vector<SymbolInfo*>();
										vector<SymbolInfo*>::iterator i;
										for (i = $1->begin(); i != $1->end(); ++i) 
											$$->push_back((*i));
      										$$->push_back(new SymbolInfo(",","COMMA"));
      										$$->push_back($3);
      										$$->push_back(new SymbolInfo("[","LTHIRD"));
      										$$->push_back($5);
      										$$->push_back(new SymbolInfo("]","RTHIRD"));
										for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      										cout<<endl;
										
										}
 		  | ID						{
 		  							cout<<"At line no :"<<getline()<<"declaration_list : ID"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
 		  | ID LTHIRD CONST_INT RTHIRD		{
 		  							cout<<"At line no :"<<getline()<<"declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									$$->push_back($1);
									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									$$->push_back($3);
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
 		  ;
 		  
statements : statement						{
 		  							cout<<"At line no :"<<getline()<<"statements : statement"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}		
	   | statements statement				{
 		  							cout<<"At line no :"<<getline()<<"statements : statements statement"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	   ;
	   
statement : var_declaration					{
 		  							cout<<"At line no :"<<getline()<<"statement : var_declaration"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | expression_statement				{
 		  							cout<<"At line no :"<<getline()<<"statement : expression_statement"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | compound_statement					{
 		  							cout<<"At line no :"<<getline()<<"statement : compound_statement"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
	  													cout<<"At line no :"<<getline()<<"statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
														$$=new vector<SymbolInfo*>();
														$$->push_back(new SymbolInfo("for","FOR"));
														$$->push_back(new SymbolInfo("(","LPAREN"));
														vector<SymbolInfo*>::iterator i;
														for (i = $3->begin(); i != $3->end(); ++i) 
															$$->push_back((*i));
      														
														for (i = $4->begin(); i != $4->end(); ++i) 
															$$->push_back((*i));
      														for (i = $5->begin(); i != $5->end(); ++i) 
															$$->push_back((*i));
      														$$->push_back(new SymbolInfo(")","RPAREN"));
      														
														for (i = $7->begin(); i != $7->end(); ++i) 
														$$->push_back((*i));
														for (i = $$->begin(); i != $$->end(); ++i) 
														cout<<(*i)->get_name();
      														cout<<endl;	
	  												}
	  | IF LPAREN expression RPAREN statement %prec nothing		{
 		  							cout<<"At line no :"<<getline()<<"statement : IF LPAREN expression RPAREN statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | IF LPAREN expression RPAREN statement ELSE statement	{
 		  							cout<<"At line no :"<<getline()<<"statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo("else","ELSE"));
      									
									for (i = $7->begin(); i != $7->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  							}
	  | WHILE LPAREN expression RPAREN statement		{
 		  							cout<<"At line no :"<<getline()<<"statement : WHILE LPAREN expression RPAREN statement"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("while","WHILE"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | PRINTLN LPAREN ID RPAREN SEMICOLON		{
 		  							cout<<"At line no :"<<getline()<<"statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("print","PRINTLN"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									$$->push_back($3);
      									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  | RETURN expression SEMICOLON			{
 		  							cout<<"At line no :"<<getline()<<"statement : RETURN expression SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("return","RETURN"));
									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	  ;
	  
expression_statement 	: SEMICOLON				{
 		  							cout<<"At line no :"<<getline()<<"expression_statement 	: SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
			| expression SEMICOLON 		{
 		  							cout<<"At line no :"<<getline()<<"expression_statement 	: expression SEMICOLON"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
			;
	  
variable : ID 							{
 		  							cout<<"At line no :"<<getline()<<"variable : ID"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	 | ID LTHIRD expression RTHIRD 			{
 		  							cout<<"At line no :"<<getline()<<"variable : ID"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	 ;
	 
 expression : logic_expression				{
 		  							cout<<"At line no :"<<getline()<<"expression : logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	   | variable ASSIGNOP logic_expression 		{
 		  							cout<<"At line no :"<<getline()<<"expression : variable ASSIGNOP logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	   ;
			
logic_expression : rel_expression 				{
 		  							cout<<"At line no :"<<getline()<<"logic_expression : rel_expression "<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		 | rel_expression LOGICOP rel_expression 	{
 		  							cout<<"At line no :"<<getline()<<"logic_expression : rel_expression "<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		 ;
			
rel_expression	: simple_expression 				{
 		  							cout<<"At line no :"<<getline()<<"rel_expression	: simple_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		| simple_expression RELOP simple_expression	{
 		  							cout<<"At line no :"<<getline()<<"rel_expression	: simple_expression RELOP simple_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		;
				
simple_expression : term 					{
 		  							cout<<"At line no :"<<getline()<<"simple_expression : term "<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		  | simple_expression ADDOP term 		{
 		  							cout<<"At line no :"<<getline()<<"simple_expression : simple_expression ADDOP term "<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		  ;
					
term :	unary_expression					{
 		  							cout<<"At line no :"<<getline()<<"term :	unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
     |  term MULOP unary_expression				{
 		  							cout<<"At line no :"<<getline()<<"term : term MULOP unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
     ;

unary_expression : ADDOP unary_expression  			{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : ADDOP unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		 | NOT unary_expression 			{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : NOT unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("!","NOT"));
      									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		 | factor 					{
 		  							cout<<"At line no :"<<getline()<<"unary_expression : NOT unary_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		 ;
	
factor	: variable 						{
 		  							cout<<"At line no :"<<getline()<<"factor : variable "<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| ID LPAREN argument_list RPAREN			{
 		  							cout<<"At line no :"<<getline()<<"factor : ID LPAREN argument_list RPAREN"<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| LPAREN expression RPAREN				{
 		  							cout<<"At line no :"<<getline()<<"factor : LPAREN expression RPAREN"<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| CONST_INT 						{
 		  							cout<<"At line no :"<<getline()<<"factor : CONST_INT"<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| CONST_FLOAT						{
 		  							cout<<"At line no :"<<getline()<<"factor : CONST_FLOAT "<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| variable INCOP 					{
 		  							cout<<"At line no :"<<getline()<<"factor : variable INCOP"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	| variable DECOP					{
 		  							cout<<"At line no :"<<getline()<<"factor : variable DECOP"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	;
	
argument_list : arguments					{
 		  							cout<<"At line no :"<<getline()<<"argument_list : arguments"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
		|						{
 		  							cout<<"At line no :"<<getline()<<"argument_list : "<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo("","EMPTY"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
			  ;
	
arguments : arguments COMMA logic_expression			{
 		  							cout<<"At line no :"<<getline()<<"arguments : arguments COMMA logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(",","COMMA"));
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
 		  						}
	      | logic_expression				{
 		  							cout<<"At line no :"<<getline()<<"arguments : logic_expression"<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
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

