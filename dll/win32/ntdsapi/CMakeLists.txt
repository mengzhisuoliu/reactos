
spec2def(ntdsapi.dll ntdsapi.spec ADD_IMPORTLIB)

list(APPEND SOURCE
    ntdsapi.c
    ${CMAKE_CURRENT_BINARY_DIR}/ntdsapi_stubs.c
    ${CMAKE_CURRENT_BINARY_DIR}/ntdsapi.def)

add_library(ntdsapi MODULE ${SOURCE})
set_module_type(ntdsapi win32dll)
target_link_libraries(ntdsapi wine)
add_importlibs(ntdsapi user32 msvcrt kernel32 ntdll)
add_cd_file(TARGET ntdsapi DESTINATION reactos/system32 FOR all)
set_wine_module(ntdsapi)
