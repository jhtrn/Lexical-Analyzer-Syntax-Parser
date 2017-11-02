/*===========================================================================================
    Authors:     Rodrigo Figueroa and Justine Tran
    Course:      CPSC 323
    Assignment:  Final Project
    Due date:    May 9, 2016
    File name:   token.l
    Purpose:     Removes all documentation, blank lines, and extra spaces from the program.      
===========================================================================================*/
%{
	#ifndef YYSTYPE
    	#define YYSTYPE char*
    	#endif
	extern YYSTYPE yylval;  
	#include "y.tab.h"
	#include <string.h>      

	typedef int bool;
	#define true 1
	#define false 0
	#define YYLEX yylex ()
%}
%option yylineno 

/*Some token definitions*/
whiteSpace [ \t\n]
digit 		[0-9]
number  	{digit}+
letter  	[A-Za-z]
id		{letter}({letter}|{digit})*
string 		\"[^\"]*\"

%%
{whiteSpace}  {}
{id}		      {	/*Return reserved words as tokens if matched, else return id */
			yylval = strdup(yytext); 
			if(strcmp(yylval,"PROGRAM")==0)
				return PROGRAM;
			else if(strcmp(yylval,"VAR")==0)
				return VAR;
			else if(strcmp(yylval,"BEGIN")==0)
				return BEG;
			else if(strcmp(yylval,"END")==0)
				return END;
			else if(strcmp(yylval,"INTEGER")==0)
				return INTEGER;
			else if(strcmp(yylval,"PRINT")==0)
				return PRINT;
			else
				return(id);
		       }
{number}                {yylval = strdup(yytext); return(number);}
{string}                {yylval = strdup(yytext); return(string);}
";"            		{return (semicolon);}
":"                     {return(colon);}
","                     {return(comma);}
"."                     {return(period);}
"="                     {return(EQ);}
"*"                     {return(MULT);}
"+"                     {return(PLUS);}
"-"			{return(SUB);}
"\\" 			{return(DIV);}
"("                     {return(LEFT_PAREN);}
")"                     {return(RIGHT_PAREN);}
%%

int yywrap(){return 1;}
/*===========================================================================================
 				 End of lex file: token.l
===========================================================================================*/
