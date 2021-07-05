%{
#include<bits/stdc++.h>
#include "Symbol_table.h"

using namespace std;
ofstream error;
ofstream code,ocode;
string data_seg;
int temp_count=0;
string code_seg,dummy,func_init,func_name;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
FILE* fp;
SymbolTable *st = new SymbolTable(30);

int line_count=1;
int err=0;
int label_count=0;
void IncLine(){
	line_count++;}
int getline()
	{return line_count;}
void IncErr(){
	err++;}
int getErr()
	{return err;}
string newLabel()
{
	string l="L"+to_string(label_count);
	label_count++;
	return l;
}
string newTemp()
{
	string l="T"+to_string(temp_count);
	temp_count++;
	return l;
}
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for
 pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return i;
    }
 
    return -1;
}
string optimize(string d_seg,string c_seg)
{
    string temp,cde;
    stringstream ss(c_seg),ss1(d_seg);
    vector<string> tokens,datas;

    while(getline(ss1, temp, '\n')) {
        datas.push_back(temp);
    }
    while(getline(ss, temp, '\n')) {
        tokens.push_back(temp);
    }
   for (int i = 0; i < tokens.size(); i++)
   {
   	if(i == tokens.size()-1) {
   	
            continue;
        }
        if((tokens[i].length() < 4) ) {
        	//ocode<<tokens[i]<<endl;
            continue;
        }
        //ocode<<tokens[i].substr(0,3)<<endl;
        if((tokens[i].substr(0,3) == "mov"))
   	{
   	//ocode<<"dhuke"<<endl;
   	string temp1;
   	//ocode<<tokens[i].substr(4,4)<<endl;
   	//<<tokens[i].substr(tokens[i].size()-2,tokens[i].size())<<endl;
   	if((tokens[i].substr(4,5) == "T")&&(tokens[i].substr(tokens[i].size()-2,tokens[i].size()) == "ax"))
   	{
   	
   	temp1=tokens[i].substr(4,tokens[i].size()-5);
   	
   	}
   	else if((tokens[i].substr(4,5) == "T")&&((tokens[i].substr(tokens[i].size()-1,tokens[i].size()) == "1")||(tokens[i].substr(tokens[i].size()-1,tokens[i].size()-1) == "0"))){
   	temp1=tokens[i].substr(4,tokens[i].size()-4);
   	}
   	int count=0;
   	
   	for(int j=i+1;j<tokens.size(); j++)
   	{
   	 if(isSubstring(tokens[j],temp1)!=-1)
   	 	count++;
   	}
   	if(count==0)
   	{
   	tokens[i]="";
   	for(int k=0;k<datas.size();k++)
   	{
   	if(isSubstring(datas[k],temp1)!=-1)
   	datas[k]="";
   	}
   	
   	}
   	
   	}
   	
        if((tokens[i].length() < 4) || (tokens[i+1].length() < 4)) {
        	//ocode<<tokens[i]<<endl;
            continue;
        }
        
   	if((tokens[i].substr(0,6) == "mov ax") && (tokens[i+1].substr(0,6) == "mov ax")) {
   	tokens[i]="";
   	}
   	if((tokens[i].substr(0,6) == "mov ax") && (tokens[i+1].substr(0,3) ==
   	"mov")&&(tokens[i+1].substr(tokens[i+1].size()-2,tokens[i+1].size()) == "ax")) {
   	if((tokens[i].substr(8,tokens[i].size()) == tokens[i+1].substr(3,tokens[i+1].size()-4))) 
   	tokens[i+1]="";
   	}
   	
   	
   }
   cde=".model small\n.stack 100h\n.data\n";//<<endl<<data_seg<<endl<<".code"<<endl<<s<<endl<<"end main";
    for (int i = 0; i < datas.size(); i++)
   {
    cde+=datas[i]+"\n";
   }
   cde+=".code\n";
    for (int i = 0; i < tokens.size(); i++)
   {
    cde+=tokens[i]+"\n";
   }
   cde+="end main";
  return cde;
  
}
void yyerror(char *s)
{
	//write your code
	cout<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	error<<"Error at line "<<getline()<<": Syntax Error"<<endl;
	IncErr();
}

bool func=false,declared=false;
int arg_count=0;
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
		i = $$->begin();
		//data_seg+="\ntemp dw ?";
		code_seg=(*i)->get_code()+"\noutput proc\nxor cx,cx \n ;count=0 and dx=0\nxor dx,dx\ncmp ax,0\nje printt \nbegin1:\ncmp ax,0\n; if ax is zero\nje repeat1\nmov bx,10 ; extract the last digit and push it to stack\ndiv bx\npush dx\ninc cx  \n;count++             \nxor dx,dx   \n; dx=0\njmp begin1\nrepeat1: \ncmp cx,0 \n;check if count>0 \nje return\npop dx   \n;pop the top of stack\nadd dx,48 \n;print the digit \nmov ah,2 \nint 21h  \ndec cx       \n;count--\njmp repeat1 \nreturn:\nret \nprintt:\nmov dx,48\nmov ah,2\nint 21h\njmp return\noutput endp";
		//code<<full_code;
	}
	;

program : program unit 	{
					vector<SymbolInfo*>::iterator i,i1;
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
					i = $$->begin();
					i1 = $2->begin();
					(*i)->set_code((*i)->get_code()+(*i1)->get_code());
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
					i = $$->begin();
					(*i)->set_code((*i)->get_code());
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
					i = $$->begin();
					(*i)->set_code("");
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
					i = $$->begin();
					(*i)->set_code("");
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
					i = $$->begin();
					(*i)->set_code((*i)->get_code());
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
      											int k=0;
											for (j = plist.begin(); j != plist.end(); ++j)
											{
											data_seg+="p"+to_string(k)+"_"+ $2->get_name()+" dw ?\n";
											delete (*j);
											k++;
											}
											plist.clear();
											if($1->get_name()!="void")
											data_seg+="ret"+ $2->get_name()+" dw ?\n";
											for (i= vlist.begin(); i != vlist.end(); ++i)
											{
											delete (*i);
											}
											vlist.clear();
											i = $$->begin();
											declared=true;
											//(*i)->set_code((*i)->get_code());
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
											//int j=0;
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
											if($1->get_name()!="void")
											data_seg+="ret_"+ $2->get_name()+" dw ?\n";
      											cout<<endl;
											cout<<endl;
											i = $$->begin();
											(*i)->set_code((*i)->get_code());
											declared=true;
		
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
		if(typef!="void")
		data_seg+="ret_"+ namef+" dw ?\n";
		SymbolInfo* si=new SymbolInfo(namef,"ID",typef);
		si->set_func();
		int h=0;
		for (j = plist.begin(); j != plist.end(); ++j)
		{
		si->addParam((*j)->get_ptype(),(*j)->get_pname());
		data_seg+="p"+to_string(h)+"_"+ namef+" dw ?\n";
		delete (*j);
		h++;
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
											vector<SymbolInfo*>::iterator i,i1;
											for (i = $5->begin(); i != $5->end(); ++i) 
												$$->push_back((*i));
											
											$$->push_back(new SymbolInfo(")","RPAREN"));
											for (i = $8->begin(); i != $8->end(); ++i) 
												$$->push_back((*i));
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											i1 = $$->begin();
      											i = $8->begin();
      											if($2->get_name()!="main")
											(*i1)->set_code("\n"+$2->get_name()+" proc\npush ax\npush bx\npush cx\npush dx"+func_init+(*i)->get_code()+"\npop dx\npop cx\npop bx\npop ax\nret"+"\n"+$2->get_name()+" endp");
											else
											(*i1)->set_code("\nmain proc\nmov  ax , @data\nmov  ds , ax"+(*i)->get_code()+"\nmain endp");
											func_init="";
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
											vector<SymbolInfo*>::iterator i,i1;
											for (i = $7->begin(); i != $7->end(); ++i) 
												$$->push_back((*i));
											$7->clear();
											for (i = $$->begin(); i != $$->end(); ++i) 
												cout<<(*i)->get_name();
      											cout<<endl;
      											cout<<endl;
      											i1 = $$->begin();
      											i = $7->begin();
											if($2->get_name()!="main")
											(*i1)->set_code("\n"+$2->get_name()+" proc\npush ax\npush bx\npush cx\npush dx"+(*i)->get_code()+"\npop dx\npop cx\npop bx\npop ax\nret"+"\n"+$2->get_name()+" endp");
											else
											(*i1)->set_code("\nmain proc\nmov  ax , @data\nmov  ds , ax"+(*i)->get_code()+"\nmov ah , 4ch\nint 21h\nmain endp");
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
									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
									(*i)->set_code((*i1)->get_code());
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
			  int k=0;
			  for ( j=vlist.begin(); j !=vlist.end(); ++j) 
			  {
			  	
			  	SymbolInfo* si=new SymbolInfo((*j)->get_name(),(*j)->get_type(),(*j)->get_dType());
			  	
			  	if(st->insert_symbol(si))
			  	{
			  		data_seg+=si->get_name()+st->get_Currid()+" dw ?\n";
			  		func_init+="\nmov cx , p"+to_string(k)+"_"+namef+"\nmov "+si->get_name()+st->get_Currid()+" , cx";
			  		
			  	}
			  	else
			  	{
			  	cout<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				error<<"Error at line "<<getline()<<": Multiple declaration of "<<(*j)->get_name()<<" in parameter"<<endl<<endl;
				IncErr();
			  	}
			  	k++;
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
											{
											   si->set_varSize((*i)->get_varSize());
											   data_seg+=(*i)->get_name()+st->get_Currid()+" dw "+to_string((*i)->get_varSize())+" dup (?)\n";
											 }
											 else
											   data_seg+=(*i)->get_name()+st->get_Currid()+" dw ?\n";
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
      									i = $$->begin();
									(*i)->set_code((*i)->get_code());
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
      										i = $$->begin();
										(*i)->set_code((*i)->get_code());
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
      									i = $$->begin();
									(*i)->set_code((*i)->get_code());
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
      									i = $$->begin();
									(*i)->set_code((*i)->get_code());
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
      									i = $$->begin();
									(*i)->set_code((*i)->get_code());
      									$1->clear();
 		  						}		
	   | statements statement				{
 		  							cout<<"Line "<<getline()<<":"<<" statements : statements statement"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i,i1;
									for (i = $1->begin(); i != $1->end(); ++i) 
										$$->push_back((*i));
      									
									for (i = $2->begin(); i != $2->end(); ++i) 
										$$->push_back((*i));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl;
      									cout<<endl;
      									i = $$->begin();
      									i1 = $2->begin();
									(*i)->set_code((*i)->get_code()+(*i1)->get_code());
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
									i = $$->begin();
									(*i)->set_code("");
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
									i = $$->begin();
									(*i)->set_code((*i)->get_code());
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
									i = $$->begin();
									(*i)->set_code((*i)->get_code());
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
														vector<SymbolInfo*>::iterator i,i1,i2,i3,i4;
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
      														string l=newLabel();
      														string l2=newLabel();
      														i = $$->begin();
      														i1 = $3->begin();
      														i2 = $4->begin();
      														i3 = $7->begin();
      														i4 = $5->begin();
      														string temp=(*i2)->get_temp();
														(*i)->set_code((*i1)->get_code()+"\n"+l+":\n"+(*i2)->get_code()+"\ncmp "+temp+",1\njne "+l2+(*i3)->get_code()+(*i4)->get_code()+"\njmp "+l+"\n"+l2+":");
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
									vector<SymbolInfo*>::iterator i,i1,i2;
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
      									string l=newLabel();
      									i = $$->begin();
      									i1 = $3->begin();
      									i2 = $5->begin();
      									string temp=(*i1)->get_temp();
									(*i)->set_code((*i1)->get_code()+"\ncmp "+temp+",1\njne "+l+(*i2)->get_code()+"\n"+l+":");
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
									vector<SymbolInfo*>::iterator i,i1,i3,i2;
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
      									string l=newLabel();
      									//string l2=newLable();
      									i = $$->begin();
      									i1 = $3->begin();
      									i2= $5->begin();
      									i3 = $7->begin();
      									string temp=(*i1)->get_temp();
									(*i)->set_code((*i1)->get_code()+"\ncmp "+temp+",1\njne "+l+(*i2)->get_code()+"\n"+l+":"+(*i3)->get_code());
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
									vector<SymbolInfo*>::iterator i,i2,i1;
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
      									
      									string l=newLabel();
      									string l1=newLabel();
      									i = $$->begin();
      									i1 = $3->begin();
      									i2 = $5->begin();
      									string temp=(*i1)->get_temp();
									(*i)->set_code("\n"+l+":"+(*i1)->get_code()+"\ncmp "+temp+",1\njne "+l1+"\n"+(*i2)->get_code()+"\njmp "+l+"\n"+l1+":");
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
      									string n=$3->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=$3->get_name()+sc->get_cid();
      									}
      									i = $$->begin();
									(*i)->set_code("\nmov ax , "+n+"\ncall output");
 		  						}
	  | RETURN expression SEMICOLON			{
 		  							cout<<"Line "<<getline()<<":"<<" statement : RETURN expression SEMICOLON"<<endl;
 		  							cout<<endl;
									$$=new vector<SymbolInfo*>();
									$$->push_back(new SymbolInfo("return","RETURN"));
									$$->push_back(new SymbolInfo(" ","space"));
									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $2->begin();
      									string temp=(*i1)->get_temp();
									(*i)->set_code((*i1)->get_code()+"\nmov bx , "+temp+"\nmov ret_"+namef+" , bx");
									(*i)->set_temp(temp);
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
									i = $$->begin();
									string temp=newTemp();
									data_seg+=temp+" dw ?\n";
									(*i)->set_code("\mov "+temp+" , 1");
									(*i)->set_temp(temp);
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
      									string cmd="\n\n;";
									for (i = $$->begin(); i != $$->end(); ++i) 
									{
										cout<<(*i)->get_name();
										cmd+=(*i)->get_name();
									}
									cmd+="\n";
									i = $$->begin();
									(*i)->set_code(cmd+(*i)->get_code());
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
      									string temp=newTemp();
      									data_seg+=temp+" dw ?\n";
      									i = $$->begin();
      									string n=$1->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=$1->get_name()+sc->get_cid();
      									}
      									
      									
      									(*i)->set_code((*i)->get_code()+"\nmov ax , "+n+"\nmov "+temp+" , ax");
      									(*i)->set_temp(temp);
      									//temp="ah";
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
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
      									
      									string temp=newTemp();
      									data_seg+=temp+" dw ?\n";
      									string n=$1->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=$1->get_name()+sc->get_cid();
      									}
      									dummy=(*i1)->get_temp();
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov bx , "+(*i1)->get_temp()+"\nsal bx , 2\ninc bx\nmov ax , "+n+"[bx]\nmov "+temp+" , ax");
      									(*i)->set_temp(temp);
  									//temp="ah";
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									//temp="bh";
      									$1->clear();
 		  						}
	   | variable ASSIGNOP logic_expression 		{
 		  							cout<<"Line "<<getline()<<":"<<" expression : variable ASSIGNOP logic_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $1->begin();
      									string n=(*i)->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=(*i)->get_name()+sc->get_cid();
      									}
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i)->get_temp();
      									string temp1=(*i1)->get_temp();
      									if($1->size()!=1)
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov bx , "+dummy+"\nsal bx , 2\ninc bx\nmov ax , "+temp1+"\nmov "+n+"[bx] , ax\nmov "+temp+" , 1");
      									else
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp1+"\nmov "+n+" , ax\nmov "+temp+" , 1");
      									//temp="bh";
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									//temp="dl";
      									$1->clear();
 		  						}
		 | rel_expression LOGICOP  rel_expression 	{
 		  							cout<<"Line "<<getline()<<":"<<" logic_expression : rel_expression LOGICOP rel_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i)->get_temp();
      									string temp1=(*i1)->get_temp();
      									string label=newLabel();
      									string label1=newLabel();
      									if($2->get_name()=="&&")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\nor ax , "+temp1+"\ncmp ax , 0"+"\nje "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()=="||")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\nor ax , "+temp1+"\ncmp ax , 0"+"\nje "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									
      								
      									//temp="dl";
      									
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									//temp="bh";
      									//dummy1="";
      									$1->clear();
 		  						}
		| simple_expression  RELOP simple_expression	{
 		  							cout<<"Line "<<getline()<<":"<<" rel_expression : simple_expression RELOP simple_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i)->get_temp();
      									string temp1=(*i1)->get_temp();
      									string label=newLabel();
      									string label1=newLabel();
      									if($2->get_name()=="<")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\njnl "+label+"\nmov "+temp+",1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()==">")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\njng "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()==">=")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\njl "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()=="<=")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\njg "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()=="==")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\njne "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									else if($2->get_name()=="!=")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\ncmp ax , "+temp1+"\nje "+label+"\nmov "+temp+" , 1\njmp "+label1+"\n"+label+":\nmov "+temp+" , 0\n"+label1+":");
      									//temp="bh";
      									
      									
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									//temp="bl";
      									$1->clear();
 		  						}
		  | simple_expression ADDOP term 		{
 		  							cout<<"Line "<<getline()<<":"<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i)->get_temp();
      									string temp1=(*i1)->get_temp();
      									if($2->get_name()=="+")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp1+"\nadd "+temp+" , ax");
      									else if($2->get_name()=="-")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp1+"\nsub "+temp+" , ax");
      								
      									//temp="bl";
      									
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									//temp="cl";
      									$1->clear();
 		  						}
     |  term MULOP unary_expression				{
 		  							cout<<"Line "<<getline()<<":"<<" term : term MULOP unary_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									//string tmp=newTemp();
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i)->get_temp();
      									string temp1=(*i1)->get_temp();
      									if($2->get_name()=="*")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax ,  "+temp+"\nimul "+temp1+"\nmov "+temp+" , ax");
      									else if($2->get_name()=="/")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax ,  "+temp+"\ncwd\nidiv "+temp1+"\nmov "+temp+" , ax");
      									else if($2->get_name()=="%")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax ,  "+temp+"\ncwd\nidiv "+temp1+"\nmov "+temp+" , dx");
      									
      									//temp="cl";
      									(*i)->set_temp(temp);
      									$1->clear();
      									$3->clear();
 		  						}
     ;

unary_expression : ADDOP unary_expression  			{
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : ADDOP unary_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back($1);
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $2->begin();
      									string temp=(*i1)->get_temp();
      									if($1->get_name()=="-")
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nneg "+temp);
      									else
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code());
      									(*i)->set_temp(temp);
      									//temp="bl";
      									$2->clear();
 		  						}
		 | NOT unary_expression 			{
 		  							cout<<"Line "<<getline()<<":"<<" unary_expression : NOT unary expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("!","NOT"));
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $2->begin();
      									string temp=(*i1)->get_temp();
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nnot "+temp);
      									(*i)->set_temp(temp);
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									(*i)->set_temp((*i)->get_temp());
      									//temp="bl";
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									(*i)->set_temp((*i)->get_temp());
      									//temp="al";
      									$1->clear();
 		  						}
	| id {func_name=name;} LPAREN argument_list RPAREN			{
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
									
      									vector<SymbolInfo*>::iterator i,i1;
      									
									for (i = $4->begin(); i != $4->end(); ++i) 
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
      									i = $$->begin();
      									i1 = $4->begin();
      									string temp=newTemp();
      									data_seg+=temp+" dw ?\n";
      									(*i)->set_code((*i1)->get_code()+"\ncall "+func_name+"\nmov ax , ret_"+func_name+"\nmov "+temp+" , ax");
      									(*i)->set_temp(temp);
      									$4->clear();
 		  						}
	| LPAREN expression RPAREN				{
 		  							cout<<"Line "<<getline()<<":"<<" factor : LPAREN expression RPAREN"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									$$->push_back(new SymbolInfo("(","LPAREN"));
									
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $2->begin();
      									(*i)->set_code((*i1)->get_code());
      									(*i)->set_temp((*i1)->get_temp());
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
      									string temp=newTemp();
      									data_seg+=temp+" dw ?\n";
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code()+"\nmov "+temp+" , "+$1->get_name());
      									(*i)->set_temp(temp);
      									//temp="al";
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
      									i = $$->begin();
      									string temp=newTemp();
      									data_seg+=temp+" dw ?\n";
      									(*i)->set_code((*i)->get_code()+"\nmov "+temp+" , "+$1->get_name());
      									(*i)->set_temp(temp);
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
      									i = $1->begin();
      									string n=(*i)->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=(*i)->get_name()+sc->get_cid();
      									}
      									i = $$->begin();
      									string temp=(*i)->get_temp();
      									(*i)->set_code((*i)->get_code()+"\ninc "+temp+"\ninc "+n);
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
      									i = $1->begin();
      									string n=(*i)->get_name()+st->get_Currid();
      									ScopeTable* sc=st->curr();
      									while(true){
      									
      									if(isSubstring(n,data_seg)!=-1)
      									{
      										break;
      									}
      									sc=sc->get_parent();
      									n=(*i)->get_name()+sc->get_cid();
      									}
      									i = $$->begin();
      									string temp=(*i)->get_temp();
      									(*i)->set_code((*i)->get_code()+"\ndec "+temp+"\ndec "+n);
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
      									i = $$->begin();
      									(*i)->set_code((*i)->get_code());
      									$1->clear();
      									arg_count=0;
 		  						}
		|						{
 		  							cout<<"Line "<<getline()<<":"<<" argument_list : "<<endl<<endl;
									$$=new vector<SymbolInfo*>();
									vector<SymbolInfo*>::iterator i;
      									$$->push_back(new SymbolInfo("","EMPTY"));
									for (i = $$->begin(); i != $$->end(); ++i) 
										cout<<(*i)->get_name();
      									cout<<endl<<endl;
      									(*i)->set_code((*i)->get_code());
      									
      									
 		  						}
			  ;
	
arguments : arguments COMMA logic_expression			{
 		  							cout<<"Line "<<getline()<<":"<<" arguments : arguments COMMA logic_expression"<<endl<<endl;
									$$=new vector<SymbolInfo*>();
      									vector<SymbolInfo*>::iterator i,i1;
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
      									i = $$->begin();
      									i1 = $3->begin();
      									string temp=(*i1)->get_temp();
      									(*i)->set_code((*i)->get_code()+(*i1)->get_code()+"\nmov ax , "+temp+"\nmov p"+to_string(arg_count)+"_"+func_name+" , ax");
      									arg_count++;
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
      									i = $$->begin();
      									string temp=(*i)->get_temp();
      									(*i)->set_code((*i)->get_code()+"\nmov ax , "+temp+"\nmov p"+to_string(arg_count)+"_"+func_name+" , ax");
      									arg_count++;
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
	code.open("code.asm",ios::out);
	ocode.open("optimized_code.asm",ios::out);
	string s=optimize(data_seg,code_seg);
	if(getErr()==0)
	{
		code<<".model small"<<endl<<".stack 100h"<<endl<<".data"<<endl<<data_seg<<endl<<".code"<<endl<<code_seg<<endl<<"end main";
		//ocode<<s;
	}
	return 0;
}

