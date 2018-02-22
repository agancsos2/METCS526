#!/bin/sh

APP_ROOT=$(dirname %1)

## Compile Java code
javac -cp .:com/amgTimer/*.java:../lib/*.jar $APP_ROOT/com/amgTimer/*.java 

## Create Manifest file
echo "Main-Class: com.amgTimer.Main\n"  > $APP_ROOT/Manifest.txt

## Create Jar file
jar cvfm \
	$APP_ROOT/../bin/TimerTest.jar \
	$APP_ROOT/Manifest.txt \
	$APP_ROOT/com/amgTimer/*.class \
