
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(clang-tidy LANGUAGES CXX)

set(CMAKE_CXX_COMPILER clang++)

# set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy-11;
#   -format-style='file';
#   -header-filter=${CMAKE_CURRENT_SOURCE_DIR};
# )


# set(CLANG_TIDY_COMMAND clang-tidy;
#             -header-filter=^.*;
#             -config-file=${PROJECT_ROOT_DIR}/.clang-tidy;)

# set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_COMMAND})

add_executable(05_unique_lock 05_unique_lock.cc)
