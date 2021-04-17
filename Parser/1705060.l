%option noyywrap yylineno
%x cmnt_single
%x cmnt_mult
%{
#include<bits/stdc++.h>
#include "Symbol_table.h"
#include "y.tab.h"
using namespace std;
string t,l;
int line;
extern int line_count;
extern int error;
extern void IncLine();
extern int getline();	
extern void IncErr();
	
extern int getErr();
void yyerror(char *);

%}



digit	[0-9]
AlphaNumeric [a-zA-Z0-9_]
special (\\t|\\n|(\\\\)|(\\')|\\a|\\f|\\r|\\b|\\v|\\0|\\\")
chars [a-zA-Z0-9_!@#$\%\^&\*\(\)\-\+=\{\}\[\]\|\?/\<\>,\.;:]
WHITESPACE [ \t\f\r\v]+ 
newline (\n|\r\n)
%%
{WHITESPACE} 				{}
{newline}  				{IncLine();}
"if" {return IF;}
"else" {return ELSE;}
"for" {return FOR;}
"while" {return WHILE;}
"do" {return DO;}
"int" {return INT;}
"float" {return FLOAT;}
"double" {return DOUBLE;}
"char" {return CHAR;}
"return" {return RETURN;}
"void" {return VOID;}
"default"	{return DEFAULT;}
"printf"	{return PRINTLN;}
(\+\+)					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"INCOP");
						yylval.siv = si;
						return INCOP;
					}
(\-\-)					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"DECOP");
						yylval.siv = si;
						return DECOP;
					}
[+-]					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"ADDOP");
						yylval.siv = si;
						return ADDOP;
					}
[\*/%]					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"MULOP");
						yylval.siv = si;
						return MULOP;
					}
[=]	   				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"ASSIGNOP");
						yylval.siv = si;
						return ASSIGNOP;
					}
(<|>|<=|>=|==|!=)			{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"RELOP");
						yylval.siv = si;
						return RELOP;
					}
(&&|\|\|)				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"LOGICOP");
						yylval.siv = si;
						return LOGICOP;
					}
!					{
						return NOT;
					}
\(					{
						return LPAREN;
					}
\)					{
						return RPAREN;
					}
\[					{
						return LTHIRD;
					}
\]					{
						return RTHIRD;
					}
, 					{
						return COMMA;
					}
; 					{
						return SEMICOLON;
					}
\{ 					{
						return LCURL;
					}
\}					{
						return RCURL;
					}
[a-zA-Z_]{AlphaNumeric}* 		{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"ID");
						yylval.siv = si;
						return ID;
					}
{digit}+[a-zA-Z_]+			{
						cout<<"Error at line no "<<getline()<<": Invalid prefix on ID or invalid suffix on Number "<<yytext<<endl<<endl;
						IncErr();
					}										
{digit}+ 				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_INT");
						yylval.siv = si;
						return CONST_INT;
					}
({digit}*)?(\.{digit}+)?(E[+-]?{digit}+)?	 {
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_FLOAT");
						yylval.siv = si;
						return CONST_FLOAT;
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
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_CHAR");
						yylval.siv = si;
						return CONST_CHAR;
						
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
<<EOF>>	{ 
		//cout<<endl;
		cout<<"Total lines: "<<getline()<<endl;
		cout<<"Total errors: "<<getErr()<<endl; 
		return 0;}						
. {cout<<"Error at line no "<<getline()<<": Unrecognized character "<<yytext<<endl<<endl; IncErr();}
%%
