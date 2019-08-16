import pickle
import requests

s = requests.Session()
# 从文件中读取cookies
with open('cookie', 'rb') as f:
    s.cookies.update(pickle.load(f))
    # s.cookies = pickle.load(f)
s.get('https://aq.qq.com/cn2/index')
print(s.cookies)
