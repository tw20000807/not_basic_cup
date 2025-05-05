#!/bin/bash

problem="chocolate"
grader_name="grader"
sol1_name="Ame"
sol2_name="Bla"

g++ -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${sol1_name}.cpp" "${sol2_name}.cpp"
