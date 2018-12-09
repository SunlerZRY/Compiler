struct Token
{

    enum Token_Type  type;	// 类别，见下页
	char * lexeme; // 属性，原始输入的字符串，亦可为数组
	double value;	  // 属性，若记号是常数则存常数的值
	double (* FuncPtr)(double);
			  // 属性，若记号是函数则存函数地址

};
enum Token_Type
{
    letter	= [a-zA-Z_],
    digit	= [0-9] ,

    ID,  COMMENT,   // 参见正规式设计
    ORIGIN, SCALE, ROT, IS,	  // 保留字（一字一码）
	TO, STEP, DRAW,FOR, FROM, // 保留字
    T,				  // 参数
    // SEMICO, L_BRACKET, R_BRACKET, COMMA,// 分隔符
    // PLUS, MINUS, MUL, DIV, POWER,		// 运算符
     FUNC,				  // 函数（调用）
     CONST_ID,			  // 常数
     NONTOKEN,			  //空记号（源程序结束）
     ERRTOKEN			  // 出错记号（非法输入）

     COMMENT   	= "//"|"--",
     WHITE_SPACE 	= (" "|\t|\n|\r|\f|\v)+,
     SEMICO    	= ";",
     L_BRACKET 	= "(",
     R_BRACKET 	= ")",
     COMMA     	= ",",
     PLUS      	= "+",
     MINUS     	= "-",
     MUL      	= "*",
     DIV       	= "/",
     POWER     	= "**",
     CONST_ID    	= digit+("." digit*)?,
     ID        	= letter+ (letter|digit)*


};
/*检查绘图语言的原文件是否存在，存在，则打开文件，初始化LineNo的值为1,否则是0*/
extern bool InitScanner(const char *FileName);

/* 关闭源程序文件*/
extern void CloseScanner(void);

/* 每调用一次次函数，就获得一个记号*/
extern Token GetToken(void);

/*从源程序中读取一个字符 */
static char GetChar();

/* 回退多读进的字符*/
static void BackChar(char);

/*将已识别的字符放到TokenBuffer中*/
static void AddCharTokenString(char);

/*清空TokenBUffer*/
static void EmptyTokenString(void);

/*根据识别出的字符串在符号表中查找 */
static Token JudgeKeyToken(const char*IDString);


