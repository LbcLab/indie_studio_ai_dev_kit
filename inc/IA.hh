//!
//! \file IA.hh
//! \!brief This is a mock of the final Ninja Gauntlet AI definition
//! \author Charles Paulet
//! \version 1.0
//!

#pragma once

# include <iostream>
# include <memory>
# include "LuaManager.hh"

//!
//! \def AI_CREATED
//!   Message that is printed when AI object is created
//!
# define AI_CREATED ("AI created.")
//!
//! \def AI_DESTROYED
//!   Message that is printed when AI object is destroyed
//!
# define AI_DESTROYED ("AI destroyed.")
//!
//! \def AI_CALL_GETLIFE
//!   Message that is printed when AI script call getLife
//!
# define AI_CALL_GETLIFE ("Call : getlife()")
//!
//! \def AI_DEFAULT_NAME
//!   Default AI name
//!
# define AI_DEFAULT_NAME ("CPU1")
//!
//! \def AI_DEFAULT_LIFE
//!   Default AI health points
//!
# define AI_DEFAULT_LIFE (100)

//!
//! \class IA
//! \brief represents the AI that is implemented in Ninja Gauntlet
//!
class IA
{
  public:
    //!
    //! \brief Constructs the AI
    //! \param path
    //!   The path of the related lua script
    //!
    IA(std::string const path);
    //!
    //! \brief Destructs the AI
    //!
    ~IA();
    //!
    //! \brief Calculates the net action of the AI
    //!   This calls the loop() function defined in the lua script
    //!
    void play(void) const;
    //!
    //! \brief Setup AI
    //!   Find basic AI information such as its name
    //!
    void setup(void);

    //!
    //! \brief Accessor on AI life
    //!
    static int getLife(lua_State *state);
    //!
    //! \brief debug function
    //!  It will list parameters you passed through it
    //!
    static int ping(lua_State *state);
  private:
    //!
    //! \brief AI contains its lua manager
    //!
    std::unique_ptr<LuaManager> lm;
    //!
    //! \brief AI life
    //!
    std::size_t life;
    //!
    //! \brief AI name
    //!
    std::string name;
};
