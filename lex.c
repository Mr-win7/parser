#include<regex.h>
#define NMATCH 1
#define TYPE_NUM 19


int token;
int token_val;
char * src;
char * old_src;
int poolsize;
int line;

struct token_type * token_type_list;

struct token_buffer
{
	struct token_type * class;
	char * result;
};

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
};


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
    };
}

struct token_type next(char * source)
{
	char * child_ptr = "\0";
    regex_t regex;
    char[128] error_buffer;
	regmatch_t[NMATCH] match_ptr;
	struct token_buffer * token_buffer_list = (struct token_buffer *) malloc(TYPE_NUM * sizeof(struct token_buffer));

    for(int i = 0; i < TYPE_NUM; i ++)
    {
        int flag = regcomp(&regex, token_type_list[0].regex, REG_EXTENDED);
        if(flag != 0)
        {
            regerror(flag, &regex, error_buffer, sizeof(error_buffer));
        }
        else
        {
			if(regexec(&regex, source, NMATCH, match_ptr,REG_NOTEOL) ==0 && match_ptr[0].rm_so == 0)
			{
				child_ptr = (char *) malloc((match_ptr[0].rm_eo - match_ptr[0].rm_so + 2) * sizeof(char));
				for(int csi = 0; csi < (match_ptr[0].rm_eo - match_ptr[0].rm_so + 2); csi ++)
				{
					child_ptr[csi] = source[match_ptr[0].rm_so + csi];
				}

			}
        }
		token_buffer_list[i].result = child_ptr;
		token_buffer_list[i].class = 
		regfree(&regex);
    }
}
