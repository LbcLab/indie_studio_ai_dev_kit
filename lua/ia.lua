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
