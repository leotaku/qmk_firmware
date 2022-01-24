#!/usr/bin/env sh
for line in $@; do
    echo "$line"
done | uniq | tee compile_flags.txt
