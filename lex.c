int token;
int token_val;
char * src;
char * old_src;
int poolsize;
int line;

enum
{
	Num = 128, Eq, Ne, Ge, Gt, Le, Lt, Add, Sub, Mul, Div, Inc, Dec, Assign, Int
}
