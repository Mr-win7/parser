#include<regex.h>


int token;
int token_val;
char * src;
char * old_src;
int poolsize;
int line;

struct token_type * token_type_list;

struct token_type
{
    enum
    {
	    Num = 128, Eq, Ne, Ge, Gt, Le, Lt, Add, Sub, Mul, Div, Inc, Dec, Assign, Int, If, Else, While, Id
    } type;
    char * regex;
};

struct identifier
{
    int token;
    int hash;
    char * name;
    int class;
    int type;
    int value;
    int Bclass;
    int Btype;
    int Bvalue;
}


void init_lex()
{
    token_type_list = 
    {
        {Num, "[0-9]+"},
        {Eq, "="},
        {Ne, "!="},
        {Ge, ">="},
        {Gt, ">"},
        {Le, "<="},
        {Lt, "<"},
        {Add, "+"},
        {Sub, "-"},
        {Mul, "*"},
        {Div, "/"},
        {Inc, "++"},
        {Dec, "--"},
        {Assign, "="},
        {Int, ""},
        {If, ""},
        {Else, ""},
        {While, ""},
        {Id, "[a-zA-Z_][0-9a-zA-Z_]*"}
    }
}

struct token_type next()
{
    regex_t regex;
    char[128] error_buffer;
    struct token_type token_type_pointer = token_type_list;

    for(int i = 0; i < 19; token_type_pointer++)
    {
        int flag = regcomp(&regex, token_type_pointer->regex, REG_EXTENDED);
        if(flag != 0)
        {
            regerror(flag, &regex, error_buffer, sizeof(error_buffer));
        }
        else
        {

        }
    }
}

    

