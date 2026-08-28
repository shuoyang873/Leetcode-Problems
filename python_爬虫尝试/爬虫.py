print("hello world\'\"")
num = 10
print ("num="+str(num))
print(2**3)

# import math
# print(math.sin(1))


s="abcdefg"
print(s[3])
print("abcdefg"[3])

#空值变量None   变量不知道要设什么值的时候，可以先设为none
n=None


#不确定某个对象类型的时候，可以用type，可以直接返回数据的类型
print(type(n))

#len函数可以知道字符串长度

print(len("abcdefg"))

#布尔类型都需要大写开头
ans1=True
ans2=False


#input是输入，而且输入的一律当成字符串
user_ID=input("请输入你的ID：")
print(user_ID)


user_age=int(input("请输入你的年龄："))       #强制将输入转换成int类型，方便进行加减
print(user_age+10)

#
import requests
response=requests.get("http://books.toscrape.com/")
print(response)
print(response.status_code)      #这边是输出网址的状态码，200表示能够找到对应的资源
#状态码在200-400之间，是相应成功； 在400-500之间是客户端错误； 在500以上是服务器错误


#可以用requests.ok判断访问网址是否成功
if response.ok:
    print(response.status_code)
else:
    print("错误")