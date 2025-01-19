#!/usr/bin/env zsh

files=("full.txt" "locale.txt" "whitespace.txt")
for file in ${files[@]}; do

    echo "Testing $file"

    if diff <(wc "$file" | tr -s ' ') <(my_wc "$file" | tr -s ' '); then
        echo "✓ Test passed for $file."
    else
        echo "✗ Test failed for $file."
    fi

    echo ""
done