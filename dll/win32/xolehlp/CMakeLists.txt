
spec2def(xolehlp.dll xolehlp.spec)

list(APPEND SOURCE
    xolehlp.c
    ${CMAKE_CURRENT_BINARY_DIR}/xolehlp_stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/xolehlp.def)

add_library(xolehlp MODULE ${SOURCE})
set_module_type(xolehlp win32dll)
target_link_libraries(xolehlp adsiid uuid wine)
add_importlibs(xolehlp msvcrt kernel32 ntdll)
add_cd_file(TARGET xolehlp DESTINATION reactos/system32 FOR all)
set_wine_module_FIXME(xolehlp) # CORE-5743: No ARRAY_SIZE and CONST_VTABLE
