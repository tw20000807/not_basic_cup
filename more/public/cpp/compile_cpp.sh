#!/bin/bash

problem="more"
grader_name="grader"
sol1_name="remember"
sol2_name="find"

g++ -std=gnu++17 -O2 -Wall -pipe -static -o "${problem}" "${grader_name}.cpp" "${sol1_name}.cpp" "${sol2_name}.cpp"
