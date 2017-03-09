with open('readme.txt', 'r') as f:
    for line in f.readlines():
        print(line.strip())

with open('test.jpg','rb') as f:
    a = f.read()
    print(a)

with open('test.txt', 'w') as f:
    f.write('Hello, world!')

with open('copy_of_test.jpg','wb') as f:
    f.write(a)