#include "Object.h"



Object::Object()
{
}

int Object::createInstance(lua_State* L)
{
    // number of arguments
    lua_gettop(L);

    // First argument is now a table that represent the class to instantiate
    //luaL_checktype(L, 1, LUA_TTABLE);

    // Create table to represent instance
    lua_newtable(L);

    // Set first argument of new to metatable of instance
    lua_pushvalue(L,1);
    lua_setmetatable(L, -2);

    // Do function lookups in metatable
    lua_pushvalue(L,1);
    lua_setfield(L, 1, "__index");

    Object** o = (Object**)lua_newuserdata(L, sizeof(Object*));
    *o = new Object();

    // Get metatable store in the registry
    luaL_getmetatable(L, "Object");

    // Set user data for Object to use this metatable
    lua_setmetatable(L, -2);

    // Set field '__self' of instance table to the object user data
    //lua_setfield(L, -2, "__self");

    return 1;
}

int Object::destroyInstance(lua_State* L)
{
    return 0;
}

int Object::y(lua_State* L)
{
    Object* o = *(Object**)luaL_checkudata(L, 0, "Object");
    lua_pushnumber(L, o->_y);
    return 1;
}

int Object::think(lua_State* L)
{
    return 1;
}

void Object::export_to_lua(lua_State* L)
{
    static const luaL_Reg lua_meta[] = {
        {"__gc", &destroyInstance},
        {NULL, NULL}
    };

    static const luaL_Reg lua_functions[] = {
        {"new", &createInstance},
        {"think", &think},
        {"y", &y},
        {NULL, NULL}
    };

    luaL_register(L, "Object", lua_functions);
    luaL_newmetatable(L, "Object");
    luaL_register(L, 0, lua_meta);
    lua_pushliteral(L, "__index");
    lua_pushvalue(L, -3);
    lua_rawset(L, -3);
    lua_pushliteral(L, "__metatable");
    lua_pushvalue(L, -3);
    lua_rawset(L, -3);
    lua_pop(L, 1);
}
