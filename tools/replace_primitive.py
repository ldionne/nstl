#!/usr/bin/env python

"""Simple script to remove some lines from the file containing the primitive
   types instantiation.
"""

if __name__ == "__main__":
    import re
    from sys import argv

    infile = argv[1]

    DELIMS = "{}+".format("-" * 20)

    with open(infile, 'r') as file:
        input = file.read()

    match = re.search(DELIMS + r"(.*?)" + DELIMS, input, re.DOTALL)

    with open(infile, 'w') as file:
        file.write(match.group(1))
