#!/bin/bash

problem="ShortAgain"
memory=524288 # 256MB
stack_size=2097152  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
