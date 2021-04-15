%option noyywrap yylineno
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
"main"	{return MAIN;}
"default"	{return DEFAULT;}
"printf"	{return PRINTLN;}
(\+\+)					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"INCOP");
						yylval = (YYSTYPE)si;
						return INCOP;
					}
(\-\-)					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"DECOP");
						yylval = (YYSTYPE)si;
						return DECOP;
					}
[+-]					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"ADDOP");
						yylval = (YYSTYPE)si;
						return ADDOP;
					}
[\*/%]					{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"MULOP");
						yylval = (YYSTYPE)si;
						return MULOP;
					}
[=]	   				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"ASSIGNOP");
						yylval = (YYSTYPE)si;
						return ASSIGNOP;
					}
(<|>|<=|>=|==|!=)			{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"RELOP");
						yylval = (YYSTYPE)si;
						return RELOP;
					}
(&&|\|\|)				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"LOGICOP");
						yylval = (YYSTYPE)si;
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
						yylval = (YYSTYPE)si;
						return ID;
					}					
{digit}+ 				{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_INT");
						yylval = (YYSTYPE)si;
						return CONST_INT;
					}
({digit}*)?(\.{digit}+)?(E[+-]?{digit}+)?	 {
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_FLOAT");
						yylval = (YYSTYPE)si;
						return CONST_FLOAT;
						}

'({chars}|{special})' 			{
						string s=yytext;
						SymbolInfo *si= new  SymbolInfo(s,"CONST_CHAR");
						yylval = (YYSTYPE)si;
						return CONST_CHAR;
						
					}						

%%
