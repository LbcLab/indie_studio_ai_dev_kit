# Ninja Gauntlet artificial intelligence API

In Ninja Gautlet, you are able to create your own artificial intelligence using Lua scripting.
This guide will show you the different features you can use in your script.

Actually, the lua script that is loaded in the game is located in : `configFiles/ai/ai.lua` which is the following :

```
speed="0.42"

function loop()
  local nearest = getNearestPlayer();
  io.write(string.format("nearest : %s\n",  nearest));
  print(getDistanceFromPlayer(nearest));
  followPlayer(nearest);
end

function my_lua_func(arg)
  print("im my_lua_func")
  io.write(string.format("my_lua_func arg: %s\n", tostring(arg)))
end
```

the function loop is the only one that is called.
You can define the speed of the ai with the global `speed`.

### ping(…)
This function takes an arbitrary number of parameters and display them. It returns 42.

### getLife()
This is an accessor on the AI remaining life points.

### getNearestAlly()
This returns the id of the nearest ninja ally from the AI.

### getNearestNinja()
This returns the id of the nearest ninja from the AI.

### getNearestEnemy()
This returns the id of the nearest monster from the AI.

### getDistanceFromPlayer(playerId)
This one takes an id of player and returns the distance between him and the AI.

### move(x, y)
Providing cartesian coordinates, the AI will move in the desired direction. Give (0,0) to stop it.

### getPosition()
Retunrs the 3D position of the AI.

### followPlayer(playerId)
Giving its ID, the AI will follow the desired player.

### followMonster(playerId)
Giving its ID, the AI will follow the desired monster.

### getPlayerPosition(playerId)
Giving its ID, the AI is able to determine a player position

### getPlayerList()
This function will return the players IDs list

### attack()
The AI attacks in front of it
