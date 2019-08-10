import requests

# 声明一个Session对象
s = requests.Session()
# 声明一个变量存放代理信息
proxies = {
    "http": "http://127.0.0.1:8888/",
    "https": "http://127.0.0.1:8888/"
}
# 有两种使用代理的方法
# [1] 在参数中提交代理信息
s.get('https://httpbin.org/user-agent', proxies=proxies)
# [2] 修改Session对象的属性
s.proxies = proxies
s.get('https://httpbin.org/user-agent')
