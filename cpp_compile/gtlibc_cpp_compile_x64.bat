@echo off
set arg1=%1
set cpp_file=%arg1%
set exe_file=%cpp_file:.cpp=.exe%

g++ -m64 -w -o %exe_file% %cpp_file% -fpermissive

