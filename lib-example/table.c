#include "base.h"

void key_but_novalue(lua_State *L);
void try_find(lua_State *L, Table *t, TValue *k);
void step_by_step(lua_State *L);

void dump_table(Table *t);
void dump_node(Node *n, int i);

int main(){
    lua_State *L = luaL_newstate();

    key_but_novalue(L);

    step_by_step(L);

    return 0;
}

void key_but_novalue(lua_State *L){
    printf("[%s]\n", __FUNCTION__);
    // set zero node size, will rehash in the future
    Table *t = luaH_new (L, 0, 0);

    TValue key1;
    setsvalue(L, &key1, luaS_newlstr(L, "name", 4));

    TValue key2;
    setsvalue(L, &key2, luaS_newlstr(L, "age", 3));

    TValue key3;
    setsvalue(L, &key3, luaS_newlstr(L, "sex", 3));

    /*
     * store key to the table node, and return the i_val
     */


    luaH_set(L, t, &key1);
    luaH_set(L, t, &key2);

    dump_table(t);
    exit(0);

    try_find(L, t, &key1);
    try_find(L, t, &key2);
    try_find(L, t, &key3);
}

void dump_table(Table *t){
    Node *node;
    int i;

    printf("%d\n", t->lsizenode);

    int size = twoto(t->lsizenode);

    for(i = 0; i < size; i++){
        node = &t->node[i];
        dump_node(node, i);
    }
}

void dump_node(Node *n, int i){
    while(n){
        switch(n->i_key.nk.tt){
            case LUA_TSTRING:
                printf("index:%d k-t:%s k-v:%s\n", i, out_type[LUA_TSTRING], svalue(&n->i_key.tvk));
                break;
            case LUA_TNIL:
                printf("index:%d k-t:%s k-v:%s\n", i, out_type[LUA_TNIL], "nil");
                break;
            default:
                printf("pending...\n");
        }

        n = n->i_key.nk.next;
    }
}

void try_find(lua_State *L, Table *t, TValue *k){

    const TValue * v = luaH_get(t, k);

    printf("key:%s v-type:%s\n", svalue(k), out_type[v->tt]);
}

void step_by_step(lua_State *L){

}
