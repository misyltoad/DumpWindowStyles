#!/bin/bash

export WINEDEBUG=-all

wine app_dump_styles.exe $@
