%option noyywrap yylineno
%x str
%x cmnt_single
%x cmnt_mult

%{
#include<bits/stdc++.h>
#include "Symbol_table.cpp"
SymbolTable *st = new SymbolTable(7);
string t,l;
int line;
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

ofstream token;
%}


keywords (if|for|else|switch|default|while|break|char|double|return|case|continue|do|int|float|void)
digit	[0-9]
AlphaNumeric [a-zA-Z0-9_]
special (\\t|\\n|(\\\\)|(\\')|\\a|\\f|\\r|\\b|\\v|\\0|\\\")
chars [a-zA-Z0-9_!@#$\%\^&\*\(\)\-\+=\{\}\[\]\|\?/\<\>,\.;:]
WHITESPACE [ \t\f\r\v]+ 
newline (\n|\r\n)
%%
{WHITESPACE} 				{}
{newline}  				{IncLine();}
{keywords} 				{
						 string s=yytext;
	   					 transform(s.begin(), s.end(), s.begin(), ::toupper);
	   					 //fprintf(tokenout,"<%s>",s);
	   					 token<<"<"<<s<<"> ";
	    					 cout<<"Line no "<<getline()<<": Token <"<<s<<"> Lexeme "<<yytext<<" found"<<endl<<endl;
	  				}
(\+\+|\-\-)				{
						token<<"<INCOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <INCOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
[+-]					{
						token<<"<ADDOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <ADDOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
[\*/%]					{
						token<<"<MULOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <MULOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
[=]	   				{
						token<<"<ASSIGNOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <ASSIGNOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
(<|>|<=|>=|==|!=)			{
						token<<"<RELOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <RELOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
(&&|\|\|)				{
						token<<"<LOGICOP, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <LOGICOP> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
!					{
						token<<"<NOT, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <NOT> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\(					{
						token<<"<LPAREN, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <LPAREN> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\)					{
						token<<"<RPAREN, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <RPAREN> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\[					{
						token<<"<LTHIRD, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <LTHIRD> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\]					{
						token<<"<RTHIRD, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <RTHIRD> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
, 					{
						token<<"<COMMA, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <COMMA> Lexeme "<<yytext<<" found"<<endl<<endl;
					}		
; 					{
						token<<"<SEMICOLON, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <SEMICOLON> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\{ 					{
						st->enterScope();
						token<<"<LCURL, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <LCURL> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
\}					{
						st->exitScope();
						token<<"<RCURL, "<<yytext<<"> ";
						cout<<"Line no "<<getline()<<": Token <RCURL> Lexeme "<<yytext<<" found"<<endl<<endl;
					}
[a-zA-Z_]{AlphaNumeric}* 		{
					string s=yytext;
					string typ="ID";
					token<<"<"<<typ<<", "<<s<<"> ";
					cout<<"Line no "<<getline()<<": Token <ID> Lexeme "<<yytext<<" found"<<endl<<endl;
					if(st->insert_symbol(typ,s)){
					st->print_all();
					//cout<<endl;
					}
					}
{digit}+[a-zA-Z_]+			{
						cout<<"Error at line no "<<getline()<<": Invalid prefix on ID or invalid suffix on Number "<<yytext<<endl<<endl;
						IncErr();
					}					
{digit}+ 				{
					string s=yytext;
					string typ="CONST_INT";
					token<<"<"<<typ<<", "<<s<<"> ";
					cout<<"Line no "<<getline()<<": Token <CONST_INT> Lexeme "<<yytext<<" found"<<endl<<endl;
					if(st->insert_symbol(typ,s)){
					st->print_all();
					//cout<<endl;
					}
					}
({digit}*)?(\.{digit}+)?(E[+-]?{digit}+)?	 {
							string s=yytext;
							string typ="CONST_FLOAT";
							token<<"<"<<typ<<", "<<s<<"> ";
							cout<<"Line no "<<getline()<<": Token <CONST_FLOAT> Lexeme "<<yytext<<" found"<<endl<<endl;
							if(st->insert_symbol(typ,s))
							{
								st->print_all();
								//cout<<endl;
						}
						}
{digit}+\.    					{
						cout<<"Error at line no "<<getline()<<": Ill formed number "<<yytext<<endl<<endl;
						IncErr();
						}
({digit}*\.{digit}*)+ 				{
						cout<<"Error at line no "<<getline()<<": Too many decimal points "<<yytext<<endl<<endl;
						IncErr();
						}
(({digit}*)?(\.{digit}*)?(E[+-]?{digit}+)?)+ 	{
						cout<<"Error at line no "<<getline()<<": Ill formed number "<<yytext<<endl<<endl;
						IncErr();
						}
'({chars}|{special})' 			{
						string s1, s=yytext;
						string typ="CONST_CHAR";
						cout<<"Line no "<<getline()<<": Token <CONST_CHAR> Lexeme "<<yytext<<" found";
						
						if(s.length()==3)
						{
						s1=s.substr(1,1);
						
						}
					
				      		else
				        	{
					 	 s1=s.substr(1,2);
					  	if(s1=="\\n")
					  		s1="\n";
					  	else if(s1=="\\t")
					  		s1="\t";
					 	else if(s1=="\\\\")
					  		s1="\\";
					  	else if(s1=="\\'")
					  		s1="\'";
					  	else if(s1=="\\\"")
					  		s1="\"";
					   	else if(s1=="\\a")
					  		s1="\a";
					   	else if(s1=="\\f")
					  		s1="\f";
					   	else if(s1=="\\r")
					   		s1="\r";
					   	else if(s1=="\\b")
					  		s1="\b";
					   	else if(s1=="\\v")
					  		s1="\v";
					   	else if(s1=="\\0")
					  		s1="\0";
					  
					 	}
						token<<"<"<<typ<<", ";
						if(s1=="\r")
							token<<endl;
						token<<s1<<"> ";
						cout<<" --> <CONST_CHAR, "<<s1<<">"<<endl<<endl;
						if(st->insert_symbol(typ,s))
						{
						st->print_all();
						//cout<<endl;
					}}
'({chars}|{special}|\\|{WHITESPACE})+' 			{
							cout<<"Error at line no "<<getline()<<": Multi character constant error "<<yytext<<endl<<endl;
							IncErr();
						}
'({chars}|\\|{special})*	{
							cout<<"Error at line no "<<getline()<<": Unterminated character "<<yytext<<endl<<endl;
							IncErr();
						}
'' 						{
							cout<<"Error at line no "<<getline()<<": Empty character constant error "<<yytext<<endl<<endl;
							IncErr();
						}						
\"						{
							BEGIN str;
							line=0;
							t=yytext;
							l=yytext;
						}
<str>({chars}|\\|{WHITESPACE})		{
						 t=t+yytext;
						 l=l+yytext;
						 
						}
<str>({special})				{
						 string s1=yytext;
						 l=l+s1;
					  	if(s1=="\\n")
					  	s1="\n";
					  	else if(s1=="\\t")
					  	s1="\t";
					  	else if(s1=="\\\\")
					  	s1="\\";
					  	else if(s1=="\\'")
					  	s1="\'";
					      	else if(s1=="\\a")
					  	s1="\a";
					    	else if(s1=="\\f")
					  	s1="\f";
					   	else if(s1=="\\r")
					   	s1="\r";
					   	else if(s1=="\\b")
					  	s1="\b";
					   	else if(s1=="\\v")
					  	s1="\v";
					   	else if(s1=="\\0")
					  	s1="\0";
					  	else if(s1=="\\\"")
					 	 s1="\"";
						 t=t+s1;
						 
						}
<str>\\{newline}				{l=l+yytext; IncLine();line++;}
<str>{newline}				{
						
						cout<<"Error at line no "<<getline()-line<<": Unterminated String "<<l<<endl<<endl;
						IncLine();
						IncErr();
						BEGIN INITIAL;
					}
<str>\"				{
						l=l+yytext;
						t=t+yytext;
						string typ="STRING";
						token<<"<"<<typ<<", "<<t<<"> ";
						cout<<"Line no "<<getline()-line<<": Token <STRING> Lexeme "<<l<<" found";
						cout<<" --> <"<<typ<<", "<<t<<"> "<<endl<<endl;
						t.clear();
						l.clear();
						line=0;
						BEGIN INITIAL;
					}
\/\/						{
						cout<<"Line no "<<getline()<<": Token <COMMENT> Lexeme //";
						BEGIN cmnt_single;
						}
<cmnt_single>({chars}|{WHITESPACE})+		{
						string s=yytext;
						cout<<s;
						
						
						}
<cmnt_single>\\{newline}							{
										string s=yytext;
										cout<<s;
										IncLine();
										}
<cmnt_single>{newline}		{
					cout<<" found"<<endl<<endl;
					IncLine();
					BEGIN INITIAL;}
\/\*								{
									BEGIN cmnt_mult;
									string s=yytext;
									line=0;
									l=yytext;
								}
<cmnt_mult>\*\/					{
								l=l+yytext;
								cout<<"Line no "<<getline()-line<<": Token <COMMENT> Lexeme "<<l;
								cout<<" found"<<endl<<endl;
								line=0;
								l.clear();
								BEGIN INITIAL;
							}
<cmnt_mult><<EOF>>					{
							cout<<"Error at line no "<<getline()-line<<": Unterminated Comment "<<l<<endl<<endl;
							IncErr();
							l.clear();
							line=0;
							BEGIN INITIAL;
							}
<cmnt_mult>{newline} {l=l+yytext; IncLine();line++;}
<cmnt_mult>. {l=l+yytext;}	
<<EOF>>	{ st->print_all();
		//cout<<endl;
		cout<<"Total lines: "<<getline()<<endl;
		cout<<"Total errors: "<<getErr()<<endl; 
		return 0;}						
. {cout<<"Error at line no "<<getline()<<": Unrecognized character "<<yytext<<endl<<endl; IncErr();}

%%
int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	token.open("token.txt",ios::out);
	freopen("log.txt","w",stdout);
	cout<<endl;
	yyin= fin;
	yylex();
	
	fclose(yyin);
	token.close();
	
	return 0;
}
