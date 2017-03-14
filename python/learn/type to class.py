class Hello1(object):
    def hello1(self, name = 'world'):
        print('Hello, %s.'%name)
    def __str__(self):
        return 'Hello Class'
    __repr__ = __str__

h = Hello1()

def fn(self, name = 'world'):
    print('Hello, %s.'%name)
Hello2 = type('Hello2', (object,), dict(hello2 = fn))

h2 = Hello2()

print(h)
print(type(h))
print(h2)
print(type(h2))
