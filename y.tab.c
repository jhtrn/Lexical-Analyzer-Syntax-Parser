#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 10 "syntax.y"
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
#line 41 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define digit 257
#define number 258
#define letter 259
#define string 260
#define RIGHT_PAREN 261
#define id 262
#define LEFT_PAREN 263
#define END 264
#define PROGRAM 265
#define VAR 266
#define BEG 267
#define INTEGER 268
#define PRINT 269
#define EQ 270
#define MULT 271
#define DIV 272
#define PLUS 273
#define SUB 274
#define semicolon 275
#define colon 276
#define comma 277
#define period 278
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    4,    4,    2,    2,    2,    2,    3,
    3,    7,    7,    9,    9,    9,    5,    6,    6,    6,
   10,   10,   10,   12,    8,    8,   13,   13,   14,   14,
   14,   14,   14,   14,   16,   16,   16,   15,   15,   17,
   17,   17,   18,   18,   18,   19,   19,   19,   11,
};
static const short yylen[] = {                            2,
    3,    3,    2,    1,    1,    3,    2,    2,    3,    3,
    1,    1,    1,    2,    1,    1,    1,    3,    2,    2,
    3,    2,    1,    1,    1,    2,    1,    1,    5,    2,
    1,    2,    4,    4,    1,    3,    2,    4,    3,    1,
    3,    3,    3,    3,    1,    1,    1,    3,    1,
};
static const short yydefred[] = {                         0,
    0,    4,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   17,    0,    3,   24,    0,    0,    0,   31,
   12,    0,    1,    0,   11,    0,   27,   28,    7,   49,
    0,   19,    0,   22,    2,    9,    6,   30,    0,    0,
   35,    0,   32,    0,    0,   26,   18,   21,   47,   46,
    0,    0,    0,   45,   37,    0,    0,    0,   16,   10,
    0,    0,    0,   38,    0,    0,   36,    0,   33,   14,
   48,    0,    0,   43,   44,   29,
};
static const short yydgoto[] = {                          3,
    4,    9,   23,    5,    6,   10,   24,   25,   60,   11,
   32,   12,   26,   27,   28,   43,   52,   53,   54,
};
static const short yysindex[] = {                      -201,
    0,    0,    0, -252, -257, -231, -251, -251, -224, -223,
 -264, -260,    0, -219,    0,    0, -197, -196, -228,    0,
    0, -200,    0, -214,    0, -214,    0,    0,    0,    0,
 -188,    0, -251,    0,    0,    0,    0,    0, -204, -259,
    0, -192,    0, -228, -258,    0,    0,    0,    0,    0,
 -204, -208, -238,    0,    0, -181, -253, -195,    0,    0,
 -248, -204, -204,    0, -204, -204,    0, -193,    0,    0,
    0, -238, -238,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
 -246,    0,    0,    0,    0,    0, -236,    0,    0,    0,
    0, -261,    0,    0,    0,    0,    0, -216, -212,    0,
    0,    0,    0,    0,    0,   31,    0,    0,    0,    0,
 -239,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    9,    1,    0,    0,    0,    0,   84,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   27,    0,    0,
    0,   19,   37,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,   80,   65,    0,   45,    0,  -12,
   55,    0,    0,    0,    0,   46,   36,   12,   11,
};
#define YYTABLESIZE 315
static const short yytable[] = {                         34,
   40,   16,   55,   30,   13,   58,   23,   68,   39,    7,
   16,   31,   71,    8,   23,    5,   33,   56,   41,   59,
   48,   69,   20,   20,   62,   63,   34,   20,   17,   20,
   25,   24,   65,   66,   38,   20,   42,   19,   20,   24,
   24,   39,   21,   15,   22,    8,    8,   44,   20,   13,
    8,   29,    8,   49,   22,   35,   13,   50,   51,   40,
    1,   41,   42,    2,   62,   63,   64,   40,   45,   41,
   46,   17,   18,   72,   73,   74,   75,   36,   37,   30,
   67,   76,   70,   15,   14,   47,   61,   57,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   40,   40,   40,   40,    0,    0,    0,    0,   40,
   39,   39,   39,   40,   40,   40,    0,   39,   40,   41,
   41,   41,   41,    0,    0,    0,   39,   41,   34,   34,
   34,   41,   41,   41,   25,   34,   41,   42,   42,   42,
   42,    0,    0,    0,   34,   42,    0,    0,   25,   42,
   42,   42,    0,    0,   42,
};
static const short yycheck[] = {                         12,
    0,  262,  262,  268,  262,  264,  268,  261,    0,  262,
  262,  276,  261,  266,  276,  262,  277,  277,    0,  278,
   33,  275,  262,  263,  273,  274,    0,  267,  275,  269,
    0,  268,  271,  272,  263,  275,    0,  262,  263,  276,
  277,  270,  267,  275,  269,  262,  263,  262,  263,  262,
  267,  275,  269,  258,  269,  275,  269,  262,  263,  260,
  262,  262,  263,  265,  273,  274,  275,  260,   24,  262,
   26,    7,    8,   62,   63,   65,   66,  275,  275,  268,
  262,  275,  278,    0,    5,   31,   51,   42,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,  262,  263,  264,   -1,   -1,   -1,   -1,  269,
  262,  263,  264,  273,  274,  275,   -1,  269,  278,  261,
  262,  263,  264,   -1,   -1,   -1,  278,  269,  262,  263,
  264,  273,  274,  275,  264,  269,  278,  261,  262,  263,
  264,   -1,   -1,   -1,  278,  269,   -1,   -1,  278,  273,
  274,  275,   -1,   -1,  278,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"digit","number","letter",
"string","RIGHT_PAREN","id","LEFT_PAREN","END","PROGRAM","VAR","BEG","INTEGER",
"PRINT","EQ","MULT","DIV","PLUS","SUB","semicolon","colon","comma","period",
"illegal-symbol",
};
static const char *yyrule[] = {
"$accept : Input",
"Input : mainprogram var begEnd",
"mainprogram : PRGRM pname semicolon",
"mainprogram : pname semicolon",
"PRGRM : PROGRAM",
"PRGRM : id",
"var : VAR declist semicolon",
"var : declist semicolon",
"var : VAR declist",
"var : id declist semicolon",
"begEnd : begstate statlist endstate",
"begEnd : statlist",
"begstate : BEG",
"begstate : id",
"endstate : END period",
"endstate : END",
"endstate : period",
"pname : id",
"declist : dec colon type",
"declist : dec type",
"declist : dec colon",
"dec : ID comma dec",
"dec : ID dec",
"dec : ID",
"ID : id",
"statlist : stat",
"statlist : stat statlist",
"stat : print",
"stat : assign",
"print : PRINT LEFT_PAREN output RIGHT_PAREN semicolon",
"print : id LEFT_PAREN",
"print : LEFT_PAREN",
"print : PRINT output",
"print : PRINT LEFT_PAREN output semicolon",
"print : PRINT LEFT_PAREN output RIGHT_PAREN",
"output : id",
"output : string comma id",
"output : string id",
"assign : id EQ expr semicolon",
"assign : id EQ expr",
"expr : term",
"expr : expr PLUS term",
"expr : expr SUB term",
"term : term MULT factor",
"term : term DIV factor",
"term : factor",
"factor : id",
"factor : number",
"factor : LEFT_PAREN expr RIGHT_PAREN",
"type : INTEGER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 133 "syntax.y"

int main()
{
	yyparse();
}

//Function purpose: Returns error message if there is error in program, exits from yacc
void yyerror (char  *s)
{
    extern int yylineno;
    extern char *yytext;
    
    if(s[0] == ';'|| s[0] == '.') 
    {
	fprintf(stderr, "ERROR: '%s' on line %d\n", s, yylineno-1);
    }
    else if (isalpha(s[0])) 
    {
	fprintf(stderr, "ERROR: unknown '%s' on line %d\n", s, yylineno);
    }
    else
    {
      	fprintf(stderr, "ERROR: '%s' on line %d\n", s, yylineno);
    } 
	exit(1);
}

//Function purpose: Writes header of program to cpp file and records action to log file
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

//Function purpose: Writes the compilation time of printing declaration list to log file
void log_print_declist(char *str)
{
	FILE *logfile = fopen("logfile.log", "a"); //Open log file
    	fprintf(logfile, "at %s ", __TIME__);
	fprintf(logfile, "Printing declaration list %s \n",str);
    	fclose(logfile); //close log file
}

//Writes the compilation time and variables declared to log file
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

//Function purpose: Writes compilation time of printing assignment declarations to log file
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

//Function purpose: Writes closing statement to cpp file
void print_end()
{
	FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file
	fprintf(CPP_final_file, "return 0;\n}\n");
   	fclose(CPP_final_file); //close cpp file
}

//Function purpose: Checks if any variables used in program are undeclared
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

//Function purpose: Saves list of variables declared in program into array and records action to log file
void saveID(char *idName)
{	
	ID[counter] = idName;
	counter++;
	
	FILE *logfile = fopen("logfile.log", "a"); //Open log file
	fprintf(logfile, "Printing known variable: %s \n",idName);
    	fclose(logfile); //close log file
}

//Function purpose: Prints variables declared to cpp file
void print_variables(char ** Vars, int size)
{
	int i = 0;
	FILE *CPP_final_file = fopen("abc13.cpp", "a"); //Open cpp file

	for(i=0;i< size-1;i++)
		fprintf(CPP_final_file,"%s, ",Vars[i]);

	fprintf(CPP_final_file,"%s;\n",Vars[size-1]);
	fclose(CPP_final_file); //close cpp file
}
/*===========================================================================================
 				End of yacc file: syntax.y
===========================================================================================*/
#line 460 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 43 "syntax.y"
	{print_end();}
break;
case 2:
#line 46 "syntax.y"
	{print_header(yystack.l_mark[-2]);}
break;
case 3:
#line 47 "syntax.y"
	{yyerror("PROGRAM is expected");}
break;
case 5:
#line 51 "syntax.y"
	{yyerror("PROGRAM is spelled wrong");}
break;
case 7:
#line 55 "syntax.y"
	{yyerror("VAR is expected");}
break;
case 8:
#line 56 "syntax.y"
	{yyerror("; is missing");}
break;
case 9:
#line 57 "syntax.y"
	{yyerror("VAR is spelled wrong");}
break;
case 11:
#line 61 "syntax.y"
	{yyerror("BEGIN is expected");}
break;
case 13:
#line 65 "syntax.y"
	{yyerror("BEGIN is spelled wrong");}
break;
case 15:
#line 69 "syntax.y"
	{yyerror(". is expected");}
break;
case 16:
#line 70 "syntax.y"
	{yyerror("END is expected");}
break;
case 18:
#line 76 "syntax.y"
	{print_variables(ID,counter);log_print_declist(yyval);}
break;
case 19:
#line 77 "syntax.y"
	{yyerror(": is expected");}
break;
case 20:
#line 78 "syntax.y"
	{yyerror("ID type is expected");}
break;
case 22:
#line 82 "syntax.y"
	{yyerror(", is missing");}
break;
case 24:
#line 86 "syntax.y"
	{saveID(yystack.l_mark[0]);}
break;
case 25:
#line 89 "syntax.y"
	{yyval = yystack.l_mark[0];}
break;
case 26:
#line 90 "syntax.y"
	{yyval = yystack.l_mark[-1];}
break;
case 27:
#line 93 "syntax.y"
	{print_cout(yystack.l_mark[0]);}
break;
case 28:
#line 94 "syntax.y"
	{print_assign(yyval);}
break;
case 29:
#line 97 "syntax.y"
	{yyval = yystack.l_mark[-2];}
break;
case 30:
#line 98 "syntax.y"
	{yyerror("PRINT is spelled wrong");}
break;
case 31:
#line 99 "syntax.y"
	{yyerror("PRINT is expected");}
break;
case 32:
#line 100 "syntax.y"
	{yyerror("( is missing");}
break;
case 33:
#line 101 "syntax.y"
	{yyerror(") is expected");}
break;
case 34:
#line 102 "syntax.y"
	{yyerror("; is missing");}
break;
case 35:
#line 105 "syntax.y"
	{checkID(yystack.l_mark[0]); yyval = yystack.l_mark[0];}
break;
case 36:
#line 106 "syntax.y"
	{ yyval = yystack.l_mark[-2]; strcat(yyval, " << "); strcat(yyval, yystack.l_mark[0]);}
break;
case 37:
#line 107 "syntax.y"
	{yyerror(", is missing");}
break;
case 38:
#line 110 "syntax.y"
	{checkID(yystack.l_mark[-3]); yyval = yystack.l_mark[-3]; strcat(yyval, " = "); strcat(yyval, yystack.l_mark[-1]);}
break;
case 39:
#line 111 "syntax.y"
	{checkID(yystack.l_mark[-2]); yyerror("; is missing");}
break;
case 40:
#line 114 "syntax.y"
	{yyval = yystack.l_mark[0];}
break;
case 41:
#line 115 "syntax.y"
	{yyval = yystack.l_mark[-2]; strcat(yyval, " + "); strcat(yyval, yystack.l_mark[0]);}
break;
case 42:
#line 116 "syntax.y"
	{yyval = yystack.l_mark[-2]; strcat(yyval, " - "); strcat(yyval, yystack.l_mark[0]);}
break;
case 43:
#line 119 "syntax.y"
	{yyval = yystack.l_mark[-2]; strcat(yyval, " * "); strcat(yyval, yystack.l_mark[0]);}
break;
case 44:
#line 120 "syntax.y"
	{yyval = yystack.l_mark[-2]; strcat(yyval, " / "); strcat(yyval, yystack.l_mark[0]);}
break;
case 45:
#line 121 "syntax.y"
	{yyval = yystack.l_mark[0];}
break;
case 46:
#line 124 "syntax.y"
	{checkID(yystack.l_mark[0]); yyval = yystack.l_mark[0];}
break;
case 47:
#line 125 "syntax.y"
	{yyval = yystack.l_mark[0];}
break;
case 48:
#line 126 "syntax.y"
	{yyval = " ( "; strcat(yyval, yystack.l_mark[-2]); strcat(yyval, " ) ");}
break;
#line 822 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
