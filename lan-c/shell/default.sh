#!/bin/sh
#default.sh
#设置变量的默认值

echo linux $version
echo linux ${version:-2.6.12}
echo the value is :$version
version="new version"
echo linux ${version:-2.6.12}
