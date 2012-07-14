
project(nstl)
cmake_minimum_required(VERSION 2.6)


file(
    GLOB_RECURSE
    editable_files
    src/*.[c,h] include/*.[c,h] test/*.[c,h]
)
set(cog_fix_pypath export PYTHONPATH=${PYTHONPATH}:tools/cog)
set(cog ${cog_fix_pypath} && python tools/cog/scripts/cog.py)
set(macroize ${cog_fix_pypath} && python tools/macroize/macroize.py)
set(cog_flags -I ${nstl_SOURCE_DIR}/tools/)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-unused-function -std=c89 -pedantic")

# Clean up the source files from generated boilerplate to facilitate editing.
add_custom_target(
    before-edit
    DEPENDS ${editable_files}
    COMMAND ${cog} ${cog_flags} -x -r ${editable_files}
    COMMAND ${macroize} ${editable_files} -u
    WORKING_DIRECTORY ${nstl_SOURCE_DIR}
)

# Run Cog and ``macroize'' on the source files to regenerate boilerplate.
add_custom_target(
    after-edit
    DEPENDS ${editable_files}
    COMMAND ${macroize} ${editable_files}
    COMMAND ${cog} ${cog_flags} -r ${editable_files}
    WORKING_DIRECTORY ${nstl_SOURCE_DIR}
)

# Generate the instantiation of primitive types.
add_custom_target(
    primitive
    COMMAND ${CMAKE_C_COMPILER} -Wall -Wextra -std=c89 -pedantic
            -I ${nstl_SOURCE_DIR}/include
            -I ${nstl_SOURCE_DIR}/ext/chaos-pp
            -I ${nstl_SOURCE_DIR}/ext/joy/include
            -E -P -D NSTL_I_INSTANTIATE_PRIMITIVE
            -o ${nstl_SOURCE_DIR}/include/nstl/internal/primitive.i
            ${nstl_SOURCE_DIR}/include/nstl/internal/primitive.h
    COMMAND python ${nstl_SOURCE_DIR}/tools/replace_primitive.py
                   ${nstl_SOURCE_DIR}/include/nstl/internal/primitive.i

    DEPENDS ${nstl_SOURCE_DIR}/include/nstl/internal/primitive.h
    WORKING_DIRECTORY ${nstl_SOURCE_DIR}
)


include_directories(${nstl_SOURCE_DIR}/ext/chaos-pp
                    ${nstl_SOURCE_DIR}/ext/joy/include)
add_subdirectory(test)
