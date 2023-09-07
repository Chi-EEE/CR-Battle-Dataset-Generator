add_rules("mode.debug", "mode.release")
add_requires("skia")
add_requires("cpptrace", "fmt", "tl_expected", "nlohmann_json")

set_languages("cxx17")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")

    add_packages("skia")
    add_packages("cpptrace", "fmt", "tl_expected", "nlohmann_json")
   
    add_files("src/**.cpp")
    add_headerfiles("src/**.h", "src/**.hpp")
    