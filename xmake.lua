add_rules("mode.debug", "mode.release")
add_requires("skia", "opencv")
add_requires("cpptrace", "fmt", "tl_expected", "spdlog")
add_requires("nlohmann_json", "toml++")

set_languages("cxx17")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")

    add_packages("skia", "opencv")
    add_packages("cpptrace", "fmt", "tl_expected", "spdlog")
    add_packages("nlohmann_json", "toml++")
   
    add_files("src/**.cpp")
    add_headerfiles("src/**.h", "src/**.hpp")
    