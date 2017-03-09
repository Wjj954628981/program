import requests
from bs4 import BeautifulSoup
from datetime import datetime
import json
import re

def getCommentCounts(newsurl):
    news_id = re.search('doc-i(.+).shtml',url).group(1)
    comment = requests.get(commentURL.format(news_id))
    jd = json.loads(comment.text.strip('var data='))
    return jd['result']['count']['total']

def getComment(newsurl):
    news_id = re.search('doc-i(.+).shtml',url).group(1)
    comment = requests.get(commentURL.format(news_id))
    jd = json.loads(comment.text.strip('var data='))
    if len(jd['result']['hot_list'])>0:
        print('hot comment:',)
        for hot_comment_list in jd['result']['hot_list']:
            print(hot_comment_list['content'])
    if len(jd['result']['cmntlist'])>0:
        print('comment:')
        for comment_list in jd['result']['cmntlist']:
            print(comment_list['content'])

def getNewsDetail(newsurl):
    result = {}
    res = requests.get(newsurl) 
    res.encoding = 'utf-8'
    soup = BeautifulSoup(res.text,'html.parser')
    result['title'] = soup.select('#artibodyTitle')[0].text
    result['time'] = datetime.strptime(soup.select('.time-source')[0].contents[0].strip(),'%Y年%m月%d日%H:%M')
    result['source'] = soup.select('.time-source span')[0].text
    result['article'] = '\n'.join([p.text.strip() for p in soup.select('#artibody p')[:-1]])
    result['editor'] = soup.select('.article-editor')[0].text.lstrip('责任编辑：')
    result['commentcounts'] = getCommentCounts(newsurl)
    return result


def getNewsList():
    result = []
    res = requests.get('http://news.sina.com.cn/china/')
    res.encoding = 'utf-8'
    soup = BeautifulSoup(res.text,'html.parser')
    num = 0;
    for news in soup.select('.news-item'):
        if len(news.select('h2'))>0:
            object = {}
            object['name'] = news.select('h2')[0].text
            object['time'] = news.select('.time')[0].text
            object['link'] = news.select('a')[0]['href']
            result.append(object)
            num = num + 1
    return result

commentURL = 'http://comment5.news.sina.com.cn/page/info?version=1&format=js&channel=gn&\
newsid=comos-{0}&group=&compress=0&ie=utf-8&oe=utf-8&page=1&\
page_size=20'
newslist = getNewsList()
for news in newslist:
    url = news['link']
    print(url)
    result = getNewsDetail(url)
    print(result['title'],result['time'],result['source'],'\n',result['article'],'\n',result['editor'],'\n',result['commentcounts'])
    getComment(url)



