#!/bin/bash

# Check if an argument is provided and is a positive integer
if ! [[ $1 =~ ^[0-9]+$ ]] || [ "$1" -le 0 ]; then
    echo "Please provide a positive integer as an argument."
    exit 1
fi

# Use the provided argument for the number of random numbers to generate
count=$1

numbers=()  # Array to store the generated random numbers

while [ ${#numbers[@]} -lt $count ]; do
    rand=$RANDOM  # Generate a random number
    if ! [[ " ${numbers[@]} " =~ " ${rand} " ]]; then  # If the number hasn't been generated before
        numbers+=($rand)  # Add the number to the array
    fi
done

echo "${numbers[*]}"

