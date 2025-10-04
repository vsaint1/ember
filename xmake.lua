set_project("c_particles")
set_languages("c99")
set_license("MIT")
set_version("0.0.1", {build = "%Y%m%d%H%M"})

add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_rules("mode.debug", "mode.release")

add_requires("libsdl3 3.2.22", {configs = {shared = false}})

target("glad")
    set_kind("static")
    add_files("vendor/glad/src/glad.c")
    add_includedirs("vendor/glad/include", {public = true})

target("psystem")
    set_kind("binary")
    
    add_files("src/main.c","src/*.c")

    add_deps("glad")

    add_packages("libsdl3", {public = true})

    if is_plat("windows") then
    end

    if not is_plat("windows")  then
        add_cflags("-fPIC")
    end

    if is_plat("wasm") then
        
       set_basename("index")

       add_ldflags(
           "-s FULL_ES3=1",
           "-s MIN_WEBGL_VERSION=2",
           "-s MAX_WEBGL_VERSION=2",
           "-s ASSERTIONS=1",
           "-s FETCH=1",
           "-s USE_SDL=3",
           "-s ALLOW_MEMORY_GROWTH=1 ",
           "-s EXPORTED_RUNTIME_METHODS=cwrap",
           "-s STACK_SIZE=1mb",
           "--preload-file=res@/res",
           "-g")

    end

    if not is_plat("wasm") then
        after_build(function (target)
            os.cp("res", path.join(target:targetdir(), "res"))
        end)
    end



for _, file in ipairs(os.files("tests/test_*.c")) do
    local name = path.basename(file)
    target(name)
        set_kind("binary")
        set_default(false)
        add_files(file)
        add_tests(name)
        add_includedirs("src/")
        add_files("src/*.c")
        remove_files("src/main.c")
        add_packages("libsdl3")
        
end

if not is_plat("windows")  then
    add_cflags("-fPIC")
end