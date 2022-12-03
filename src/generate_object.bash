#!/bin/bash

tot=""
for f in *.cc; do
    tot="${tot} ${f:0:-3}.o"
done
echo ${tot}
