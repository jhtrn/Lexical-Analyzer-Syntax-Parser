%{
 	#ifndef YYSTYPE
   	#define YYSTYPE char*
   	#endif
    	#include <stdio.h>
    	#include <stdlib.h>
   	#include <string.h>
	#include <assert.h>
	typedef int bool;
	#define true 1
	#define false 0
   	int yylex();
    	void yyerror( char *);
    	void print_header(char *);
	void log_print_declist(char *str);
	void print_assign();
	void print_cout();
	void saveID(char *);
	void checkID(char *);
	char *ID[10];
	void print_variables(char ** ,int );	
	int counter = 0;
%}
%token digit number letter 
%right string 
%token RIGHT_PAREN 
%right  id LEFT_PAREN END
%token PROGRAM  VAR  BEG    INTEGER  PRINT 
%token EQ  MULT DIV PLUS SUB   RIGHT_PAREN
%token semicolon  colon  comma  period
%token MSP
%start Input
%%

Input
   	: mainprogram var begEnd {print_end();}
	;
mainprogram
	:  PRGRM pname semicolon {print_header($1);}	
	| pname semicolon {yyerror("PROGRAM is expected");}
   	;
PRGRM
	: PROGRAM
	| id {yyerror("PROGRAM is spelled wrong");} //gold
	;
var
	: VAR declist semicolon 
   	| declist semicolon {yyerror("VAR is expected");}
    	| VAR declist {yyerror("; is missing");}
	| id declist semicolon {yyerror("VAR is spelled wrong");} 
    	;
begEnd
  	: begstate statlist endstate 
	| statlist  {yyerror("BEGIN is expected before");}
	;
begstate	
	: BEG  
	| id  {yyerror("BEGIN is spelled wrong");} 
	;
endstate
	: END period
	| END {yyerror(". is expected");}
	| period {yyerror("END is expected");}
	;
pname
  	: id
	;
declist
	: dec colon type  {print_variables(ID,counter);log_print_declist($$);}
   	| dec type {yyerror(": is expected");}
    	| dec colon {yyerror("ID type is expected");}
	;
dec
	: ID comma dec 
    	| ID dec {yyerror(", is missing");}
	| ID  
	;
ID: id	{saveID($1);} 
	;
statlist
    	: stat {$$ = $1;}
	| stat statlist  {$$ = $1;}
	;
stat
    	: print {print_cout($1);}
	| assign {print_assign($$);}
	;
print
	:PRINT LEFT_PAREN output RIGHT_PAREN semicolon {$$ = $3;}
	|PRINT LEFT_PAREN output RIGHT_PAREN {yyerror("; is missing");}
    	| LEFT_PAREN output RIGHT_PAREN{yyerror("PRINT is expected");}
    	| PRINT output RIGHT_PAREN{yyerror("( is missing");}
    	| PRINT LEFT_PAREN output{yyerror(") is expected");}
	;
output
	:id {checkID($1); $$ = $1;}
   	|string comma id {$$ = $1; strcat($$, " << "); strcat($$, $3);}
	|string id {yyerror(", is missing");}
	;
assign
	:id EQ expr semicolon {checkID($1); $$ = $1; strcat($$, " = "); strcat($$, $3);}
	|id EQ expr {checkID($1); yyerror("; is missing");}
	;
expr
   	:term  {$$ = $1;}
    	| expr PLUS term {$$ = $1; strcat($$, " + "); strcat($$, $3);}
	| expr SUB term  {$$ = $1; strcat($$, " - "); strcat($$, $3);}
	;
term
	:term MULT factor  {$$ = $1; strcat($$, " * "); strcat($$, $3);}
	| term DIV factor  {$$ = $1; strcat($$, " / "); strcat($$, $3);}
	| factor  {$$ = $1;}
	;
factor
	:id {checkID($1); $$ = $1;}
	| number {$$ = $1;}
	| LEFT_PAREN expr RIGHT_PAREN {$$ = " ( "; strcat($$, $1); strcat($$, " ) ");}
	;
type
	:INTEGER
	;
	
%%

int main()
{
    yyparse();
}
void yyerror (char  *s)
{
    extern int yylineno;
    extern char *yytext;
    
    if(s[0] == ';') 
    {
	fprintf(stderr, "ERROR: '%s' on line %d\n", s, yylineno-1);
    }
   
    else if(isalpha(s[0]))
    {	
	fprintf(stderr, "ERROR: unknown '%s' on line %d\n", s, yylineno);
    }
    else
    {
      	fprintf(stderr, "ERROR: '%s' on line %d\n", s, yylineno);
    } 
	exit(1);
}

void print_header(char * str)
{
    FILE *logfile = fopen("logfile.log", "a"); //Open log file
    FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open log file
    freopen(NULL,"w+",CPP_final_file);
    fprintf(logfile, "Compiled on: %s \n", __DATE__);
    fprintf(logfile, "at %s ", __TIME__);
    fprintf(logfile, "Printing header %s \n",str);
    fprintf(CPP_final_file,"#include <iostream>\nusing namespace std;\nint main()\n{\n");
    fprintf(CPP_final_file,"int ");
    fclose(logfile); //close log file
    fclose(CPP_final_file);  //close cpp file
}

void log_print_declist(char *str)
{
    FILE *logfile = fopen("logfile.log", "a"); //Open log file
    fprintf(logfile, "at %s ", __TIME__);
    fprintf(logfile, "Printing declaration list %s \n",str);
    fclose(logfile); //close log file
}

void print_cout(char * str)
{
    FILE *logfile = fopen("logfile.log", "a"); //Open log file
    fprintf(logfile, "at %s ", __TIME__);
    fprintf(logfile, "Printing cout declarations %s \n",str);
    fclose(logfile); //close log file
    FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file
    fprintf(CPP_final_file,"cout << %s << endl;\n", str);
    fclose(CPP_final_file); //close cpp file
}

void print_assign(char *str)
{
    FILE *logfile = fopen("logfile.log", "a"); //Open log file
    fprintf(logfile, "at %s ", __TIME__);
    fprintf(logfile, "Printing assignment declarations %s \n",str);
    fclose(logfile);
    FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file
    fprintf(CPP_final_file, "%s;\n",str);
    fclose(CPP_final_file); //close cpp file
}

void print_end()
{
    FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file
    fprintf(CPP_final_file, "return 0;\n}\n");
    fclose(CPP_final_file); //close cpp file
}

void checkID(char *idName)
{
    int i=0;
    bool valid=true;
    for(i=0; i <counter;i++)
    {
        if(strcmp(idName,ID[i])!=0)
	{
	    valid=false;
	}
	else
	{
	    valid=true;
	    break;
	}	
    }
    if(valid==false)
    yyerror(idName);

}

void saveID(char *idName)
{	
    ID[counter] = idName;
    counter++;
	
    FILE *logfile = fopen("logfile.log", "a"); //Open log file
    fprintf(logfile, "Printing known variable: %s \n",idName);
    fclose(logfile); //close log file
}

void print_variables(char ** Vars, int size)
{
    int i = 0;
    FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file

    for(i=0;i< size-1;i++)
	fprintf(CPP_final_file,"%s, ",Vars[i]);

    fprintf(CPP_final_file,"%s;\n",Vars[size-1]);
    fclose(CPP_final_file); //close cpp file
}
