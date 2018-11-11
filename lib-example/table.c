#include "base.h"

void t_integer(lua_State *L, int sizearray, int sizenode);
void t_string(lua_State *L, int sizearray, int sizenode);

void t_find(lua_State *L, Table *t, TValue *k);

void dump_nodes(Table *t);
void dump_node(Node *n, Table *t);

void dump_arrays(Table *t);
extern int indent;

int main(){
    lua_State *L = luaL_newstate();

    t_string(L, 0, 0);
    t_integer(L, 0, 0);
    t_integer(L, 0, 2);  //node size not enough, will rehash
    t_integer(L, 0, 3);  //node size enough, array data will be stored to node until next rehash
    return 0;
}

void t_string(lua_State *L, int sizearray, int sizenode){
    indent_p("[%s %d %d]\n", __FUNCTION__, sizearray, sizenode);
    indent += 2;

    Table *t = luaH_new (L, sizearray, sizenode);

    TValue k1, k2, k3;
    setsvalue(L, &k1, luaS_newlstr(L, "name", 4));
    setsvalue(L, &k2, luaS_newlstr(L, "age", 3));
    setsvalue(L, &k3, luaS_newlstr(L, "sex", 3));

    TValue *v1,*v2,*v3;

    v1 = luaH_set(L, t, &k1);
    setsvalue(L, v1, luaS_newlstr(L, "Lyli", 4));

    v2 = luaH_set(L, t, &k2);
    setsvalue(L, v2, luaS_newlstr(L, "22", 2));

    v3 = luaH_set(L, t, &k3);
    setsvalue(L, v3, luaS_newlstr(L, "female", 6));


    dump_nodes(t);
    dump_arrays(t);

    indent -= 2;
    puts("");
}

void t_integer(lua_State *L, int sizearray, int sizenode){
    indent_p("[%s %d %d]\n", __FUNCTION__, sizearray, sizenode);
    indent += 2;

    Table *t = luaH_new (L, sizearray, sizenode);

    TValue k1, k2, k3;

    k1.tt = LUA_TNUMBER;
    k1.value.n = 1;

    k2.tt = LUA_TNUMBER;
    k2.value.n = 2;

    k3.tt = LUA_TNUMBER;
    k3.value.n = 4;

    TValue *v1,*v2,*v3;

    v1 = luaH_set(L, t, &k1);
    setsvalue(L, v1, luaS_newlstr(L, "one", 3));

    v2 = luaH_set(L, t, &k2);
    setsvalue(L, v2, luaS_newlstr(L, "two", 3));

    v3 = luaH_set(L, t, &k3);
    setsvalue(L, v3, luaS_newlstr(L, "four", 4));

    dump_nodes(t);
    dump_arrays(t);

    indent -= 2;
    puts("");
}

void dump_arrays(Table *t){
    indent_p("[%s]\n", __FUNCTION__);
    indent += 2;
    int i;
    TValue *v;
    for(i = 0; i < t->sizearray; i++){
        v = &t->array[i];

        indent_p("t[%d] = ", i+1);
        dump_v(v);
        puts("");
    }

    indent -= 2;
}

void dump_nodes(Table *t){
    indent_p("[%s]\n", __FUNCTION__);
    indent += 2;
    Node *node;
    int i;

    int size = twoto(t->lsizenode);

    for(i = 0; i < size; i++){
        node = &t->node[i];
        dump_node(node, t);
    }


    indent -= 2;
    puts("");
}

void dump_node(Node *n, Table *t){
    unsigned int hash, slot_i;

    switch(n->i_key.nk.tt){
        case LUA_TSTRING:
            hash = n->i_key.tvk.value.gc->ts.tsv.hash;
            //slot_i = lmod(hash, sizenode(t));
            //printf("%d ", slot_i);

            indent_p("t['%s'] = ", svalue(&n->i_key.tvk));
            dump_v(&n->i_val);
            puts("");
            break;
        case LUA_TNUMBER:
            indent_p("t[%d] = ", (int)n->i_key.tvk.value.n);
            dump_v(&n->i_val);
            puts("");
            break;
        case LUA_TNIL:
            indent_p("nil\n");
            break;
        default:
            indent_p("error...\n");
    }

}

void t_find(lua_State *L, Table *t, TValue *k){
    const TValue * v = luaH_get(t, k);

    dump_v(v);
    puts("");

}
