import functools
import time

ISOTIMEFORMAT = '%Y-%m-%d %x'

def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator

@log('hello')
def now():
    print(time.strftime(ISOTIMEFORMAT,time.localtime()))

now()
