import requests

# 声明一个Session对象
s = requests.Session()
# 修改代理信息
s.proxies = {
    "http": "http://127.0.0.1:8888/",
    "https": "http://127.0.0.1:8888/"
}
# 设置自定义证书
# # 假设证书在代码目录下的cert文件夹里，文件名为FiddlerRoot.pem
# # 直接使用相对路径
s.verify = r'cert\FiddlerRoot.pem'
# # 如果使用了c_rehash.pl对cert文件夹做了处理，可以修改为如下一行代码
s.verify = r'cert'
print(s.get('https://httpbin.org/user-agent').text)
