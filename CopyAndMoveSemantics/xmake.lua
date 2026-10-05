add_rules("mode.debug", "mode.release")

target("CopyAndMoveSemantics")
    set_kind("binary")
    add_files("src/*.cpp")
    
