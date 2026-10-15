cmake_minimum_required(VERSION 3.16)
project(mpasdesc_analysis_model LANGUAGES C)

# Analysis-team test code: never a clean-room implementation input.
add_library(mpasdesc_model SHARED compatibility.c)
target_compile_features(mpasdesc_model PRIVATE c_std_11)
target_include_directories(mpasdesc_model PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(mpasdesc_model PRIVATE -Wall -Wextra -Werror -Wpedantic)
endif()

# The target is intentionally self-contained. It never compiles src/ pseudocode,
# original binaries, reviewed behavior notes, or clean implementation source.
