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

set arr[0].file=run_bubble_sort.bat
set arr[1].file=run_obuchaika.bat
set arr[2].file=run_prefix_sum.bat
set arr[3].file=run_zachet.bat

set arr[0].folder=SmartSort
set arr[1].folder=obuchaiika
set arr[2].folder=prefix_sum
set arr[3].folder=zachet

for /L %%i in (0,1,5) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .