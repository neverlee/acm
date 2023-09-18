import re
import html
import os

def getdata(fname):
    fin = open(fname)
    data = fin.read()
    fin.close()
    return str(data)

patpid = re.compile("Problem : </b>(\d+)")
patlang = re.compile("Language : </b>([\w\s\+]+)")
patcode = re.compile("<pre>(.*)</pre>")

def getcodepage(data, fid):
    #data = data[5189:-561]
    #data = data[5189:-550]
    #print(data)
    pid = patpid.findall(data)
    if (not pid) or len(pid) < 1:
        print("find problem id error")
    pid = pid[0]
    lang = patlang.findall(data)
    if (not lang) or len(lang) < 1:
        print("find lang error")
    lang = lang[0]
    code = patcode.findall(data)
    if (not code) or len(code) < 1:
        print("find code error")
    print("get:", pid, lang)
    #print(code[0])
    ncode = html.unescape(code[0])
    ncode = ncode.replace("\\r\\n", "\n")
    ncode = ncode.replace("\\\\", "\\")
    #ncode = ncode.replace("\\n", "\n")
    #print(ncode)

    sname = "ncode/" + pid + "-" + fid + "."
    if lang == "GNU C++":
        sname = sname + "cc"
    elif lang == "Java":
        sname = sname + "java"
    else:
        sname = sname + "c"
    print("write:", sname)
    with open(sname, "w") as fout:
        fout.write(ncode)

for fname in os.listdir("save"):
    fpath = "save/" + fname
    print(fpath)
    data = getdata(fpath)
    getcodepage(data, fname)

