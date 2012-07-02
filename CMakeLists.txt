
project(nstl)
cmake_minimum_required(VERSION 2.6)

file(
    GLOB_RECURSE
    editable_files
    "src/*.[c,h]" "include/*.[c,h]" "test/*.[c,h]"
)
set(cog "tools/cog/scripts/cog.py")
set(macroize "tools/macroize/macroize.py")
set(cog_flags "-Itools/")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")


add_custom_target(
    before_edit
    COMMAND python3 ${cog} ${cog_flags} -x -r ${editable_files}
    COMMAND python3 ${macroize} ${editable_files} -u
    WORKING_DIRECTORY "${nstl_SOURCE_DIR}"
)

add_custom_target(
    after_edit
    COMMAND python3 ${macroize} ${editable_files}
    COMMAND python3 ${cog} ${cog_flags} -r ${editable_files}
    WORKING_DIRECTORY "${nstl_SOURCE_DIR}"
)

include_directories("ext/chaos-pp" "../joy/include")
add_subdirectory(test)
