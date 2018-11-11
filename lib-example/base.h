#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <ltable.h>
#include <lstring.h>
#include <lobject.h>

void dump_v(TValue *v);
void indent_p(const char * format, ...);


#endif
