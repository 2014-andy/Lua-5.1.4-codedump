#include "../src/lua.h"  
#include "../src/lauxlib.h"  
#include "../src/lualib.h"  
#include "common.h"


int get_tab(lua_State *L)
{
    /* create table. */
    lua_newtable(L);

    /* push (key, value). */
    int i;
    char value[10] = {0};
    for(i=0; i<5; ++i)
    {
        sprintf(value, "value%d", i+1);
        printf("c code value%d\n", i+1);
        lua_pushnumber(L, i+1);    //key
        lua_pushstring(L, value);  //value
        lua_settable(L, -3);       //push key,value
    }

    /* deal return. */
    return 1;
}

void* load_lua1(void* v)
{
    (void)v;
        /* create a state and load standard library. */
    lua_State* L = luaL_newstate();

    /* opens all standard Lua libraries into the given state. */
    luaL_openlibs(L);

    /* register function be called by lua. */
    lua_register(L, "gettab", get_tab);

    /* load and exec the specified lua file. */
    int error = luaL_dofile(L, "lua_test.lua");
    if(error) {
        perror("luaL_dofile error");
        return NULL;
    }

    /* get the domain function from lua file. */ 
    lua_getglobal(L,"domain");
    lua_pushnumber(L, 1);
    lua_pushnumber(L, 22);
    LOGI("call lua")

    /* exec the domain function. */
    error = lua_pcall(L, 2, 0, 0);
    if (error) {
        fprintf(stderr,"%s\n",lua_tostring(L,-1));
        lua_pop(L,1);
    }
    lua_close(L);
    
    return NULL;
}

void* load_lua2(void* v)
{
    (void)v;
        /* create a state and load standard library. */
    lua_State* L = luaL_newstate();

    /* opens all standard Lua libraries into the given state. */
    luaL_openlibs(L);

    /* register function be called by lua. */
    lua_register(L, "gettab", get_tab);

    /* load and exec the specified lua file. */
    int error = luaL_dofile(L, "lua_test.lua");
    if(error) {
        perror("luaL_dofile error");
        return NULL;
    }

    /* get the domain function from lua file. */ 
    lua_getglobal(L,"domain2");
    lua_pushnumber(L, 1);
    lua_pushnumber(L, 22);

    /* exec the domain function. */
    error = lua_pcall(L, 2, 0, 0);
    if (error) {
        fprintf(stderr,"%s\n",lua_tostring(L,-1));
        lua_pop(L,1);
    }
    
    /* get the domain function from lua file. */ 
    lua_getglobal(L,"domain");
    lua_pushnumber(L, 1);
    lua_pushnumber(L, 22);

    /* exec the domain function. */
    error = lua_pcall(L, 2, 0, 0);
    if (error) {
        fprintf(stderr,"%s\n",lua_tostring(L,-1));
        lua_pop(L,1);
    }
    lua_close(L);
    
    return NULL;
}


int main()
{
    load_lua1(NULL);
//    test_nodetach();
//    test_detach();
    return 0;
}
