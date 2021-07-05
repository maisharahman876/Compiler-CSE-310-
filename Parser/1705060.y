%{
#include<bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;
ofstream error;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE* fp;
SymbolTable *st = new SymbolTable(30);

int line_count=1;
int err=0;
void IncLine(){
	line_count++;}
int getline()
	{return line_count;}
void IncErr(){
	err++;}
int getErr()
	{return err;}

void yyerror(char *s)
{
	//write your code
	cout<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	error<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	IncErr();
}
bool func=false;
string type,name,namef,typef;
vector<param*>plist;
vector<string>arglist;
vector<SymbolInfo*>vlist;
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
%type <siv> type_specifier id
%type <ival> newScope in_func
%nonassoc nothing
%nonassoc ELSE
%%

start : program
	{
		$$=new vector<SymbolInfo*>();
		vector<SymbolInfo*>::iterator i;
		for (i = $1->begin(); i != $1->end(); ++i) 
		$$->push_back((*i));
		cout<<"Line "<<getline()<<":"<<" start : program"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		$1->clear();
	}
	;

program : program unit 	{
					vector<SymbolInfo*>::iterator i;
					$$=new vector<SymbolInfo*>();
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					for (i = $2->begin(); i != $2->end(); ++i) 
						$$->push_back(*i);
					cout<<"Line "<<getline()<<":"<<" program : program unit"<<endl;
					cout<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					$1->clear();
					$2->clear();
				}
	| unit			{
					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" program : unit"<<endl;
					cout<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					$1->clear();
				}
	;
	
unit : var_declaration		{
					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : var_declaration"<<endl;
					cout<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					$1->clear();
				}
     | func_declaration	{
     					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : func_declaration"<<endl;
					cout<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					$1->clear();
     				}
     | func_definition		{
     					$$=new vector<SymbolInfo*>();
					vector<SymbolInfo*>::iterator i;
					for (i = $1->begin(); i != $1->end(); ++i) 
						$$->push_back((*i));
					cout<<"Line "<<getline()<<":"<<" unit : func_definition"<<endl;
					cout<<endl;
					for (i = $$->begin(); i != $$->end(); ++i) 
						cout<<(*i)->get_name();
					cout<<endl;
					cout<<endl;
					$1->clear();
     				}
     ;
     
func_declaration : type_specifier id in_func LPAREN parameter_list RPAREN lookup SEMICOLON	{
											cout<<"Line "<<getline()<<":"<<" func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON"<<endl;
											cout<<endl;
											vector<param*>::iterator j;
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo(" ","space"));
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = $5->begin(); i != $5->end(); ++i) 
												$$->push_back((*i));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											$$->push_back(new SymbolInfo("\n","newline"));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											func=false;
											for (j = plist.begin(); j != plist.end(); ++j)
											{
											delete (*j);
											}
											plist.clear();
											for (i= vlist.begin(); i != vlist.end(); ++i)
											{
											delete (*i);
											}
											vlist.clear();
											$5->clear();
		
										}
		| type_specifier id in_func LPAREN RPAREN lookup SEMICOLON			{
											cout<<"Line "<<getline()<<":"<<" func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON"<<endl;
											cout<<endl;
											
											vector<SymbolInfo*>::iterator i;
											vector<param*>::iterator j;
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo(" ","space"));
											$$->push_back($2);
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											$$->push_back(new SymbolInfo(";","SEMICOLON"));
											$$->push_back(new SymbolInfo("\n","newline"));
											for (i = $$->begin(); i != $$->end(); ++i) 
											cout<<(*i)->get_name();
											func=false;
											for (j = plist.begin(); j != plist.end(); ++j)
											{
											delete (*j);
											}
											plist.clear();
											for (i= vlist.begin(); i != vlist.end(); ++i)
											{
											delete (*i);
											}
											vlist.clear();
											
      											cout<<endl;
											cout<<endl;
		
										}
		;

id : ID {
		$$=new SymbolInfo($1->get_name(),"ID");
		name=$1->get_name();
		//func=true;
	}
;
in_func : {
		func=true;
		namef=name;
		typef=type;	
	  }
;
lookup: {
		vector<param*>::iterator j;
	 	if(st->lookup_symbol(namef)==NULL)
		{
		SymbolInfo* si=new SymbolInfo(namef,"ID",typef);
		si->set_func();
		
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		si->addParam((*j)->get_ptype(),(*j)->get_pname());
		delete (*j);
		}
		si->set_func();
		st->insert_symbol(si);
		plist.clear();
		typef.clear();
		namef.clear();
		}
		else
		{
		SymbolInfo* f=st->lookup_symbol(namef);
		if(!f->isFunc())
		{
		cout<<"Error at line "<<getline()<<":  function  with non-function type identifier "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": function  with non-function type identifier "<<namef<<endl<<endl;
		IncErr();
		}
		else
		{
		cout<<"Error at line "<<getline()<<": Multiple declaration of function "<<namef<<" in parameter"<<endl<<endl;
		error<<"Error at line "<<getline()<<": Multiple declaration of function"<<namef<<" in parameter"<<endl<<endl;
		IncErr();
		}
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		delete (*j);
		}
		plist.clear();
		}
		
	}
;
lookup1: {
	 	vector<param*>::iterator j;
	 	if(st->lookup_symbol(namef)==NULL)
		{
		SymbolInfo* si=new SymbolInfo(namef,"ID",typef);
		si->set_func();
		
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		si->addParam((*j)->get_ptype(),(*j)->get_pname());
		
		delete (*j);
		}
		si->set_func();
		//error<<namef<<" "<<si->get_listSize()<<endl;
		st->insert_symbol(si);
		plist.clear();
		
		}
		else
		{
		SymbolInfo* f=st->lookup_symbol(namef);
		if(!f->isFunc())
		{
		cout<<"Error at line "<<getline()<<":  Multiple declaration of "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Multiple declaration of "<<namef<<endl<<endl;
		IncErr();
		}
		else if(f->get_listSize()!=plist.size())
		{
		cout<<"Error at line "<<getline()<<":  Total number of arguments mismatch with declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Total number of arguments mismatch with declaration in function "<<namef<<endl<<endl;
		IncErr();
		}
		else {
		for(int k=0;k<plist.size();k++)
		{
		if((f->getParam(k))->get_ptype()!=plist[k]->get_ptype())
		{
		cout<<"Error at line "<<getline()<<":  Argument mismatch with declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<" : Argument mismatch with declaration in function "<<namef<<endl<<endl;
		IncErr();
		break;
		}
		}
		}
		if(typef!=f->get_dType())
		{
		cout<<"Error at line "<<getline()<<":  Return type mismatch with function declaration in function "<<namef<<endl<<endl;
		error<<"Error at line "<<getline()<<": Return type mismatch with function declaration in function "<<namef<<endl<<endl;
		IncErr();
		}
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		delete (*j);
		}
		plist.clear();
		//error<<namef<<" "<<f->get_listSize();
		}
		
	}
;		 
func_definition :   type_specifier id in_func LPAREN parameter_list RPAREN lookup1 compound_statement	{
												cout<<"Line "<<getline()<<":"<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement"<<endl;
											cout<<endl;
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo(" ","space"));
											$$->push_back($2);
											
											$$->push_back(new SymbolInfo("(","LPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = $5->begin(); i != $5->end(); ++i) 
												$$->push_back((*i));
											
											$$->push_back(new SymbolInfo(")","RPAREN"));
											for (i = $8->begin(); i != $8->end(); ++i) 
												$$->push_back((*i));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											$5->clear();
      											$8->clear();
											}
		| type_specifier id in_func LPAREN RPAREN lookup1 compound_statement			{
											cout<<"Line "<<getline()<<":"<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl;
											cout<<endl;
											$$=new vector<SymbolInfo*>();
											$$->push_back($1);
											$$->push_back(new SymbolInfo(" ","space"));
											$$->push_back($2);
											
											$$->push_back(new SymbolInfo("(","LPAREN"));
											$$->push_back(new SymbolInfo(")","RPAREN"));
											vector<SymbolInfo*>::iterator i;
											for (i = $7->begin(); i != $7->end(); ++i) 
												$$->push_back((*i));
											$7->clear();
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
											}
 		;				


parameter_list  : parameter_list COMMA type_specifier id	{
									cout<<"Line "<<getline()<<":"<<" parameter_list : parameter_list COMMA type_specifier ID"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									$$->push_back(new SymbolInfo(" ","space"));
									$$->push_back($4);
									param* p=new param($3->get_name(),$4->get_name());
									plist.push_back(p);
									SymbolInfo* si=new SymbolInfo($4->get_name(),"ID",$3->get_name());
									vlist.push_back(si);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();	
								}
		| parameter_list COMMA type_specifier		{
									cout<<"Line "<<getline()<<":"<<" parameter_list : parameter_list COMMA type_specifier"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									param* p=new param($3->get_name(),"");
									plist.push_back(p);
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									$$->push_back(new SymbolInfo(",","COMMA"));
									$$->push_back($3);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
										
								}
 		| type_specifier id				{
									cout<<"Line "<<getline()<<":"<<" parameter_list : type_specifier ID"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									param* p=new param($1->get_name(),$2->get_name());
									plist.push_back(p);
									SymbolInfo* si=new SymbolInfo($2->get_name(),"ID",$1->get_name());
									vlist.push_back(si);
									$$->push_back($1);
									$$->push_back(new SymbolInfo(" ","space"));
									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
									cout<<endl;
								}
		| type_specifier				{
									cout<<"Line "<<getline()<<":"<<" parameter_list : type_specifier"<<endl;
									param* p=new param($1->get_name(),"");
									plist.push_back(p);
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
										
								}
 		;

 		
compound_statement : LCURL newScope statements RCURL			{
									cout<<"Line "<<getline()<<":"<<" compound_statement : LCURL statements RCURL"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("{","LCURL"));
									
									$$->push_back(new SymbolInfo("\n","newline"));
									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo("}","RCURL"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									st->print_all();
      									st->exitScope();
      									$3->clear();
										
								}
 		    | LCURL newScope RCURL				{
									cout<<"Line "<<getline()<<":"<<" compound_statement : LCURL  RCURL"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;

									$$->push_back(new SymbolInfo("{","LCURL"));
									
									$$->push_back(new SymbolInfo("\n","newline"));
      									$$->push_back(new SymbolInfo("}","RCURL"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									st->print_all();
      									st->exitScope();
										
								}
 		    ;
newScope : 	{
			$$=-1;
			st->enterScope();
			if(func)
			{
		
			  vector<SymbolInfo*>::iterator j;
			  for ( j=vlist.begin(); j !=vlist.end(); ++j) 
			  {
			  	
			  	SymbolInfo* si=new SymbolInfo((*j)->get_name(),(*j)->get_type(),(*j)->get_dType());
			  	
			  	if(st->insert_symbol(si))
			  	{}
			  	else
			  	{
			  	cout<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				error<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				IncErr();
			  	}
			  	delete (*j);
			  }
			  vlist.clear();
			  func=false;
			}
			
			
		}
;		    
var_declaration : type_specifier declaration_list SEMICOLON	{
									cout<<"Line "<<getline()<<":"<<" var_declaration : type_specifier declaration_list SEMICOLON"<<endl;
									cout<<endl;
									bool a=true;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									type=$1->get_name();
									$$->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									if(type=="void")
									{
										cout<<"Error at line "<<getline()<<": Variable type cannot be void"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Variable type cannot be void"<<endl<<endl;
									
										IncErr();
										a=false;
										
									}
									for (i = $2->begin(); i != $2->end(); ++i) 
									{
										
										
										if(((*i)->get_type()=="ID")&&a)
										{
											//(*i)->set_dType(type);
											
											SymbolInfo* si=new SymbolInfo((*i)->get_name(),"ID",type);
											if(st->insert_symbol(si))
											{
											if((*i)->get_varSize()!=-1)
											   si->set_varSize((*i)->get_varSize());
											}
											else
											{
											cout<<"Error at line "<<getline()<<": Multiple declaration of "<<(*i)->get_name()<<endl<<endl;
											error<<"Error at line "<<getline()<<": Multiple declaration of "<<(*i)->get_name()<<endl<<endl;
									
											IncErr();
											}
											
										}
										$$->push_back((*i));
									}
									type.clear();
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$2->clear();
										
								}
 		 ;
 		 
type_specifier	: INT		{
					cout<<"Line "<<getline()<<":"<<" type_specifier : INT"<<endl;
					cout<<endl;
					$$=new SymbolInfo("int","INT");
					cout<<$$->get_name()<<endl;
					cout<<endl;
					type="int";
				}
 		| FLOAT	{
					cout<<"Line "<<getline()<<":"<<" type_specifier : FLOAT"<<endl;
					cout<<endl;
					$$=new SymbolInfo("float","FLOAT");
					cout<<$$->get_name()<<endl;
					cout<<endl;
					type="float";
				}
 		| VOID		{
					cout<<"Line "<<getline()<<":"<<" type_specifier : VOID"<<endl;
					cout<<endl;
					$$=new SymbolInfo("void","VOID");
					cout<<$$->get_name()<<endl;
					cout<<endl;
					type="void";
				}
 		;
 		
declaration_list : declaration_list COMMA id			{
									cout<<"Line "<<getline()<<":"<<" declaration_list : declaration_list COMMA ID"<<endl;
									cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(",","COMMA"));
      									$$->push_back($3);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
										
								}
 		  | declaration_list COMMA id LTHIRD CONST_INT RTHIRD	{
										cout<<"Line "<<getline()<<":"<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD"<<endl;
										cout<<endl;
										$$=new vector<SymbolInfo*>();
										vector<SymbolInfo*>::iterator i;
										for (i = $1->begin(); i != $1->end(); ++i) 
											$$->push_back((*i));
      										$$->push_back(new SymbolInfo(",","COMMA"));
      										$3->set_varSize(stoi($5->get_name()));
      										//cout<<$3->get_varSize()<<endl;;
      										$$->push_back($3);
      										$$->push_back(new SymbolInfo("[","LTHIRD"));
      										$$->push_back($5);
      										$$->push_back(new SymbolInfo("]","RTHIRD"));
										for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      										cout<<endl;
      										cout<<endl;
      										$1->clear();
										
										}
 		  | id						{
 		  							cout<<"Line "<<getline()<<":"<<" declaration_list : ID"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									
									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
 		  | id LTHIRD CONST_INT RTHIRD		{
 		  							cout<<"Line "<<getline()<<":"<<" declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									$1->set_varSize(stoi($3->get_name()));
									$$->push_back($1);
									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									$$->push_back($3);
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
 		  ;
 		  
statements : statement						{
 		  							cout<<"Line "<<getline()<<":"<<" statements : statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
 		  						}		
	   | statements statement				{
 		  							cout<<"Line "<<getline()<<":"<<" statements : statements statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
      									$2->clear();
 		  						}
	   ;
	   
statement : var_declaration					{
 		  							cout<<"Line "<<getline()<<":"<<" statement : var_declaration"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
 		  						}
	  | expression_statement				{
 		  							cout<<"Line "<<getline()<<":"<<" statement : expression_statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
 		  						}
	  | compound_statement					{
 		  							cout<<"Line "<<getline()<<":"<<" statement : compound_statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$1->clear();
 		  						}
	  | FOR LPAREN expression_statement expression_statement expression RPAREN statement	{
	  													cout<<"Line "<<getline()<<":"<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl;
	  													cout<<endl;
														$$=new vector<SymbolInfo*>();
														$$->push_back(new SymbolInfo("for","FOR"));
														$$->push_back(new SymbolInfo("(","LPAREN"));
														vector<SymbolInfo*>::iterator i;
														for (i = $3->begin(); i != $3->end(); ++i) 
														if((*i)->get_name()!="\n")
															$$->push_back((*i));
      														
														for (i = $4->begin(); i != $4->end(); ++i) 
														if((*i)->get_name()!="\n")
															$$->push_back((*i));
      														string t;
									for (i = $5->begin(); i != $5->end(); ++i) 
									{
										t=(*i)->get_dType();
										if((*i)->get_name()!="\n")
										$$->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
      														$$->push_back(new SymbolInfo(")","RPAREN"));
      														
														for (i = $7->begin(); i != $7->end(); ++i) 
														$$->push_back((*i));
														for (i = $$->begin(); i != $$->end(); ++i) 
														
														cout<<(*i)->get_name();
      														cout<<endl;
      														cout<<endl;
      														$3->clear();
      														$4->clear();
      														$5->clear();	
	  												}
	  | IF LPAREN expression RPAREN statement %prec nothing		{
 		  							cout<<"Line "<<getline()<<":"<<" statement : IF LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo(" ","newline"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
										t=(*i)->get_dType();
										$$->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$3->clear();
      									$5->clear();
 		  						}
	  | IF LPAREN expression RPAREN statement ELSE statement	{
 		  							cout<<"Line "<<getline()<<":"<<" statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("if","IF"));
									$$->push_back(new SymbolInfo(" ","newline"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
										t=(*i)->get_dType();
										$$->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo("else","ELSE"));
      									$$->push_back(new SymbolInfo("\n","newline"));
      									
									for (i = $7->begin(); i != $7->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$3->clear();
      									$5->clear();
      									$7->clear();
 		  							}
	  | WHILE LPAREN expression RPAREN statement		{
 		  							cout<<"Line "<<getline()<<":"<<" statement : WHILE LPAREN expression RPAREN statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									string t;
									$$->push_back(new SymbolInfo("while","WHILE"));
									$$->push_back(new SymbolInfo(" ","space"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									vector<SymbolInfo*>::iterator i;
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
										t=(*i)->get_dType();
										$$->push_back((*i));
									}
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									
									for (i = $5->begin(); i != $5->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$3->clear();
      									$5->clear();
 		  						}
	  | PRINTLN LPAREN id RPAREN SEMICOLON		{
 		  							cout<<"Line "<<getline()<<":"<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									SymbolInfo* v=st->lookup_symbol($3->get_name());
      									if(v==NULL)
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable  "<<$3->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<$3->get_name()<<endl<<endl;
									
									IncErr();
      									}
      						
									$$->push_back(new SymbolInfo("printf","PRINTLN"));
									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									$$->push_back($3);
      									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo(")","RPAREN"));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
 		  						}
	  | RETURN expression SEMICOLON			{
 		  							cout<<"Line "<<getline()<<":"<<" statement : RETURN expression SEMICOLON"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("return","RETURN"));
									$$->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $2->begin(); i != $2->end(); ++i)
									{ 
										$$->push_back((*i));
										t=(*i)->get_dType();
									}
									//error<<t<<" "<<typef;
									
									if(t=="void")
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t!=typef)
									{
									cout<<"Error at line "<<getline()<<":  Return type mismatch with function declaration in function "<<namef<<endl<<endl;
									error<<"Error at line "<<getline()<<": Return type mismatch with function declaration in function "<<namef<<endl<<endl;
									IncErr();
									}
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									$2->clear();
 		  						}
	  ;
	  
expression_statement 	: SEMICOLON				{
 		  							cout<<"Line "<<getline()<<":"<<" expression_statement : SEMICOLON"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
			| expression SEMICOLON 		{
 		  							cout<<"Line "<<getline()<<":"<<" expression_statement : expression SEMICOLON"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(";","SEMICOLON"));
      									$$->push_back(new SymbolInfo("\n","newline"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
			;
	  
variable : id 							{
 		  							cout<<"Line "<<getline()<<":"<<" variable : ID"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									SymbolInfo* v=st->lookup_symbol($1->get_name());
      									if(v!=NULL)
      									{
      									$1->set_dType(v->get_dType());
      									//cout<<v->get_dType()<<" ";
      									$1->set_varSize(v->get_varSize());
      									if(v->get_varSize()>-1)
      									{
      									$1->set_dType(v->get_dType()+"arr");
      									}
      									}
      									else
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable "<<$1->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<$1->get_name()<<endl<<endl;
									
									IncErr();
									$1->set_dType("int");
      									}
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
	 | id LTHIRD expression RTHIRD 			{
 		  							cout<<"Line "<<getline()<<":"<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									SymbolInfo* v=st->lookup_symbol($1->get_name());
      									
      									if(v!=NULL)
      									{
      									$1->set_dType(v->get_dType());
      									$1->set_varSize(v->get_varSize());
      									if($1->get_varSize()==-1)
      									{
      									cout<<"Error at line "<<getline()<<": "<<$1->get_name()<<" not an array"<<endl<<endl;
									error<<"Error at line "<<getline()<<": "<<$1->get_name()<<" not an array"<<endl<<endl;
									
									IncErr();
      									}
      									}
      									else
      									{
      									cout<<"Error at line "<<getline()<<": Undeclared variable  "<<$1->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared variable "<<$1->get_name()<<endl<<endl;
									
									IncErr();
									$1->set_dType("int");
      									}
      									
      									$$->push_back($1);
      									$$->push_back(new SymbolInfo("[","LTHIRD"));
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									 t=(*i)->get_dType();
									 }
									if(t!="int")
									{
									cout<<"Error at line "<<getline()<<": Expression inside third brackets not an integer"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Expression inside third brackets not an integer"<<endl<<endl;
									
									IncErr();
									}
      									$$->push_back(new SymbolInfo("]","RTHIRD"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									$3->clear();
 		  						}
	 ;
	 
 expression : logic_expression				{
 		  							cout<<"Line "<<getline()<<":"<<" expression : logic expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
	   | variable ASSIGNOP logic_expression 		{
 		  							cout<<"Line "<<getline()<<":"<<" expression : variable ASSIGNOP logic_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									SymbolInfo* v;
      									SymbolInfo* e;
									string t,t1;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									}
									i=$1->begin();
									t=(*i)->get_dType();
									v=(*i);
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									  t1=(*i)->get_dType();
									}
									i=$3->begin();
									e=(*i);
									if(t1=="void")
									{
									 	cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									
										IncErr();
									}
									else if(t!=t1&&t=="int")
									{
									cout<<"Error at line "<<getline()<<": Type Mismatch"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Type Mismatch"<<endl<<endl;
									
									IncErr();
									}
									else if(t!=t1&&(t1=="intarr"||t1=="floatarr"))
									{
										cout<<"Error at line "<<getline()<<": Type mismatch, "<<e->get_name()<<" is an array"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Type mismatch, "<<e->get_name()<<" is an array"<<endl<<endl;
									
										IncErr();
									}
									else if(t!=t1&&(t=="intarr"||t=="floatarr"))
									{
										cout<<"Error at line "<<getline()<<": Type mismatch, "<<v->get_name()<<" is an array"<<endl<<endl;
										error<<"Error at line "<<getline()<<": Type mismatch, "<<v->get_name()<<" is an array"<<endl<<endl;
									
										IncErr();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
	   ;
			
logic_expression : rel_expression 				{
 		  							cout<<"Line "<<getline()<<":"<<" logic_expression : rel_expression "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
		 | rel_expression LOGICOP rel_expression 	{
 		  							cout<<"Line "<<getline()<<":"<<" logic_expression : rel_expression LOGICOP rel_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t1=="void")||(t=="void"))
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr"||t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									//tf=t1;
									
									IncErr();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
		 ;
			
rel_expression	: simple_expression 				{
 		  							cout<<"Line "<<getline()<<":"<<" rel_expression : simple_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
		| simple_expression RELOP simple_expression	{
 		  							cout<<"Line "<<getline()<<":"<<" rel_expression : simple_expression RELOP simple_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t1=="void")||(t=="void"))
									{
									cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr"||t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									//tf=t1;
									
									IncErr();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
		;
				
simple_expression : term 					{
 		  							cout<<"Line "<<getline()<<":"<<" simple_expression : term "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
		  | simple_expression ADDOP term 		{
 		  							cout<<"Line "<<getline()<<":"<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1,tf;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									  t1=(*i)->get_dType();
									}
									if((t=="void")||(t1=="void"))
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									tf="int";
									}
									
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t1;
									
									IncErr();
									}
									else if(t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t;
									
									IncErr();
									}
									else if(t1==t)
									tf=t;
									else 
									tf="float";
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(tf);
									}
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
		  ;
					
term :	unary_expression					{
 		  							cout<<"Line "<<getline()<<":"<<" term : unary_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
     |  term MULOP unary_expression				{
 		  							cout<<"Line "<<getline()<<":"<<" term : term MULOP unary_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t,t1,tf;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
      									$$->push_back($2);
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									 $$->push_back((*i));
									  t1=(*i)->get_dType();
									}
									
									if((t=="void")||(t1=="void"))
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									IncErr();
									tf="int";
									}
									
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t1;
									
									IncErr();
									}
									else if(t1=="intarr"||t1=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									tf=t;
									
									IncErr();
									}
									else if(t1==t)
									tf=t;
									else 
									tf="float";
									if(($2->get_name()=="%")&&(tf=="float"))
									{
									cout<<"Error at line "<<getline()<<": Non-Integer operand on modulus operator"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Non-Integer operand on modulus operator"<<endl<<endl;
									tf="int";
									IncErr();
									}
									if(($3->size()==1))
									{
									 i=$3->begin();
									 if((*i)->get_name()=="0")
									 {
									 cout<<"Error at line "<<getline()<<": Modulus by Zero"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Modulus by Zero"<<endl<<endl;
									tf="int";
									IncErr();
									 }
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(tf);
									}
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
     ;

unary_expression : ADDOP unary_expression  			{
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : ADDOP unary_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $2->begin(); i != $2->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									if(t=="void")
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									t="int";
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									t="int";
									
									IncErr();
									}
									
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$2->clear();
 		  						}
		 | NOT unary_expression 			{
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : NOT unary expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("!","NOT"));
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $2->begin(); i != $2->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									if(t=="void")
									{
									 cout<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Void function used in expression"<<endl<<endl;
									t="int";
									IncErr();
									}
									else if(t=="intarr"||t=="floatarr")
									{
									
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									$2->clear();
 		  						}
		 | factor 					{
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : factor"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									  t=(*i)->get_dType();
									}
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
		 ;
	
factor	: variable 						{
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									 $$->push_back((*i));
									 
									}
									i=$1->begin();
									t=(*i)->get_dType();
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
	| id LPAREN argument_list RPAREN			{
 		  							cout<<"Line "<<getline()<<":"<<" factor : ID LPAREN argument_list RPAREN"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back($1);
									SymbolInfo* f=st->lookup_symbol($1->get_name());
									string t;
									t="int";
									if(f==NULL)
									{
									cout<<"Error at line "<<getline()<<":  Undeclared function "<<$1->get_name()<<endl<<endl;
									error<<"Error at line "<<getline()<<": Undeclared function "<<$1->get_name()<<endl<<endl;
									IncErr();
									
									}
									else{
									if(f->isFunc())
									{
										t=f->get_dType();
										if(f->get_listSize()!=arglist.size())
										{
										//error<<f->get_name()<<" ";
										//error<<f->get_listSize()<<" "<<arglist.size()<<endl;
										cout<<"Error at line "<<getline()<<": Total number of arguments mismatch in function "<<$1->get_name()<<endl<<endl;
										error<<"Error at line "<<getline()<<": Total number of arguments mismatch in function "<<$1->get_name()<<endl<<endl;
										IncErr();
										}
									
										else
										{
										for(int j=0;j<arglist.size();j++)
										if((f->getParam(j))->get_ptype()!=arglist[j])
										{
										cout<<"Error at line "<<getline()<<":  Argument mismatch in function "<<$1->get_name()<<endl<<endl;
										error<<"Error at line "<<getline()<<":  Argument mismatch in function "<<$1->get_name()<<endl<<endl;
										
										IncErr();
										break;
										}
										
										}
										
										
										
									}
									else
									{
									cout<<"Error at line "<<getline()<<":  function  with non-function type identifier"<<endl<<endl;
									error<<"Error at line "<<getline()<<": function  with non-function type identifier"<<endl<<endl;
									IncErr();
									}
									}
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
      									
									for (i = $3->begin(); i != $3->end(); ++i) 
										$$->push_back((*i));
      									
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
									for(int j=0;j<arglist.size();j++)
										arglist[j].clear();
										arglist.clear();
      									cout<<endl<<endl;
      									$3->clear();
 		  						}
	| LPAREN expression RPAREN				{
 		  							cout<<"Line "<<getline()<<":"<<" factor : LPAREN expression RPAREN"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i;
									string t;
									for (i = $2->begin(); i != $2->end(); ++i) 
									{
									 $$->push_back((*i));
									 t=(*i)->get_dType();
									}
      									$$->push_back(new SymbolInfo(")","RPAREN"));
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType(t);
									}
      									cout<<endl<<endl;
      									$2->clear();
 		  						}
	| CONST_INT 						{
 		  							cout<<"Line "<<getline()<<":"<<" factor : CONST_INT"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									$1->set_dType("int");
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
	| CONST_FLOAT						{
 		  							cout<<"Line "<<getline()<<":"<<" factor : CONST_FLOAT "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
									$1->set_dType("float");
      									$$->push_back($1);
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
 		  						}
	| variable INCOP 					{
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable INCOP"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									$$->push_back((*i));
									}
									i=$1->begin();
									if(((*i)->get_type()=="ID")&&((*i)->get_dType()=="float")){
									cout<<"Error at line "<<getline()<<": Can't increment float number"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Can't increment float number"<<endl<<endl;
									IncErr();
									}
									else if(((*i)->get_type()=="ID")&&((*i)->get_dType()!="int")){
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
										
      									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
										
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
	| variable DECOP					{
 		  							cout<<"Line "<<getline()<<":"<<" factor : variable DECOP"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									$$->push_back((*i));
									}
									i=$1->begin();
									if(((*i)->get_type()=="ID")&&((*i)->get_dType()=="float")){
									cout<<"Error at line "<<getline()<<": Can't decrement float number"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Can't decrement float number"<<endl<<endl;
									IncErr();
									}
									else if(((*i)->get_type()=="ID")&&((*i)->get_dType()!="int")){
									cout<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									error<<"Error at line "<<getline()<<": Array used in expression"<<endl<<endl;
									
									IncErr();
									}
      									$$->push_back($2);
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
									cout<<(*i)->get_name();
									(*i)->set_dType("int");
									}
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
	;
	
argument_list : arguments					{
 		  							cout<<"Line "<<getline()<<":"<<" argument_list : arguments"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									$1->clear();
 		  						}
		|						{
 		  							cout<<"Line "<<getline()<<":"<<" argument_list : "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo("","EMPTY"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									
 		  						}
			  ;
	
arguments : arguments COMMA logic_expression			{
 		  							cout<<"Line "<<getline()<<":"<<" arguments : arguments COMMA logic_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
      									
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									$$->push_back(new SymbolInfo(",","COMMA"));
									for (i = $3->begin(); i != $3->end(); ++i) 
									{
									$$->push_back((*i));
									t=(*i)->get_dType();
									
									}
									
									arglist.push_back(t);
									
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									$1->clear();
      									$3->clear();
 		  						}
	      | logic_expression				{
 		  							cout<<"Line "<<getline()<<":"<<" arguments : logic_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i;
      									string t;
      									
									for (i = $1->begin(); i != $1->end(); ++i) 
									{
									$$->push_back((*i));
									t=(*i)->get_dType();
									}
									arglist.push_back(t);	
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									$1->clear();
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
	error.open("error.txt",ios::out);
	freopen("log.txt","w",stdout);
	yyin=fp;
	yyparse();
	st->print_all();
	cout<<endl;
	cout<<"Total lines: "<<getline()<<endl;
	cout<<"Total errors: "<<getErr()<<endl;

	
	return 0;
}

