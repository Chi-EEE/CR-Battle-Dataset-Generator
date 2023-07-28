add_rules("mode.debug", "mode.release")
set_runtimes("MDd")
add_requires("libpng")

set_languages("cxx17")

target("SC-To-PNG")
    set_kind("binary")

    add_packages("libpng")
    add_headerfiles("src/**.h")
    add_files("src/**.cpp")
    
    add_includedirs("include", { public = true })
    
    add_ldflags("/ignore:4099")

    add_linkdirs("lib/$(mode)")

    add_links(
        "ASTC",
        "ETCPACK",
        "LZHAM", 
        "LZMA", 
        "SupercellFlash", 
        "SupercellCompression", 
        "SupercellTextureLoader", 
        "Zstandard"
        )
