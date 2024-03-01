@echo off
setlocal EnableDelayedExpansion

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

copy ..\%SOURCE_FOLDER%\SmartSort\run_bubble_sort.bat .\SmartSort
copy ..\%SOURCE_FOLDER%\obuchaiika\run_obuchaika.bat .\obuchaiika
copy ..\%SOURCE_FOLDER%\prefix_sum\run_prefix_sum.bat .\prefix_sum
copy ..\%SOURCE_FOLDER%\zachet\run_zachet.bat .\zachet

copy ..\run_tests.bat .