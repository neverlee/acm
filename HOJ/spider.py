
#!/usr/bin/env python
#coding=utf-8
import urllib
import http.cookiejar
import re
import time

cookie = http.cookiejar.CookieJar()
cjhdr  = urllib.request.HTTPCookieProcessor(cookie)
opener = urllib.request.build_opener(cjhdr)

postdata = {'userid': 'listarmb', 'password': 'dt********', 'submit':''}
params = urllib.parse.urlencode(postdata).encode("utf8")
opener.open("http://acm.hnu.cn/online/?action=user&type=login",params).read()

patsid = re.compile("action=solution&id=(\d+)")
patpid = re.compile("action=problem&type=show&id=(\d+)")
# startno 每次加20
startno = 20
postdata = {'userid': 'listarmb', 'judgeresult':"0", 'courseid':"0", 'rank':"no", 'startno':0, 'submit':''}
while True:
    postdata['startno'] = startno

    params = urllib.parse.urlencode(postdata).encode("utf8")
    astatus = opener.open("http://acm.hnu.cn/online/?action=status", params)
    print("getstatus at", startno)
    stdata = str(astatus.read())
    sids = patsid.findall(stdata)
    pids = patpid.findall(stdata)
    if (not sids) or len(sids) == 0:
        break
    print("get sids len", len(sids))

    time.sleep(10)

    for i in range(0, len(sids)):
        asid = sids[i]
        apid = pids[i]
        with open("save/" + asid, "w") as fout:
            acode = opener.open("http://acm.hnu.cn/online/?action=solution&id=" + asid)
            fout.write(str(acode.read()))
        print("get a code file", apid, asid)
        time.sleep(10)
    time.sleep(10)

    startno = startno + 20


# 需要替换最后的ID
#with open("code", "w") as fout:
#    acode = opener.open("http://acm.hnu.cn/online/?action=solution&id=448696")
#    fout.write(str(acode.read()))

