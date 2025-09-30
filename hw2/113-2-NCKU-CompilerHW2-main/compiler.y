/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h"
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static int lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool HAS_ERROR = false;
    int scope = 0;
    int scope_count = 0;
    int addr = -1;
    typedef struct {
        char* name;
        char* type;
        int mut;
        int scope;
        int addr;
        int line_no;
    } Symbol;

    Symbol symbol_table[100];
    int symbol_count = 0;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token LET MUT NEWLINE
%token INT FLOAT BOOL STR
%token TRUE FALSE
%token GEQ LEQ EQL NEQ LOR LAND
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN
%token IF ELSE FOR WHILE LOOP
%token PRINT PRINTLN
%token FUNC RETURN BREAK
%token ARROW AS IN DOTDOT RSHIFT LSHIFT

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> ID

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type
%type <s_val> Expression

/* Yacc will start at this nonterminal */
%start Program

%left LOR
%left LAND
%right '!'
%left '>' '<' EQL NEQ
%left '+' '-'
%left '*' '/' '%'
%right UMINUS

/* Grammar section */
%%

Program
    : GlobalStatementList
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : FunctionDeclStmt
    | NEWLINE
;

FunctionDeclStmt
    : FUNC ID '(' ')' {
        printf("func: %s\n", $2);
        insert_symbol($2, addr, scope);
      } BlockStmt
;

BlockStmt
    : '{' {
        scope++;
        scope_count++;
        create_symbol();
      } StatementList '}' {
        dump_symbol();
        scope--;
        for (int i = 0; i < symbol_count; i++){
            if(symbol_table[i].scope > scope)
                symbol_count = i;
        }
      }
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : VarDeclStmt
    | AssignmentStmt
    | PrintStmt
    | IfStmt
    | WhileStmt
    | BlockStmt 
    | NEWLINE
;

VarDeclStmt
    : LET MUT ID '=' Expression ';'{
        ++addr;
        symbol_table[symbol_count].name = $3;
        symbol_table[symbol_count].type = $5;
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($3, addr, scope);
        ++symbol_count;
    }
    | LET MUT ID ':' Type ';' {
        ++addr;
        symbol_table[symbol_count].name = $3;
        symbol_table[symbol_count].type = $5;
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($3, addr, scope);
        ++symbol_count;
    }
    | LET MUT ID ':' Type '=' Expression ';' {
        ++addr;
        symbol_table[symbol_count].name = $3;
        symbol_table[symbol_count].type = $5;
        symbol_table[symbol_count].mut = 1;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($3, addr, scope);
        ++symbol_count;
    }
    | LET ID ':' Type '=' Expression ';' {
        ++addr;
        symbol_table[symbol_count].name = $2;
        symbol_table[symbol_count].type = $4;
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($2, addr, scope);
        ++symbol_count;
    }
    | LET ID ':' Type ';' {
        ++addr;
        symbol_table[symbol_count].name = $2;
        symbol_table[symbol_count].type = $4;
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($2, addr, scope);
        ++symbol_count;
    }
    | LET ID ':' Type '=' '"' Expression '"' ';' {
        ++addr;
        symbol_table[symbol_count].name = $2;
        symbol_table[symbol_count].type = $4;
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($2, addr, scope);
        ++symbol_count;
    }
    | LET ID ':' Type '=' '[' ExpressionList ']' ';'{
        ++addr;
        symbol_table[symbol_count].name = $2;
        symbol_table[symbol_count].type = $4;
        symbol_table[symbol_count].mut = 0;
        symbol_table[symbol_count].scope = scope;
        symbol_table[symbol_count].addr = addr;
        symbol_table[symbol_count].line_no = yylineno + 1;
        insert_symbol($2, addr, scope);
        ++symbol_count;
    }
;

IfStmt
    : IF Expression BlockStmt
    | IF Expression BlockStmt ELSE BlockStmt
;

WhileStmt
    : WHILE Expression BlockStmt
;

AssignmentStmt
    : ID '=' Expression ';' {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            printf("error:%d: undefined: %s\n", yylineno + 1, $1);
        }else{
            printf("ASSIGN\n");

            if (symbol_table[idx].mut == 0) 
                printf("error:%d: cannot borrow immutable borrowed content `%s` as mutable\n", yylineno + 1, $1);   
        } 
    }
    | ID '=' '"' Expression '"' ';' {
        printf("ASSIGN\n");
    }
    | ID ADD_ASSIGN Expression ';' {
        printf("ADD_ASSIGN\n");
    }
    | ID SUB_ASSIGN Expression ';' {
        printf("SUB_ASSIGN\n");
    }
    | ID MUL_ASSIGN Expression ';' {
        printf("MUL_ASSIGN\n");
    }
    | ID DIV_ASSIGN Expression ';' {
        printf("DIV_ASSIGN\n");
    }
    | ID REM_ASSIGN Expression ';' {
        printf("REM_ASSIGN\n");
    }
;

PrintStmt
    : PRINTLN '(' Expression ')' ';' {
        if (strcmp($3, "i32") == 0)
            printf("PRINTLN i32\n");
        else if (strcmp($3, "f32") == 0)
            printf("PRINTLN f32\n");
        else if (strcmp($3, "bool") == 0)
            printf("PRINTLN bool\n");
        else if(strcmp($3, "str") == 0)
            printf("PRINTLN str\n");
        else if(strcmp($3, "array") == 0)
            printf("PRINTLN array\n");
    }
    | PRINT '(' Expression ')' ';' {
        if (strcmp($3, "i32") == 0)
            printf("PRINT i32\n");
        else if (strcmp($3, "f32") == 0)
            printf("PRINT f32\n");
        else if (strcmp($3, "bool") == 0)
            printf("PRINT bool\n");
        else if(strcmp($3, "str"))
            printf("PRINT str\n");
        else if(strcmp($3, "array") == 0)
            printf("PRINTLN array\n");
    }
    | PRINTLN '(' '"' STRING_LIT '"' ')' ';' {
        printf("STRING_LIT \"%s\"\n", $4);
        printf("PRINTLN str\n");
    }
;

ExpressionList
    : Expression
    | ExpressionList ',' Expression
;

Expression
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>1);
        $$ = "i32";
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>1);
        $$ = "f32";
    }
    | TRUE {
        printf("bool TRUE\n");
        $$ = "bool";
    }
    | FALSE {
        printf("bool FALSE\n");
        $$ = "bool";
    }
    | ID {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            printf("error:%d: undefined: %s\n", yylineno + 1, $1);
            $$ = "undefined";
        } else {
            printf("IDENT (name=%s, address=%d)\n", $1, symbol_table[idx].addr);  
            $$ = symbol_table[idx].type;
        }
    }
    | ID '[' INT_LIT ']'{
        int idx = lookup_symbol($1);
        printf("IDENT (name=%s, address=%d)\n", $1, symbol_table[idx].addr);  
        printf("INT_LIT %d\n", $<i_val>3);
        $$ = "array";
    } 
    | '-' Expression %prec UMINUS {
        printf("NEG\n");
        $$ = $2;
    }
    | '!' Expression {
        printf("NOT\n");
        $$ = "bool";
    }
    | Expression AS Expression {
        printf("AS\n");
        $$ = "as";
    }
    | Expression '+' Expression {
        printf("ADD\n");
        $$ = (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) ? "f32" : "i32";
    }
    | Expression '-' Expression {
        printf("SUB\n");
        $$ = (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) ? "f32" : "i32";
    }
    | Expression '*' Expression {
        printf("MUL\n");
        $$ = (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) ? "f32" : "i32";
    }
    | Expression '/' Expression {
        printf("DIV\n");
        $$ = (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) ? "f32" : "i32";
    }
    | Expression '%' Expression {
        printf("REM\n");
        $$ = "i32";
    }
    | Expression '>' Expression {
        if (strcmp($1, "undefined") == 0) {
            printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno + 1, $1, $3);
        }

        printf("GTR\n");
        $$ = "bool";
    }
    | Expression '<' Expression {
        printf("LSS\n");
        $$ = "bool";
    }
    | Expression LSHIFT Expression {
        if (strcmp($1, $3) != 0) {
            printf("error:%d: invalid operation: LSHIFT (mismatched types %s and %s)\n", yylineno + 1, $1, $3);
        }
        printf("LSHIFT\n");
        $$ = "lshift";
    }
    | Expression EQL Expression {
        printf("EQL\n");
        $$ = "eql";
    }
    | Expression NEQ Expression {
        printf("NEQ\n");
        $$ = "neq";
    }
    | Expression LAND Expression {
        printf("LAND\n");
        $$ = "bool";
    }
    | Expression LOR Expression {
        printf("LOR\n");
        $$ = "bool";
    }
    | '(' Expression ')' {
        $$ = $2;
    }
    | STRING_LIT {
        printf("STRING_LIT \"%s\"\n", $<s_val>1);
        $$ = "str";
    }
    | '"' '"'{
        printf("STRING_LIT \"\"\n");
        $$ = "str";
    }
    | Expression AS Type {
        if (strcmp($1, "f32") == 0 && strcmp($3, "i32") == 0) {
            printf("f2i\n");
            $$ = "i32";
        } else if (strcmp($1, "i32") == 0 && strcmp($3, "f32") == 0) {
            printf("i2f\n");
            $$ = "f32";
        } else {
            $$ = $3;
        }
    }
    
;

Type
    : INT   { $$ = "i32"; }
    | FLOAT { $$ = "f32"; }
    | BOOL  { $$ = "bool"; }
    | STR   { $$ = "string"; }
    | '&' STR { $$ = "str"; }
    | '[' INT ';' Expression ']' {$$ = "array"; }

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yylineno = 0;
    create_symbol();
    yyparse();
    dump_symbol();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol() {
    printf("> Create symbol table (scope level %d)\n", scope);
}

static void insert_symbol(const char* name, int addr, int _scope) {
    printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, _scope);
}

static int lookup_symbol(const char* name) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (symbol_table[i].scope <= scope && strcmp(symbol_table[i].name, name) == 0 ) {
            return i;
        }   
    }
    return -1;
}

static void dump_symbol() {
    printf("\n> Dump symbol table (scope level: %d)\n", scope);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Mut", "Type", "Addr", "Lineno", "Func_sig");

    int index = 0;
    for (int i = 0; i < symbol_count; i++) {
        if (symbol_table[i].scope == scope) {
            printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
                   index,
                   symbol_table[i].name,
                   symbol_table[i].mut,                      
                   symbol_table[i].type,
                   symbol_table[i].addr,                     
                   symbol_table[i].line_no,
                   "-");                     // 非函式填 "-"
            index++;
        }
        
    }

    if (scope == 0) {
        printf("%-10d%-10s%-10d%-10s%-10d%-10d%-10s\n",
               0, "main", -1, "func", -1, 1, "(V)V");
    }
}
