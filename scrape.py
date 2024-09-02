
import requests
import sys

from bs4 import BeautifulSoup

#send requests

def scrape(url):

    url = "https://" + url
    #get response of the url request
    response = requests.get(url)

    #parse HTML content
    soup = BeautifulSoup(response.content,"html.parser")

    #Extract text
    text = soup.get_text()
    print(text)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        url = sys.argv[1]
        scrape(url)
    else:
        print("No URL provided")
