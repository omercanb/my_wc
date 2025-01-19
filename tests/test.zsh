#!/usr/bin/env zsh

files=("full.txt" "locale.txt" "whitespace.txt")
script_dir="$(dirname "$0")"

for file in ${files[@]}; do
    full_path="$script_dir/$file"

    echo "Testing $full_path"

    if diff <(wc "$full_path" | tr -s ' ') <(my_wc "$full_path" | tr -s ' '); then
        echo "✓ Test passed for $file."
    else
        echo "✗ Test failed for $file."
    fi

    echo ""
done