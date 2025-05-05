@echo off

set problem=chocolate
set grader_name=grader
set sol1_name=Ame
set sol2_name=Bla

g++ -std=gnu++17 -O2 -pipe -o "%problem%" "%grader_name%.cpp" "%sol1_name%.cpp" "%sol2_name%.cpp"
