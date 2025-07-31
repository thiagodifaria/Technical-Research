# Parar o script se qualquer comando falhar
$ErrorActionPreference = "Stop"

# --- Limpeza ---
Write-Host "--- Limpando o diretorio de build anterior ---" -ForegroundColor Yellow
if (Test-Path -Path "build") {
    Remove-Item -Recurse -Force "build"
}

# --- Configuração (Generate) ---
Write-Host "--- Configurando o projeto C++ com CMake ---" -ForegroundColor Cyan
# Cria o diretório de build
New-Item -ItemType Directory -Force -Path "build" | Out-Null
# Gera os arquivos de projeto do Visual Studio
cmake -S . -B build

# --- Compilação (Build) ---
Write-Host "--- Compilando os testes C++ ---" -ForegroundColor Green
# Compila o projeto na configuração Release. Isso irá gerar o run_tests.exe
cmake --build build --config Release

# --- Execução dos Testes ---
Write-Host "--- Executando os testes C++ diretamente ---" -ForegroundColor Magenta
# Em vez de usar ctest, executamos o programa de teste compilado diretamente.
# O '&' é o operador de chamada do PowerShell, necessário para executar o .exe.
& ./build/Release/run_tests.exe

Write-Host "--- Processo de teste C++ concluido com sucesso! ---" -ForegroundColor Green