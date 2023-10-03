add_rules("mode.debug", "mode.release")

add_repositories("repository repository", {rootdir = os.scriptdir()})

add_requires("skia")
add_requires("cpptrace", "fmt", "tl_expected", "spdlog")
add_requires("json-schema-validator-", { alias = "json-schema-validator" })
add_requires("toml++")
add_requires("csvparser")

set_languages("cxx17")

target("CR-Battle-Dataset-Generator")
    set_kind("binary")

    add_packages("skia")
    add_packages("cpptrace", "fmt", "tl_expected", "spdlog")
    add_packages("json-schema-validator", "toml++", "csvparser")
   
    add_files("src/**.cpp")
    add_headerfiles("src/**.h", "src/**.hpp")
    