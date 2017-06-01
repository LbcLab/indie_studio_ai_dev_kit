//!
//! \file main.cpp
//! \!brief This is the main where you can test various things
//! \author Charles Paulet
//! \version 1.0
//!

#include "LuaManager.hh"
#include "IA.hh"

//!
//! \brief Print program usage
//!
static int usage(std::string const binName)
{
  std::cerr << binName+": <lua_script>" << std::endl;
  return 1;
}

//!
//! \brief Entry point
//! \param ac
//!   Number of arguments given to the program
//! \param av
//!   The actual parameters given to the program
//!
int main(int const ac, char const * const * const av)
{
  IA *ia;
  if (ac != 2)
    return usage(std::string(av[0]));
  try {
    ia = new IA(av[1]);
  }
  catch (const char *e)
  {
    std::cerr << "Cannot create IA : " << e << std::endl;
    return 1;
  }
  ia->play();
  delete ia;
  return 0;
}

