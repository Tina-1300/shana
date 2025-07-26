@echo off
setlocal enabledelayedexpansion

echo === Launch all .exe in build\tests ===

for %%f in (build\tests\*.exe) do (
    echo.
    echo --- Execution of %%f ---
    "%%f"
    echo --- End of %%f ---
    echo.
)

echo === All executables have been launched ===

