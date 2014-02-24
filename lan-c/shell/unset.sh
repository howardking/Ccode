#!/bin/sh
#unset.h
#清除变量的值

echo "Before clearance"

str="Hello World"
echo $str

echo "After clearance"

#unset $str
unset str
echo $str
