import requests

# 声明一个Session对象
s = requests.Session()
# 使用该对象的get方法请求网站
r = s.get('https://httpbin.org/user-agent')
print(r.text)
