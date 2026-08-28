# import requests
# from bs4 import BeautifulSoup
# header={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/151.0.0.0 Safari/537.36 Edg/151.0.0.0"}
# response=requests.get("https://movie.douban.com/top250",headers=header)
# print(response.status_code)
# print(response.text)

# content=requests.get("https://movie.douban.com/top250",headers=header).text
# print(content)
# soup=BeautifulSoup(content,"html.parser")
# print(soup.p)
# print(soup.img)



# import requests
# from bs4 import BeautifulSoup
# content=requests.get("https://books.toscrape.com/").text
# soup=BeautifulSoup(content,"html.parser")
# all_price=soup.find_all("p",attrs={"class":"price_color"})
# for price in all_price:
#     print(price.string[2:])


# import requests
# from bs4 import BeautifulSoup
# header={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/151.0.0.0 Safari/537.36 Edg/151.0.0.0"}
# content=requests.get("https://movie.douban.com/top250",headers=header).text
# soup=BeautifulSoup(content,"html.parser")
# all_title=soup.find_all("span",attrs={"class":"title"})
# for title in all_title:
#     title_string=title.string
#     if "/" not in title_string:
#         print(title.string)



# import requests
# from bs4 import BeautifulSoup
# header={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/151.0.0.0 Safari/537.36 Edg/151.0.0.0"}
# for start_num in range(0,250,25):
#     content=requests.get(f"https://movie.douban.com/top250?start={start_num}",headers=header).text
#     soup=BeautifulSoup(content,"html.parser")
#     all_title=soup.find_all("span",attrs={"class":"title"})
#     for title in all_title:
#         title_string=title.string
#         if "/" not in title_string:
#             print(title_string)


# import requests
# from bs4 import BeautifulSoup

# header = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/151.0.0.0 Safari/537.36 Edg/151.0.0.0"}
# content=requests.get("https://books.toscrape.com/",headers=header).text
# soup=BeautifulSoup(content,"html.parser")
# all_title=soup.find_all("i",attrs={"class":"star-rating Five"})
# for title in all_title:
#     print(title.string)


import requests
from bs4 import BeautifulSoup

headers = {"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/151.0.0.0 Safari/537.36 Edg/151.0.0.0"}
content = requests.get("https://books.toscrape.com/", headers=headers).text
soup = BeautifulSoup(content, "html.parser")

# 1. 找到所有包含评级信息的 <p> 标签
all_ratings = soup.find_all("p", attrs={"class": "star-rating"})

for rating in all_ratings:
    # 2. 获取 class 属性，它是一个列表，例如 ['star-rating', 'Three']
    class_list = rating.get("class")
    
    # 3. 评级是列表中的第二个元素
    rating_value = class_list[1]
    
    print(rating_value)