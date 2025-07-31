# Versão mínima do CMake
cmake_minimum_required(VERSION 3.15)

# Nome do projeto e padrão C++
project(TechnicalResearch LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Incluir o diretório de headers públicos
include_directories(include)

# Encontrar todos os arquivos fonte na pasta src/
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Criar uma biblioteca estática com todos os algoritmos
add_library(algorithms STATIC ${SOURCES})

# Configurar GoogleTest para os testes
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Encontrar todos os arquivos de teste na pasta tests/
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Criar o executável de teste
add_executable(run_tests ${TEST_SOURCES})

# Vincular a biblioteca de algoritmos e o GoogleTest ao executável de teste.
# A biblioteca gtest_main já fornece a função main() e inicializa o GoogleTest.
target_link_libraries(run_tests PRIVATE algorithms gtest_main)