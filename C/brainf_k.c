#include <stdio.h>
#define MEMSIZE 32768
#define SLENGTH 128000
/*As of now everthing except loops will work, I think...
* ASCII REFERENCE: '%'=37 | ','=44 | '.'=46 | '>'=62 | '<'=60 | '+'=43 | '-'=45 | '['=91 | ']'=93 
* A loop parser needs to be made :|
* No support for comments yet. '%'
* This code might just be too memory intensive.
*/
int main() {
    char mc[MEMSIZE]={0};    //Memory Cells allocated, and initialized.
//    int *in=fopen(stdin,"r");    
    int ip=0,pc=0;    //ip-> counts the memory location, pc-> counts the program's progress
    while(!foef(stdin) && pc<SLENGTH) {     //BF limits code length to 128000B it seems.
        int c=fgetc(stdin);
        ++pc;   //Parse next character from the input stream.
parse:  (c==44)?*mc=(char)c:(
            (c==46)?printf("%c",mc[ip]):(
                (c==62)?++ip:(  //move instruction pointer appropriately
                    (c==60)?--ip:(
                        (c==43)?++mc[ip]:(
                            (c==45)?--mc[ip]:(
                                (c==91 || c==93)?
                                    if(c==91 && mc[ip]!=0) {
                                        goto parse;
                                    }
                                    else if(c==91 && mc[ip]==0){
                                        ip=;//Wherever the corresponding endLoop occurs, need to run a stage for this.
                                    }
                                    else if(c==93) {
                                        ip=;//Send it back to where the corresponding startLoop occurs.
                                    }
                                    else{/*Is there anything else that can be done?*/}:/*ignore everthing else.*/;
                        )
                    )
                )
            )
        );
    }
    return 0;
}
