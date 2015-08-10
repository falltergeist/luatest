#ifndef OBJECT_H
#define OBJECT_H

// C++ standard includes

// luatest includes

// Third party includes
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

class Object
{

public:
    Object();

    static int createInstance(lua_State* L);
    static int destroyInstance(lua_State* L);

    static int y(lua_State* L);

    static int think(lua_State* L);

    static void export_to_lua(lua_State* L);

private:
    int _x = 11;
    int _y = 42;

};

#endif // OBJECT_H
