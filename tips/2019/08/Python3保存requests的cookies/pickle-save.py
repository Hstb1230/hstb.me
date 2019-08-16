import pickle
import requests

s = requests.Session()
s.get('https://aq.qq.com/cn2/index')
print(s.cookies)
# 将cookies写到文件
with open('cookie', 'wb') as f:
    pickle.dump(s.cookies, f)
