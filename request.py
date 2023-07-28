from requests import get
from sys import argv
file=open("result.txt",'w')
file.write(get(argv[1]).text)
