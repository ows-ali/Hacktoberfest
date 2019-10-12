def split_and_join(line):
    # write your code here
    segments = line.split(' ')
    linkedString = "-".join(segments)
    return linkedString
    
if __name__ == '__main__':
    line = raw_input()
    result = split_and_join(line)
    print result