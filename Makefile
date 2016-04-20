
xb-prettifier := $(shell command -v xcpretty >/dev/null 2>&1 && echo "xcpretty -c" || echo "cat")
valgrind-exe := $(shell command -v valgrind)

all: ios

clean:  lib2048.gyp third_party/gtest.gyp
	rm -rf generated-src/*
	rm -rf build/*
	./third_party/gyp/tools/pretty_gyp.py lib2048.gyp > lib_tmp && mv lib_tmp lib2048.gyp
	./third_party/gyp/tools/pretty_gyp.py third_party/gtest.gyp > gtest_tmp && mv gtest_tmp third_party/gtest.gyp


third_party/gyp/:
	cd third_party/gyp/ && git checkout  -q 0bb67471bca068996e15b56738fa4824dfa19de0

djinni: ./third_party/djinni/src/ third_party/gyp/
	./third_party/djinni/src/run \
		--idl ./djinni/twenty_forty_eight.djinni \
		--cpp-out ./generated-src/cpp \
		--cpp-namespace twentyfortyeight::cpp \
		--ident-cpp-method FooBar \
		--ident-cpp-enum FooBar \
		--cpp-enum-hash-workaround false \
		--java-out ./generated-src/java \
		--java-package com.boloutaredoubeni.twentyfortyeight.djinni \
		--jni-out ./generated-src/jni \
		--jni-namespace twentyfortyeight::jni \
		--objc-out ./generated-src/objc \
		--objc-type-prefix TFE \
		--objcpp-out ./generated-src/objcpp \
		--objcpp-namespace twentyfortyeight::objc


lib2048.xcodeproj: third_party/gyp/ djinni
	 ./third_party/gyp/gyp --depth=. -DOS=mac -f xcode \
		--generator-output=./build/mac/ -I./third_party/djinni/common.gypi lib2048.gyp

test: test-cpp

test-cpp: lib2048.xcodeproj
	xcodebuild -project build/mac/lib2048.xcodeproj/ -configuration Debug -target "test" | ${xb-prettifier} \
		&& ${valgrind-exe} ./build/Debug/test


ios.xcodeproj: djinni
	./third_party/gyp/gyp --depth=. -DOS=ios -f xcode \
		--generator-output=./build/ios/ -I./third_party/djinni/common.gypi lib2048.gyp


ios: ios.xcodeproj
	xcodebuild -project build/ios/lib2048.xcodeproj/ -configuration Debug -target lib2048_ios | ${xb-prettifier}


android: gyp_android

gyp_android: djinni
	PYTHONPATH=third_party/gyp/pylib ANDROID_BUILD_TOP=$(shell dirname `which ndk-build`) ./third_party/gyp/gyp --depth=. -f android 	-DOS=android -I./third_party/djinni/common.gypi lib2048.gyp --root-target=lib2048_jni


.PHONY: djinni gyp test clean ios android
