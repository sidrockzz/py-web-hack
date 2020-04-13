#!/bin/bash

for file in *.py; do
  name=$(basename "$file" .py)
  echo mv "$file" "$name.py"
done
