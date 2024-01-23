arg_lines=(
    "000000_10 000000_10 2"
    "000000_10 000000_10_2 2"
    "000000_10 000000_10_4 2"
    "000000_10 000000_10_8 2"
)

for arg_line in "${arg_lines[@]}"; do
    echo run: $arg_line;
    args=($arg_line)
    ./main answer/${args[0]}.png result/${args[1]}.png ${args[2]}
done

