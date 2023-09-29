add_rules("mode.debug", "mode.release")

add_repositories("my-repo repository")

add_requires("skia", "opencv")
add_requires("cpptrace", "fmt", "tl_expected", "spdlog")
add_requires("json-schema-validatora", "toml++")

set_languages("cxx17")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")

    add_packages("skia", "opencv")
    add_packages("cpptrace", "fmt", "tl_expected", "spdlog")
    add_packages("json-schema-validatora", "toml++")
   
    add_files("src/**.cpp")
    add_headerfiles("src/**.h", "src/**.hpp")
    