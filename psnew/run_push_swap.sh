#!/bin/bash

# Check if an argument is provided and is a positive integer
if ! [[ $1 =~ ^[0-9]+$ ]] || [ "$1" -le 0 ]; then
    echo "Usage: $0 [positive integer]"
    echo "Please provide a positive integer as an argument for the number of random numbers to generate."
    exit 1
fi

# Use the provided argument for the number of random numbers to generate
count=$1

# Generate the numbers and store them in a variable
numbers=$(./generate_numbers.sh $count)

# Run push_swap with the generated numbers and store the output (operations)
operations=$(./push_swap $numbers)

# Print all operations
echo "Operations:"
echo "$operations"

# Count the number of operations and print the total
echo "Total number of operations:"
echo "$operations" | wc -l
