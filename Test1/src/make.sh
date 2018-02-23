#!/bin/sh

APP_ROOT=$(dirname %1)

## Compile Java code
javac -cp .:com/amgTest1/*.java:com/amgSort/*.java:../lib/*.jar \
 $APP_ROOT/com/amgTest1/*.java \
 $APP_ROOT/com/amgSort/*.java \
 $APP_ROOT/com/amgCommon/*.java

## Create Manifest file
echo "Main-Class: com.amgTest1.Main\n"  > $APP_ROOT/Manifest.txt

## Create Jar file
jar cvfm \
	$APP_ROOT/../bin/AMGTest1.jar \
	$APP_ROOT/Manifest.txt \
	$APP_ROOT/com/amgTest1/*.class \
    $APP_ROOT/com/amgSort/*.class \
	$APP_ROOT/com/amgCommon/*.class
