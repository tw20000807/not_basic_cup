#!/bin/bash

problem="short"
memory=524288  # 256MB
stack_size=262144  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
