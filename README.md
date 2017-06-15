# ![LBCLAB](https://lbclab.com/gauntlet/assets/logo.png) Ninja Gauntlet - The AI development kit

This repository contains the artificial intelligence development kit provided with the LbcLab video game [_Ninja Gauntlet_](https://lbclab.com/gauntlet/)
This allows the developper to program its own artificial intelligeance thanks to a LUA binding that is implemented in Ninja Gauntlet.

By developping Lua scripts, the gamer would be able to control AI in-game behaviour.
To help him in his quest, LbcLab released this development kit that embeed a minimal version of the Ninja Gauntlet binding.
You could such run lua scripts, interact and modify the AI class but also debug the hole thing by debug functions and messages that
have been placed in this developper kit.
<p align="center">
<a href="https://github.com/LbcLab/indie_studio_ai_dev_kit/blob/master/FEATURES.md">Discover the available features</a>
</p>

## Getting Started

These instructions will get you a copy of the project up and running on your local machine.

### Prerequisites

What things you need to install the software and how to install them. First, make sure you've got the lua lib installed.
Then, clone the repository and run the example script given the following instructions :

```
git clone git@github.com:LbcLab/indie_studio_ai_dev_kit
cd indie_studio_ai_dev_kit
make
./test_ai lua/ia.lua
```

### Example

This is the result of the example script located in _lua/ia.lua_ :
```
AI name : my_name
AI created.
ping() was called with 3 arguments:
        arg [1]:        [test]
        arg [2]:        [23]
        arg [3]:        [banane]
Call : getlife()
getLife() returned: 100.0
AI destroyed.
```
The example script defines some global variables and functions thay may be interpreted by the AI class.
This is actually the example script :
```
name="my_name"
class="thief"

function loop()
  local ping = ping("test", 23, "banane");
  local life = getLife();
  io.write(string.format("getLife() returned: %s\n", tostring(life)))
end

function my_lua_func(arg)
  print("im my_lua_func")
  io.write(string.format("my_lua_func arg: %s\n", tostring(arg)))
end
```
You may notice that *name* is the only global variable has been interpreted. Actually, it's the case on Ninja Gauntlet but
it may be updated in the future, pay attention to the new releases. They would be announced on
the [_official website_](https://lbclab.com/gauntlet/).
You may notice that only _loop()_ has been called. This is the only function that will be called on Ninja Gauntlet.
 
## Documentation

This project has been documented thanks to Doxygen. The _Doxyfile_ configuration is provided.
You can re-generate the documentation using ```doxygen Doxyfile```.

The documentation is generated in three different formats.

### html

```
cd doc/html/
firefox index.html
```

### latex

```
cd doc/latex
make
firefox refman.pdf
```

### mans

```
cd doc/man
???
PROFIT
```
 
## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -avm 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :ok_hand:

 
 ## :neckbeard: Authors
 
 + **Charles Paulet** - *initial work && distribution* - [LbcLab](https://lbclab.com/)
 
 See also the list of [contributors](https://github.com/LbcLab/docIndie/contributors) who participated in this project.
