
project(nstl)
cmake_minimum_required(VERSION 2.6)

file(
    GLOB_RECURSE
    editable_files
    "src/*.[c,h]" "include/*.[c,h]" "test/*.[c,h]"
)
set(cog "tools/cog/scripts/cog.py")
set(macroize "tools/macroize/macroize.py")
set(cog_fix_pypath export "PYTHONPATH=${PYTHONPATH}:tools/cog")
set(cog_flags "-Itools/")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-function -Wno-unused-parameter -std=c89 -pedantic")


add_custom_target(
    before-edit
    COMMAND ${cog_fix_pypath} && python ${cog} ${cog_flags} -x -r ${editable_files}
    COMMAND python ${macroize} ${editable_files} -u
    WORKING_DIRECTORY "${nstl_SOURCE_DIR}"
)

add_custom_target(
    after-edit
    COMMAND python ${macroize} ${editable_files}
    COMMAND ${cog_fix_pypath} && python ${cog} ${cog_flags} -r ${editable_files}
    WORKING_DIRECTORY "${nstl_SOURCE_DIR}"
)

include_directories("ext/chaos-pp" "ext/joy/include")
add_subdirectory(test)
