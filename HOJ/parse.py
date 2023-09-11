

from bs4 import BeautifulSoup
import os
import re

pbmap = {}
lgmap = {}
jrmap = {}

root = "commit/"
for fname in os.listdir():
    fpath = root + fname
    with open(fpath) as f:
        fdata = f.read()
        soup = BeautifulSoup(fdata, "html.parser")

        pblb = soup.find(name="b", string=re.compile('Problem :', re.S))
        pbid = pblb.next_sibling

        lglb = soup.find(name="b", string=re.compile('Language :', re.S))
        lgname = lglb.next_sibling.string.split('\\')[0]

        jrlb = soup.find(name="b", string=re.compile('Judge Result:', re.S))
        jr = jrlb.next_sibling.string

        sclb = soup.find(name="b", string=re.compile('Source Code', re.S))
        sc = str(sclb.parent.parent.next_sibling.next_sibling.pre.string).replace("\xa0", " ").replace("\\r", "").encode("utf8").decode('unicode_escape')

        print(fpath, pbid, lgname, jr)
        # print(sc)
        pbmap[pbid] = pbmap.get(pbid, 0) + 1
        lgmap[lgname] = lgmap.get(lgname, 0) + 1
        jrmap[jr] = jrmap.get(jr, 0) + 1


print(lgmap)
print(jrmap)
print(len(pbmap))

