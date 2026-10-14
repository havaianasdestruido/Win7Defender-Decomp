cmake_minimum_required(VERSION 3.16)
project(mpasdesc_behavior_model LANGUAGES C)
add_library(mpasdesc_model SHARED compatibility.c)
target_compile_features(mpasdesc_model PRIVATE c_std_11)
target_include_directories(mpasdesc_model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(mpasdesc_model PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()
# Deliberately excludes pseudocode.c: unverified decompiler output is not buildable source.
# No Windows DLL/COM compatibility is implied by this portable test target.
