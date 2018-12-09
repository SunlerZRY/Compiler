#include<iostream>
#include<stdio.h>
using namespace std;
letter	= [a-zA-Z_]
digit	= [0-9]
WHITE_SPACE = (" "|\t|\n|\r|\f|\v)+

ID     = letter+ (letter|dight)*
CONST_ID    = digit+ ("." digit*)?
POWER       = "**"
COMMENT     = "//"|"--"
SEMICO      = ";"
L_BRACKET   = "("
R_BRACKET   = ")"
COMMA       = ","
PLUS        = "+"
MINUS       = "-"
MUL         = "*"
DIV         = "/"

struct t_state_trans
{
   int src; // 源状态
   char tag;// 边上标记
   int to;  // 目标状态
}
myTrans[]={ //全部转移
   {0, ‘*’, 4},
   {0, ‘-’, 7},
   {2, ‘.’, 3},

}; // 基于此,实现
// 终态的数据结构
struct  t_final_state {
 int  state;  // 终态
 Token_Type kind; // 记号类别
};
// 所有终态
struct  t_final_state
myFinalStates[] =
{
   {1, ID},
   {2, CONST_ID},
   {3, CONST_ID},

};

bool InitScanner(const char *FileName){

        if(FILENAME_MAX!=null)
           return true;
        else
            return false;


}
//查询 & 返回 DFA 的初态
int get_start_state(){
    return 0;
 }
// 执行状态转移，返回下一状态。若无转移则返回 -1.
int move(int state_src,char ch){
    for(int i=0;i<sizeof(myTrans);i++){
        if(state_src==myTrans[i][0]&&ch==myTrans[i][1]){
            return myTrans[i][2];
        }
    }
    return -1;
}

//终态判断。若为终态，则返回相应的记号类别，否则返回 ERRTOKEN
enum Token_Type state_is_final(int state){
     for(int i=0;i<sizeof(myFinalStates);i++){
        if(state_src==myFinalStates[i][0]){
            return myFinalStates[i][1];
        }
    }


};
//追加文本
void AppendTokenTxt(struct Token*pToken,int current_char){
   //pToken->lexeme+=current_char;

}


struct Token GetToken(){
    int first_char;
    int last_state=-1;
    struct Token theToken;//被识别到的记号对象
    int to_be_continue;

    do
    {
        //预处理，跳过空白字符
        first_char=pre_process(&theToken)；
        if(first_char==-1)
        {
            theToken.type=NONTOKEN;
            return theToken;
        }
        //边扫描输入，边转移状态
        last_state=scan_move(&theToken,first_char);
        //后处理，根据终态所标记的记号种类信息，进行处理
        to_be_continue=post_process(&theToken,last_state);

    }while(to_be_continue!=0);

    return theToken;
}
//从源文件中读取一个字符
char GetChar(void){
    //从源文件中读到一个字符，并返回它
    //遇到文件结束，则返回-1
    int next_char=getc(in_file);
    if(EOF==next_char)
        return -1;
    else
        //统一返回大写
        return topper(next_char);
}
void BackChar(char c){
      if(c==EOF||}c!='\n')
                return;
      else
      ungetc(c,in_file);
}
int pre_process(struct Token *pToken){
     int current_char;//当前读到字符
     memset(pToken,0,sizeof(struct Token));//记号内存清零
     for(;;){
        current_char=GetChar();
        if(current_char==-1){
            return -1;
        }
        if(!isspace(current_char))
            break;
     }
   // 此时，current_char 就是记号的第一个字符
    return current_char;
}
//识别一个记号
int scan_move(struct Token*pToken,int first_char)
{

    int current_state,next_state;//当前状态，下一状态
    int current_char;
    current_state=get_start_state();
    for(;;){
        next_state=move(current_state,current_char);
        if(next_state<0){//没有转移了
            BackChar(current_char);//退回当前字符
            break;
        }
        AppendTokenTxt(pToken,current_char);//追加记号文本
        current_state=next_state;
        current_char=GetChar();
        if(current_char==-1){//文件结束
            break;
        }
        return current_state;
    }

}
/*根据识别出的字符串在符号表中查找
若找到返回该记号
否则返回错误记号
 */
struct Token JudgeKeyToken(const char*c_str){
            int count;
            struct Token err_token;
            int n=sizeof(TokenTab)/sizeof(TokenTab[0]);
            for(count=0;count<n;++count){
                if(strcmp(TokenTab[count]).lexeme,c_str)==0)
                    return  TokenTab[count];
            }
            memset(&err_token,0,sizeof(err_token));
            err_token.type=ERRTOKEN;
            return err_token;


};
终态判断及收尾
int post_process(struct Token *pToken,int last_state){
         int to_be_continue=0;
         enum Token_Type tk;终态对应的记号
         pToken->type=tk=state_is_final;
         switch(tk){
              case ID://查找符号表，进一步计算记号信息
                  *pToken=JudgeKeyToken(pToken->lexeme);
                  break;
              case CONST_ID:
                pToken->value=atof(pToken->lexeme);//转为数值
              case COMMENT:
                {
                    int c;
                    while(1){
                        c=GetChar();//行注释，忽略到行尾
                        if(c=='\n'||c==-1)
                            break;
                    }

                }
                to_be_continue=1;
                break;
         }
         return to_be_continue;
}









