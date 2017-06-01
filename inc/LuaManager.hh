//!
//! \file LuaManager.hh
//! \!brief This define tools related to Lua scripts
//! \author Charles Paulet
//! \version 1.0
//!

#pragma once

/*
# ifdef _cplusplus
#  include <lua5.2/lua.hpp>
# else
#  include <lua5.2/lua.h>
#  include <lua5.2/lualib.h>
#  include <lua5.2/lauxlib.h>
#endif
*/
extern "C"
{
#include <lua5.2/lualib.h>
#include <lua5.2/lauxlib.h>
#include <lua5.2/lua.h>
}

# include <iostream>

//!
//! \def ERR_LUA_LOADSCRIPT
//!   Error message triggered when lua script cannot be loaded
//!
# define ERR_LUA_LOADSCRIPT ("Cannot load sript")

//!
//! \class LuaManager
//! \brief represents the Lua scripts handler/loader
//!
class LuaManager
{
  public:
    //!
    //! \brief Lua scripts manager constructor
    //!
    LuaManager();
    //!
    //! \brief Lua scripts manager destructor
    //!
    ~LuaManager();
    //!
    //! \brief Open the Lua managing context
    //! \param path
    //!   Actually the path of the lua script
    //!
    bool loadScript(std::string const &path);
    //!
    //! \brief Accessor on the path of the lua script
    //!
    std::string const getPath(void) const;
    //!
    //! \brief Call loop() function
    //!
    bool execute(void) const;
    //!
    //! \brief Accessor on the ai name defined in the lua script
    //!
    std::string getName(void) const;

  private:
    //!
    //! \brief print lua error
    //!
    void print_err(void) const;
    //!
    //! \brief register the functions that the lua script can access
    //!
    void registerSymbols(void) const;
    //!
    //! \brief lua context
    //!
    lua_State * const state;
    //!
    //! \brief lua script path
    //!
    std::string path;
};
