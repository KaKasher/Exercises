import requests
import time
from bs4 import BeautifulSoup

while True:

    r = requests.get('https://www.amazon.de/PlayStation-Zertifiziert-Generalüberholt-DualShock-Controller/dp/B07DLJRYL7/ref=as_li_ss_tl')
    soup = BeautifulSoup(r.content, 'lxml')

    print(soup.find('span', {'class': 'a-size-medium a-color-price'}).text.strip())

    time.sleep(10)