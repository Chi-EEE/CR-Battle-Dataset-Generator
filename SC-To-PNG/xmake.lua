add_rules("mode.debug", "mode.release")
add_requires("libpng")

set_languages("cxx17")

target("SC-To-PNG")
    set_kind("binary")
    add_packages("libpng")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    
    add_includedirs("include", { public = true })

    add_links("SupercellFlash", "SupercellCompression", "SupercellCompression", "LZMA", "LZHAM", "Zstandard")
    add_linkdirs("lib/$(mode)")