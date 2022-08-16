#!/bin/bash

x86_64-w64-mingw32-gcc main.c -Wall -Wextra -Wpedantic -o app_dump_styles -static -static-libgcc
