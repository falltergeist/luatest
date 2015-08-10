// Standard C++ includes
#include <stdio.h>

// luatest includes
#include "src/Object.h"

// Third party includes
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

int main(int argc, char* argv[])
{    
    lua_State* L = lua_open();
    luaL_openlibs(L);

    Object::export_to_lua(L);


    int error = luaL_loadfile(L, "scripts/main.lua");
    if (error)
    {
        fprintf(stderr, "%s", lua_tostring(L, -1));
        return 1;
    }


    error = lua_pcall(L, 0, 0, 0);
    if (error)
    {
        fprintf(stderr, "%s", lua_tostring(L, -1));
        return 1;
    }

    lua_close(L);
    return 0;
}
