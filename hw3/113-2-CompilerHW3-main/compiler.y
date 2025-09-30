
/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_common.h" //Extern variables that communicate with lex
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

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static int lookup_symbol();
    static void dump_symbol();

    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
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

    int label_count = 0;
    int label_count_2 = 0;
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
        CODEGEN(".method public static %s([Ljava/lang/String;)V\n", $2);
        g_indent_cnt++;
        CODEGEN(".limit stack 100\n");
        CODEGEN(".limit locals 100\n");

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

        if (scope == 0) {
            CODEGEN("return\n");
            g_indent_cnt--;
            CODEGEN(".end method\n");
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

        if (strcmp($5, "i32") == 0)
            CODEGEN("istore %d\n", addr);
        else if (strcmp($5, "f32") == 0)
            CODEGEN("fstore %d\n", addr);
        else if (strcmp($5, "str") == 0 || strcmp($5, "string") == 0)
            CODEGEN("astore %d\n", addr);    
        else if (strcmp($5, "bool") == 0)
            CODEGEN("istore %d\n", addr);
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

        if (strcmp($5, "i32") == 0)
            CODEGEN("istore %d\n", addr);
        else if (strcmp($5, "f32") == 0)
            CODEGEN("fstore %d\n", addr);
        else if (strcmp($5, "str") == 0 || strcmp($5, "string") == 0)
            CODEGEN("astore %d\n", addr);    
        else if (strcmp($5, "bool") == 0)
            CODEGEN("istore %d\n", addr);
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

        if (strcmp($4, "i32") == 0)
            CODEGEN("istore %d\n", addr);
        else if (strcmp($4, "f32") == 0)
            CODEGEN("fstore %d\n", addr);
        else if (strcmp($4, "str") == 0 || strcmp($4, "string") == 0)
            CODEGEN("astore %d\n", addr);
        else if (strcmp($4, "bool") == 0)
            CODEGEN("istore %d\n", addr);
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

        if (strcmp($4, "i32") == 0)
            CODEGEN("istore %d\n", addr);
        else if (strcmp($4, "f32") == 0)
            CODEGEN("fstore %d\n", addr);
        else if (strcmp($4, "str") == 0 || strcmp($4, "string") == 0)
            CODEGEN("astore %d\n", addr);
        else if (strcmp($4, "bool") == 0)
            CODEGEN("istore %d\n", addr);
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
        
        if (strcmp($4, "i32") == 0)
            CODEGEN("istore %d\n", addr);
        else if (strcmp($4, "f32") == 0)
            CODEGEN("fstore %d\n", addr);
        else if (strcmp($4, "str") == 0 || strcmp($4, "string") == 0)
            CODEGEN("astore %d\n", addr);    
        else if (strcmp($4, "bool") == 0)
            CODEGEN("istore %d\n", addr);
    }
;

IfStmt
    : IF Expression BlockStmt{
       CODEGEN("L_if_false_%d:\n", label_count_2); 
       label_count_2 ++;
    }
    | IF Expression
        BlockStmt {
            CODEGEN("goto L_if_exit_%d\n", label_count_2); 
        }ELSE { 
            CODEGEN("L_if_false_%d:\n", label_count_2); 
        }BlockStmt{
            CODEGEN("L_if_exit_%d:\n", label_count_2); 
            label_count_2 ++;
    }
;

WhileStmt
    : WHILE { CODEGEN("L_if_true_%d:\n", label_count_2); 
        }Expression BlockStmt{
        CODEGEN("goto L_if_true_%d\n", label_count_2); 
        CODEGEN("L_if_false_%d:\n", label_count_2); 
        label_count_2 ++;
    }
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
            
            if (strcmp(symbol_table[idx].type, "i32") == 0)
                CODEGEN("istore %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "f32") == 0)
                CODEGEN("fstore %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "str") == 0 || strcmp(symbol_table[idx].type, "string") == 0)
                CODEGEN("astore %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "bool") == 0)
                CODEGEN("istore %d\n", symbol_table[idx].addr);
        } 
        
    }
    | ID '=' '"' Expression '"' ';' {
        printf("ASSIGN\n");

        int idx = lookup_symbol($1);
        if (strcmp(symbol_table[idx].type, "str") == 0 || strcmp(symbol_table[idx].type, "string") == 0)
            CODEGEN("astore %d\n", symbol_table[idx].addr);
    }
    | ID ADD_ASSIGN Expression ';' {
        printf("ADD_ASSIGN\n");

        int idx = lookup_symbol($1);
        if (strcmp($3, "i32") == 0) {
            CODEGEN("iload %d\n", symbol_table[idx].addr);  // load x
            CODEGEN("swap\n");
            CODEGEN("iadd\n");
            CODEGEN("istore %d\n", symbol_table[idx].addr); // store x
        } else if (strcmp($3, "f32") == 0) {
            CODEGEN("fload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("fadd\n");
            CODEGEN("fstore %d\n", symbol_table[idx].addr);
        }
    }
    | ID SUB_ASSIGN Expression ';' {
        printf("SUB_ASSIGN\n");

        int idx = lookup_symbol($1);
        if (strcmp($3, "i32") == 0) {
            CODEGEN("iload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("isub\n");
            CODEGEN("istore %d\n", symbol_table[idx].addr);
        } else if (strcmp($3, "f32") == 0) {
            CODEGEN("fload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("fsub\n");
            CODEGEN("fstore %d\n", symbol_table[idx].addr);
        }
    }
    | ID MUL_ASSIGN Expression ';' {
        printf("MUL_ASSIGN\n");

        int idx = lookup_symbol($1);
        if (strcmp($3, "i32") == 0) {
            CODEGEN("iload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("imul\n");
            CODEGEN("istore %d\n", symbol_table[idx].addr);
        } else if (strcmp($3, "f32") == 0) {
            CODEGEN("fload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("fmul\n");
            CODEGEN("fstore %d\n", symbol_table[idx].addr);
        }
    }
    | ID DIV_ASSIGN Expression ';' {
        printf("DIV_ASSIGN\n");

        int idx = lookup_symbol($1);
        if (strcmp($3, "i32") == 0) {
            CODEGEN("iload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("idiv\n");
            CODEGEN("istore %d\n", symbol_table[idx].addr);
        } else if (strcmp($3, "f32") == 0) {
            CODEGEN("fload %d\n", symbol_table[idx].addr);
            CODEGEN("swap\n");
            CODEGEN("fdiv\n");
            CODEGEN("fstore %d\n", symbol_table[idx].addr);
        }
    }
    | ID REM_ASSIGN Expression ';' {
        printf("REM_ASSIGN\n");

        int idx = lookup_symbol($1);
        CODEGEN("iload %d\n", symbol_table[idx].addr);
        CODEGEN("swap\n");
        CODEGEN("irem\n");
        CODEGEN("istore %d\n", symbol_table[idx].addr);
    }
;

PrintStmt
    : PRINTLN '(' Expression ')' ';' {
        //int idx = lookup_symbol($3);
        if (strcmp($3, "i32") == 0){
            printf("PRINTLN i32\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            //CODEGEN("iload %d\n", symbol_table[idx].addr);
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V\n");
        }   
        else if (strcmp($3, "f32") == 0){
            printf("PRINTLN f32\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            //CODEGEN("fload %d\n", symbol_table[idx].addr);
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V\n");
        } 
        else if (strcmp($3, "bool") == 0){
            printf("PRINTLN bool\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            //CODEGEN("iload %d\n", symbol_table[idx].addr);
            CODEGEN("invokevirtual java/io/PrintStream/println(Z)V\n"); 
        }      
        else if(strcmp($3, "str") == 0){
            printf("PRINTLN str\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            //CODEGEN("aload %d\n", symbol_table[idx].addr);
            CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n"); 
        }           
        else if(strcmp($3, "array") == 0)
            printf("PRINTLN array\n");
    }
    | PRINT '(' Expression ')' ';' {
        if (strcmp($3, "i32") == 0){
            printf("PRINT i32\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            CODEGEN("invokevirtual java/io/PrintStream/println(I)V\n");
        }            
        else if (strcmp($3, "f32") == 0){
            printf("PRINT f32\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            CODEGEN("invokevirtual java/io/PrintStream/println(F)V\n");
        }        
        else if (strcmp($3, "bool") == 0){
            printf("PRINT bool\n");
            CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            CODEGEN("swap\n");
            CODEGEN("invokevirtual java/io/PrintStream/println(Z)V\n"); 
        }     
        else if(strcmp($3, "str"))
            printf("PRINT str\n");
        else if(strcmp($3, "array") == 0)
            printf("PRINTLN array\n");
    }
    | PRINTLN '(' '"' STRING_LIT '"' ')' ';' {
        printf("STRING_LIT \"%s\"\n", $4);
        printf("PRINTLN str\n");

        CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
        CODEGEN("ldc \"%s\"\n", $4);
        CODEGEN("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        
    }
;

ExpressionList
    : Expression
    | ExpressionList ',' Expression
;

Expression
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>1);
        CODEGEN("ldc %d\n", $<i_val>1);
        $$ = "i32";
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>1);
        CODEGEN("ldc %f\n", $<f_val>1);
        $$ = "f32";
    }
    | TRUE {
        printf("bool TRUE\n");
        $$ = "bool";
        CODEGEN("iconst_1\n");
    }
    | FALSE {
        printf("bool FALSE\n");
        $$ = "bool";
        CODEGEN("iconst_0\n");
    }
    | ID {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            printf("error:%d: undefined: %s\n", yylineno + 1, $1);
            $$ = "undefined";
        } else {
            printf("IDENT (name=%s, address=%d)\n", $1, symbol_table[idx].addr);  
            $$ = symbol_table[idx].type;

            if (strcmp(symbol_table[idx].type, "i32") == 0)
                CODEGEN("iload %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "f32") == 0)
                CODEGEN("fload %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "str") == 0 || strcmp(symbol_table[idx].type, "string") == 0)
                CODEGEN("aload %d\n", symbol_table[idx].addr);
            else if (strcmp(symbol_table[idx].type, "bool") == 0)
                CODEGEN("iload %d\n", symbol_table[idx].addr);
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

        if (strcmp($2, "i32") == 0)
            CODEGEN("ineg\n");
        else if (strcmp($2, "f32") == 0)
            CODEGEN("fneg\n");
        
    }
    | '!' Expression {
        printf("NOT\n");
        $$ = "bool";
        CODEGEN("iconst_1\n");
        CODEGEN("ixor\n");
    }
    | Expression AS Expression {
        printf("AS\n");
        $$ = "as";
    }
    | Expression '+' Expression {
        printf("ADD\n");
        if (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) {
            CODEGEN("fadd\n");
            $$ = "f32";
        } else {
            CODEGEN("iadd\n");
            $$ = "i32";
        }
    }
    | Expression '-' Expression {
        printf("SUB\n");
        if (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) {
            CODEGEN("fsub\n");
            $$ = "f32";
        } else {
            CODEGEN("isub\n");
            $$ = "i32";
        }
    }
    | Expression '*' Expression {
        printf("MUL\n");
        if (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) {
            CODEGEN("fmul\n");
            $$ = "f32";
        } else {
            CODEGEN("imul\n");
            $$ = "i32";
        }
    }
    | Expression '/' Expression {
        printf("DIV\n");
        if (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) {
            CODEGEN("fdiv\n");
            $$ = "f32";
        } else {
            CODEGEN("idiv\n");
            $$ = "i32";
        }
    }
    | Expression '%' Expression {
        printf("REM\n");
        CODEGEN("irem\n");
        $$ = "i32";
    }
    | Expression '>' Expression {
        if (strcmp($1, "undefined") == 0) {
            printf("error:%d: invalid operation: GTR (mismatched types %s and %s)\n", yylineno + 1, $1, $3);
        }

        printf("GTR\n");
        $$ = "bool";

        if (strcmp($1, "f32") == 0 || strcmp($3, "f32") == 0) {
            CODEGEN("fcmpl\n");                             // f1, f2 → (int)
            CODEGEN("iconst_1\n");
            CODEGEN("if_icmpeq L_true_%d\n", label_count);
        } else {
            CODEGEN("if_icmpgt L_true_%d\n", label_count);  // 比較 int 兩值
        }
        CODEGEN("iconst_0\n");
        CODEGEN("goto L_end_%d\n", label_count);
        CODEGEN("L_true_%d:\n", label_count);
        CODEGEN("iconst_1\n");
        CODEGEN("L_end_%d:\n", label_count);

        label_count++;
    }
    | Expression '<' Expression {
        printf("LSS\n");
        $$ = "bool";

        int label = label_count++;
        CODEGEN("isub\n");                          
        CODEGEN("iflt L_cmp_%d\n", label);         
        CODEGEN("iconst_0\n");                          
        CODEGEN("goto L_cmp_end_%d\n", label);     
        CODEGEN("L_cmp_%d:\n", label);            
        CODEGEN("iconst_1\n");                          
        CODEGEN("L_cmp_end_%d:\n", label);              
        CODEGEN("ifeq L_if_false_%d\n", label);    
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

        int label = label_count++;
        CODEGEN("isub\n");
        CODEGEN("ifeq L_cmp_%d\n", label);    
        CODEGEN("iconst_0\n");                     
        CODEGEN("goto L_cmp_end_%d\n", label);
        CODEGEN("L_cmp_%d:\n", label);              
        CODEGEN("iconst_1\n");
        CODEGEN("L_cmp_end_%d:\n", label);
        CODEGEN("ifeq L_if_false_%d\n", label);

    }
    | Expression NEQ Expression {
        printf("NEQ\n");
        $$ = "neq";

        int label = label_count++;

        CODEGEN("isub\n");                          
        CODEGEN("ifne L_cmp_%d\n", label);         
        CODEGEN("iconst_0\n");                          
        CODEGEN("goto L_cmp_end_%d\n", label);     
        CODEGEN("L_cmp_%d:\n", label);            
        CODEGEN("iconst_1\n");                          
        CODEGEN("L_cmp_end_%d:\n", label);              
        CODEGEN("ifeq L_if_false_%d\n", label);
    }
    | Expression LAND Expression {
        printf("LAND\n");
        $$ = "bool";
        CODEGEN("iand\n");
    }
    | Expression LOR Expression {
        printf("LOR\n");
        $$ = "bool";
        CODEGEN("ior\n");
    }
    | '(' Expression ')' {
        $$ = $2;
    }
    | STRING_LIT {
        printf("STRING_LIT \"%s\"\n", $<s_val>1);
        $$ = "str";
        CODEGEN("ldc \"%s\"\n", $<s_val>1);
    }
    | '"' '"'{
        printf("STRING_LIT \"\"\n");
        $$ = "str"; 
        CODEGEN("ldc \"\"\n");
    }
    | Expression AS Type {
        if (strcmp($1, "f32") == 0 && strcmp($3, "i32") == 0) {
            printf("f2i\n");
            CODEGEN("f2i\n");
            $$ = "i32";
        } else if (strcmp($1, "i32") == 0 && strcmp($3, "f32") == 0) {
            printf("i2f\n");
            CODEGEN("i2f\n");
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
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");
    
    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();
    dump_symbol();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
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
                   symbol_table[i].mut,                        // Mut 預設為 0
                   symbol_table[i].type,
                   symbol_table[i].addr,                        // Addr 就用 index 表示
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