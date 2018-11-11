#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <ltable.h>
#include <lstring.h>
#include <lobject.h>

const char *out_type[] = {
    "nil",
    "boolean",
    "lightuserdata",
    "number",
    "string",
    "table",
    "function",
    "userdata",
    "thread",
    NULL
};
