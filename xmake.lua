add_rules("mode.debug", "mode.release")
add_requires("skia")
add_requires("fmt", "tl_expected", "nlohmann_json")

set_languages("cxx17")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")
    add_packages("skia")
    add_packages("fmt", "tl_expected", "nlohmann_json")
   
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")

    set_configdir("$(buildir)/$(plat)/$(arch)/$(mode)/config")
    add_configfiles("config/**", {onlycopy = true})
