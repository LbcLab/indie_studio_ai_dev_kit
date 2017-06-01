//!
//! \file IA.cpp
//! \!brief This handle the member functions of the IA class
//! \author Charles Paulet
//! \version 1.0
//!

#include "IA.hh"

//!
//! \brief that is initialized in the IA constructor
//! \relates IA
//!
IA *that;

IA::IA(std::string const path)
{
  that = this;
  this->lm = std::make_unique<LuaManager>();
  if (this->lm->loadScript(path) == false)
    throw ERR_LUA_LOADSCRIPT;
  this->setup();
#ifdef AI_DEV_KIT
  std::cout << AI_CREATED <<std::endl;
#endif
}

IA::~IA()
{
#ifdef AI_DEV_KIT
  std::cout << AI_DESTROYED << std::endl;
#endif
}

void IA::setup(void)
{
  std::string name;

  this->life = AI_DEFAULT_LIFE;
  this->name = AI_DEFAULT_NAME;

  if ((name = this->lm->getName()).empty() == false)
    this->name = std::move(name);
#ifdef AI_DEV_KIT
  std::cout << "AI name : " + this->name << std::endl;
#endif
}

void IA::play(void) const
{
  this->lm->execute();
}

extern "C"
{
int IA::getLife(lua_State *state)
{
#ifdef AI_DEV_KIT
  std::cout << AI_CALL_GETLIFE << std::endl;
#endif
  lua_pushnumber(state, that->life);
  return 1;
}

int IA::ping(lua_State *state)
{
  int const args = lua_gettop(state);
  printf("ping() was called with %d arguments:\n", args);
  for (int n(1) ; n <= args ; ++n)
    printf("\targ [%d]:\t[%s]\n", n, lua_tostring(state, n));
  lua_pushnumber(state, 42);
  return 1;
}
}
