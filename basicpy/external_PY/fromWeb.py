import requests
from bs4 import BeautifulSoup
def scrap_webpage(url):
  response=requests.get(url)
  if  response.status_code==200:
    soup=BeautifulSoup(response.content,"html.parser")
    return soup
  else:
    print(f"failed to retireve the web page status code{response.status_code}")
    return None
def extract_data(soup):
  heading=soup.find_all(['h1','h2','h3'])
  for x in heading:
    print(x.get_text(strip=True))
url="https://www.rit.ac.in/"
soup=scrap_webpage(url)
if soup:
  extract_data(soup)
else:
  print("error")
