#!/bin/sh
bindir=$(pwd)
cd /Users/georgi/Documents/workspace/framework/source/demo/
export DYLD_LIBRARY_PATH=:$DYLD_LIBRARY_PATH

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		 -batch -command=$bindir/gdbscript  /Users/georgi/Documents/workspace/framework/build/MinSizeRel/demo 
	else
		"/Users/georgi/Documents/workspace/framework/build/MinSizeRel/demo"  
	fi
else
	"/Users/georgi/Documents/workspace/framework/build/MinSizeRel/demo"  
fi
