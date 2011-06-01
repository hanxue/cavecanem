#!/bin/bash

if [ -f ./main/cavecanem ]
then
    export LD_LIBRARY_PATH=$PWD/shared/hyperic_sigar-1.6.4/lib:$LD_LIBRARY_PATH	
    cd main
    ./cavecanem $*
else
    echo "***************************************************************"
    echo Cave Canem executable does not exist in:
    echo $PWD/main 
    echo ""
    echo Please, try to recompile the application using the command:
    echo " $ make arch_name."
    echo "***************************************************************"
fi

