add_rules("mode.debug", "mode.release")
add_requires("skia")
add_requires("tl_expected")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")
    add_rules("utils.bin2c", {extensions = {".json"}})
    add_packages("skia")
    add_packages("tl_expected")
    if is_mode("debug") then 
        set_targetdir("$(buildir)/debug/$(os)/$(arch)")
        set_configdir("$(buildir)/debug/$(os)/$(arch)/res")
    else 
        set_targetdir("$(buildir)/release/$(os)/$(arch)")
        set_configdir("$(buildir)/release/$(os)/$(arch)/res")
    end
    add_files("src/*.cpp")
    add_headerfiles("src/*.h")
    add_files("src/*/*.cpp")
    add_headerfiles("src/*/*.h")
    -- add_files("res/TowerPosition/*.json")
    add_configfiles("res/config.json")

--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro defination
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

