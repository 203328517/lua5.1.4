#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <ltable.h>

void main(){
    lua_State *L = luaL_newstate();
    
    Table *t = luaH_new (L, 0, 0);
    
    TString *s = luaS_newlstr(L, "dailei", 6);
}
