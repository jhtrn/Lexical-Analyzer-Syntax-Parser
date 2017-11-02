/*===========================================================================================
    Authors:     Rodrigo Figueroa and Justine Tran
    Course:      CPSC 323
    Assignment:  Final Project
    Due date:    May 9, 2016
    File name:   fix.l
    Purpose:     Removes all documentation, blank lines, and extra spaces from the program.      
===========================================================================================*/
%{
	extern int yylval;
%}

%%
\(\*[^\*\)]*\*\)\n        {}  //Ignore comments, includes (*anything not *) then *)
\;" "*\(\*[^\*\)]*\*\)        {printf(";");}  //Ignore comments, includes (*anything not *) then *)
\t+" "*                 {}  //Remove tab and line up output 
" "+                    {printf(" ");} //Replace multiple spaces with 1 space
\n+                     {printf("\n");}  //Not working, removes only 1 newline
" "*=" "*               {printf(" = ");}  //Have 1 space before and after =
" "*:" "*               {printf(" : ");}  //Have 1 space before and after :
" "*\*" "*              {printf(" * ");}  //Have 1 space before and after *
\)+" "+;+               {printf(");");}   //Ignore space after )  ;
" "+;+                  {printf(";");}   //Ignore space after number ; 
" "+,                  {printf(",");}   //Ignore space before ,
" "*\)                  {printf(" )");}  //Have 1 space before )
\(" "*                  {printf("( ");}  //Have 1 space after (
(`|'|‘|’)                   {printf("\"");}  //Change to double quotes
%%

int main()
{
	yylex();
}
/*===========================================================================================
 				 End of lex file: fix.l
===========================================================================================*/
