#!/bin/bash

# Change to the root of the project
cd "$(git rev-parse --show-toplevel)"

# The header of the AUTHORS file
cat > AUTHORS << EOH
# This file lists the two authors that have contributed to this simple shell project.
EOH

# List of all the authors and add them to the file
git log --format='%aN <%aE>' | sort -uf >> AUTHORS
