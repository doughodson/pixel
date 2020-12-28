#
# remove any generated build files
#
rm -rf ..\gmake
rm -rf ..\obj
#
# create new build files files
#
./premake5-alpha15 --os=linux --file=premake5.lua gmake

