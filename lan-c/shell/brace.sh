#!/bin/sh
#brace.sh
#用（（））代替expr计算算术运算

sum=$((3 + 2))
echo $sum

mod=$((3 % 2))
echo $mod

mul=$((3 \* 2))
echo $mul

exit 0
