#include "base.h"

int indent = 0;


void dump_v(TValue *v){
    switch(v->tt){
        case LUA_TSTRING:
            printf("'%s'", svalue(v));
            break;
        case LUA_TNUMBER:
            printf("%d", nvalue(v));
            break;
        default:
            printf("nil");
            break;
    }
}

void indent_p(const char * format, ...){
    int i = 0;
    char buf[4069];
    char *cur = buf;
    va_list list;

    while(i < indent){
        buf[i++] = ' ';
        cur++;
    }

    va_start(list, format);
    vsnprintf(cur, 4069, format, list);
    va_end(list);

    printf("%s", buf);
}
