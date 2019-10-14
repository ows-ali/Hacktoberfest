#!/bin/python

import math
import os
import random
import re
import sys


n = int(raw_input().strip())
if (n in range (6, 21) or n % 2 != 0):
        print("Weird")
else: 
    print("Not Weird")