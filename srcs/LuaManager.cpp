//!
//! \file LuaManager.cpp
//! \!brief This handle the member functions of the LuaManager class
//! \author Charles Paulet
//! \version 1.0
//!

#include <functional>
#include <sstream>
#include "IA.hh"
#include "LuaManager.hh"

LuaManager::LuaManager() : state(luaL_newstate())
{
  this->registerSymbols();
  luaL_openlibs(this->state);
}

void LuaManager::registerSymbols(void) const
{
  lua_register(this->state, "ping", IA::ping);
  lua_register(this->state, "getLife", IA::getLife);
}

LuaManager::~LuaManager()
{
  lua_close(this->state);
}

void LuaManager::print_err(void) const
{
  char const *msg = lua_tostring(this->state, -1);
  std::cerr << std::string(msg) << std::endl;
  lua_pop(this->state, 1);
}

bool LuaManager::loadScript(std::string const &path)
{
  int const res = luaL_dofile(this->state, path.c_str());
  if (res != LUA_OK)
  {
    this->print_err();
    return false;
  }
  this->path = std::move(path);
  return true;
}

std::string const LuaManager::getPath(void) const
{
  return this->path;
}

bool LuaManager::execute(void) const
{
  lua_getglobal(this->state, "loop");
  int const res = lua_pcall(this->state, 0, LUA_MULTRET, 0);
  if (res != LUA_OK)
  {
    this->print_err();
    return false;
  }
  return true;
}

std::string LuaManager::getName(void) const
{
  lua_getglobal(this->state, "name");
  if (!lua_isstring(this->state, -1))
  {
    std::cerr << "No name given" << std::endl;
    return "";
  }
  else
    return std::string(((char *)lua_tostring(this->state, -1)));
}
